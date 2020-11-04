/****************************************************************************
 Copyright (c) 2014-2016 Chukong Technologies Inc.
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "3d/CCSprite3D.h"
#include "3d/CCObjLoader.h"
#include "3d/CCMeshSkin.h"
#include "3d/CCBundle3D.h"
#include "3d/CCSprite3DMaterial.h"
#include "3d/CCAttachNode.h"
#include "3d/CCMesh.h"

#include "base/CCDirector.h"
#include "base/CCAsyncTaskPool.h"
#include "base/ccUTF8.h"
#include "base/ccUtils.h"
#include "2d/CCLight.h"
#include "2d/CCCamera.h"
#include "base/ccMacros.h"
#include "platform/CCPlatformMacros.h"
#include "platform/CCFileUtils.h"
#include "renderer/CCTextureCache.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCMaterial.h"
#include "renderer/CCTechnique.h"
#include "renderer/CCPass.h"

NS_CC_BEGIN

std::string Sprite3D::g_ReplaceTextureExtension;

std::string Sprite3D::adjustTextureExtension(const std::string &fileName)
{
    if (fileName.empty() || g_ReplaceTextureExtension.empty())
        return fileName;
    
    if (fileName.rfind(g_ReplaceTextureExtension) == fileName.length() - g_ReplaceTextureExtension.length()) {
        return fileName;
    }
    
    std::string newFileName = fileName;
    size_t extPos = fileName.rfind(".");
    if (extPos != std::string::npos)
    {
        newFileName.resize(extPos);
    }
        
    newFileName += g_ReplaceTextureExtension;
    return newFileName;
}

static Sprite3DMaterial* getSprite3DMaterialForAttribs(const MeshVertexData* meshVertexData, bool usesLight, bool alphaTest);

Sprite3D* Sprite3D::create()
{
    //
    auto sprite = new (std::nothrow) Sprite3D();
    if (sprite && sprite->init())
    {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}

Sprite3D* Sprite3D::create(const std::string& modelPath)
{
    CCASSERT(modelPath.length() >= 4, "invalid filename for Sprite3D");
    
    auto sprite = new (std::nothrow) Sprite3D();
    if (sprite && sprite->initWithFile(modelPath))
    {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}
Sprite3D* Sprite3D::create(const std::string& modelPath, const std::string& texturePath)
{
    auto sprite = create(modelPath);
    if (sprite)
    {
        sprite->setTexture(texturePath);
    }
    
    return sprite;
}

void Sprite3D::createAsync(const std::string& modelPath, const AsyncLoadCallback& callback, void* callbackparam)
{
    createAsync(modelPath, std::string(), callback, callbackparam);
}

void Sprite3D::createAsync(const std::string& modelPath, const std::string& texturePath, const AsyncLoadCallback &callback, void* callbackparam)
{
    createAsync(modelPath, std::string(), texturePath, callback, callbackparam);
}

void Sprite3D::createAsyncWithSkeleton(const std::string &modelPath, const std::string &skeletonPath, const std::function<void (Sprite3D *, void *)> &callback,
                                       void *callbackparam)
{
    createAsync(modelPath, skeletonPath, std::string(), callback, callbackparam);
}

void Sprite3D::createAsync(const std::string& modelPath, const std::string &skeletonPath, const std::string& texturePath, const AsyncLoadCallback &callback, void* callbackparam)
{
    Sprite3D *sprite = new (std::nothrow) Sprite3D();
        
    if (sprite->loadFromCache(modelPath, skeletonPath))
    {
        sprite->autorelease();
        if (!texturePath.empty())
            sprite->setTexture(texturePath);
        callback(sprite, callbackparam);
        return;
    }
    
    auto &param = sprite->_asyncLoadParam;
    param.afterLoadCallback = callback;
    param.texPath = texturePath;
    param.skeletonPath = skeletonPath;
    param.modelPath = modelPath;
    param.callbackParam = callbackparam;
    param.modelData.reset(new (std::nothrow) Sprite3DCache::Sprite3DData);
    
    if (!skeletonPath.empty() && skeletonPath != modelPath && !Sprite3DCache::getInstance()->getSpriteData(skeletonPath))
    {
        param.skeletonData.reset(new (std::nothrow) Sprite3DCache::Sprite3DData);
    } 
    
    AsyncTaskPool::getInstance()->enqueue(AsyncTaskPool::TaskType::TASK_IO, CC_CALLBACK_1(Sprite3D::afterAsyncLoad, sprite), (void*)(&sprite->_asyncLoadParam), [sprite]()
    {
        auto &param = sprite->_asyncLoadParam;
        bool ok = param.modelData->loadFromFile(param.modelPath);
        if (ok && param.skeletonData)
        {
            ok = param.skeletonData->loadFromFile(param.skeletonPath);
        }
        param.result = ok;
    });
    
}

void Sprite3D::afterAsyncLoad(void* param)
{
    Sprite3D::AsyncLoadParam* asyncParam = (Sprite3D::AsyncLoadParam*)param;
    autorelease();
    if (asyncParam)
    {
        if (asyncParam->result)
        {
            _meshes.clear();
            _meshesSorted.clear();
            _meshVertexDatas.clear();
            CC_SAFE_RELEASE_NULL(_skeleton);
            removeAllAttachNode();
            
            auto& skeletonDataPtr = asyncParam->skeletonData;
            
            Sprite3DCache::Sprite3DData* skeletonData = nullptr;
            if (skeletonDataPtr)
            {
                skeletonData = Sprite3DCache::getInstance()->getSpriteData(asyncParam->skeletonPath);
                if (!skeletonData)
                {
                    skeletonData = skeletonDataPtr.release();
                    Sprite3DCache::getInstance()->addSprite3DData(asyncParam->skeletonPath, skeletonData);
                    CC_SAFE_RELEASE(skeletonData);
                }
            }

            
            //create in the main thread
            auto& modelDataPtr = asyncParam->modelData;
            auto modelData = Sprite3DCache::getInstance()->getSpriteData(asyncParam->modelPath);
            if (modelDataPtr && !modelData)
            {
                modelData = modelDataPtr.release();
                Sprite3DCache::getInstance()->addSprite3DData(asyncParam->modelPath, modelData);
                CC_SAFE_RELEASE(modelData);
            }
            
            if (modelData) {
                applySpriteData(modelData, skeletonData ? Skeleton3D::create(skeletonData->nodedatas.skeleton) : nullptr);
                genMaterial();
            }
            
            if (!asyncParam->texPath.empty())
            {
                setTexture(asyncParam->texPath);
            }
        }
        else
        {
            CCLOG("file load failed: %s ", asyncParam->modelPath.c_str());
            if (!asyncParam->skeletonPath.empty() && asyncParam->skeletonPath != asyncParam->modelPath)
                CCLOG("file load failed: %s ", asyncParam->skeletonPath.c_str());
        }
        asyncParam->afterLoadCallback(this, asyncParam->callbackParam);
    }
}

AABB Sprite3D::getAABBRecursivelyImp(Node *node)
{
    AABB aabb;
    for (auto iter : node->getChildren()){
        aabb.merge(getAABBRecursivelyImp(iter));
    }
    
    Sprite3D *sprite3d = dynamic_cast<Sprite3D*>(node);
    if (sprite3d)
        aabb.merge(sprite3d->getAABB());

    return aabb;
}

bool Sprite3D::loadFromCache(const std::string& path, const std::string& skeletonPath)
{
    if (!skeletonPath.empty() && skeletonPath != path)
    {
        auto spritedata = Sprite3DCache::getInstance()->getSpriteData(skeletonPath);
        if (spritedata)
        {
            return loadFromCache(path, spritedata->nodedatas.skeleton);
        }
    }
    
    return loadFromCache(path);
}

bool Sprite3D::loadFromCache(const std::string& path, const std::vector<NodeData*>& skeletonData)
{
    auto spritedata = Sprite3DCache::getInstance()->getSpriteData(path);
    if (spritedata)
    {
        applySpriteData(spritedata, Skeleton3D::create(skeletonData));
        return true;
    }
    
    return false;
}

void Sprite3D::setSkeleton(Skeleton3D *skeleton)
{
    if (skeleton == _skeleton)
        return;
    
    CC_SAFE_RELEASE(_skeleton);
    _skeleton = skeleton;
    CC_SAFE_RETAIN(_skeleton);
}

void Sprite3D::applySpriteData(Sprite3DCache::Sprite3DData *spritedata, Skeleton3D* skele)
{
    spritedata->prepareMeshVertexData();
    _meshVertexDatas.reserve(spritedata->meshVertexDatas.size());
    _meshVertexDatas.clear();
    for (auto it : spritedata->meshVertexDatas) {
        _meshVertexDatas.pushBack(it);
    }

    setSkeleton(skele ? skele : Skeleton3D::create(spritedata->nodedatas.skeleton));

    const bool singleSprite = (spritedata->nodedatas.nodes.size() == 1);
    for(const auto& it : spritedata->nodedatas.nodes)
    {
        if(it)
        {
            createNode(it, this, spritedata->materialdatas, singleSprite);
        }
    }
    
    if(!skele){
        for(const auto& it : spritedata->nodedatas.skeleton)
        {
            if(it)
            {
                createAttachSprite3DNode(it, spritedata->materialdatas);
            }
        }
    }

    auto& programStates = spritedata->programStates;
    ssize_t meshCount = _meshes.size();
    if (programStates.empty()) {
        programStates.reserve(meshCount);
        for (const auto mesh : _meshes) {
            programStates.pushBack(mesh->getProgramState());
        }
    } else {
        for (ssize_t i = 0; i < meshCount; ++i) {
            // cloning is needed in order to have one state per sprite
            auto glstate = spritedata->programStates.at(i);
            _meshes.at(i)->setProgramState(glstate->clone());
        }
    }
}

bool Sprite3D::loadFromCache(const std::string& path, Skeleton3D* skele /*= nullptr*/)
{
    auto spritedata = Sprite3DCache::getInstance()->getSpriteData(path);
    if (spritedata)
    {
        applySpriteData(spritedata, skele);
        return true;
    }
    
    return false;
}

static bool loadFromBundle(Bundle3D* bundle, NodeDatas* nodedatas, MeshDatas* meshdatas,  MaterialDatas* materialdatas)
{
    bool isSkeleton = false;
    if (!bundle->loadMeshDatas(*meshdatas)) {
        meshdatas->resetData();
        isSkeleton = true;
    }
    if (!bundle->loadMaterials(*materialdatas)){
        materialdatas->resetData();
        isSkeleton = true;
    }
    bool ret = bundle->loadNodes(*nodedatas);
    if (isSkeleton) {
        if (nodedatas->skeleton.empty()) {
            nodedatas->skeleton.swap(nodedatas->nodes);
        }
    }
    return ret;
}

Sprite3D::Sprite3D()
: _skeleton(nullptr)
, _blend(BlendFunc::ALPHA_NON_PREMULTIPLIED)
, _aabbDirty(true)
, _lightMask(-1)
, _shaderUsingLight(false)
, _forceDepthWrite(false)
, _usingAutogeneratedGLProgram(true)
, _forceDisableDepthTest(false)
{
}

Sprite3D::~Sprite3D()
{
    _meshes.clear();
    _meshesSorted.clear();
    _meshVertexDatas.clear();
    CC_SAFE_RELEASE_NULL(_skeleton);
    removeAllAttachNode();
}

bool Sprite3D::init()
{
    if(Node::init())
    {
        return true;
    }
    return false;
}

bool Sprite3D::initWithFile(const std::string& path, Skeleton3D* skele /*= nullptr*/)
{
    _aabbDirty = true;
    _meshes.clear();
    _meshesSorted.clear();
    _meshVertexDatas.clear();
    CC_SAFE_RELEASE_NULL(_skeleton);
    removeAllAttachNode();
    
    if (loadFromCache(path, skele))
        return true;
    
    auto modelData = new (std::nothrow) Sprite3DCache::Sprite3DData;
    if (modelData && modelData->loadFromFile(path))
    {
        applySpriteData(modelData, skele);
        genMaterial();
        
        Sprite3DCache::getInstance()->addSprite3DData(path, modelData);
        CC_SAFE_RELEASE(modelData);
        return true;
    }
    CC_SAFE_DELETE(modelData);
    
    return false;
}

Mesh *Sprite3D::createMesh(NodeData* nodedata, ModelData* modeldata, const MaterialDatas& materialdatas) const
{
    auto mesh = Mesh::create(nodedata->id, getMeshIndexData(modeldata->subMeshId));
    if (!mesh)
        return mesh;
    
    if (_skeleton && modeldata->bones.size())
    {
        auto skin = MeshSkin::create(_skeleton, modeldata->bones, modeldata->invBindPose);
        mesh->setSkin(skin);
    }
    
    const NMaterialData* materialData;
    if (modeldata->materialId.empty() && materialdatas.materials.size())
    {
        materialData = &materialdatas.materials[0];
        const NTextureData* textureData = materialData->getTextureData(NTextureData::Usage::Diffuse);
        mesh->setTexture(adjustTextureExtension(textureData->filename));
    }
    else
    {
        materialData = materialdatas.getMaterialData(modeldata->materialId);
        if(materialData)
        {
            const NTextureData* textureData = materialData->getTextureData(NTextureData::Usage::Diffuse);
            if(textureData)
            {
                mesh->setTexture(adjustTextureExtension(textureData->filename));
                auto tex = mesh->getTexture();
                if(tex)
                {
                    Texture2D::TexParams texParams;
                    texParams.minFilter = backend::SamplerFilter::LINEAR;
                    texParams.magFilter = backend::SamplerFilter::LINEAR;
                    texParams.sAddressMode = textureData->wrapS;
                    texParams.tAddressMode = textureData->wrapT;
                    tex->setTexParameters(texParams);
                }
            }
            textureData = materialData->getTextureData(NTextureData::Usage::Normal);
            if (textureData)
            {
                auto tex = Director::getInstance()->getTextureCache()->addImage(adjustTextureExtension(textureData->filename));
                if(tex)
                {
                    Texture2D::TexParams texParams;
                    texParams.minFilter = backend::SamplerFilter::LINEAR;
                    texParams.magFilter = backend::SamplerFilter::LINEAR;
                    texParams.sAddressMode = textureData->wrapS;
                    texParams.tAddressMode = textureData->wrapT;
                    tex->setTexParameters(texParams);
                }
                mesh->setTexture(tex, NTextureData::Usage::Normal);
            }
        }
    }
    
    if (materialData) {
        mesh->_isTransparent = (materialData->getTextureData(NTextureData::Usage::Transparency) != nullptr);
    }
    
    return mesh;
}

Sprite3D* Sprite3D::createSprite3DNode(NodeData* nodedata,ModelData* modeldata,const MaterialDatas& materialdatas)
{
    auto sprite = new (std::nothrow) Sprite3D();
    if (sprite)
    {
        sprite->setName(nodedata->id);
        auto mesh = createMesh(nodedata, modeldata, materialdatas);
        // set locale transform
        Vec3 pos;
        Quaternion qua;
        Vec3 scale;
        nodedata->transform.decompose(&scale, &qua, &pos);
        sprite->setPosition3D(pos);
        sprite->setRotationQuat(qua);
        sprite->setScaleX(scale.x);
        sprite->setScaleY(scale.y);
        sprite->setScaleZ(scale.z);
        
        sprite->addMesh(mesh);
        sprite->autorelease();
        sprite->genMaterial();
    }
    return   sprite;
}
void Sprite3D::createAttachSprite3DNode(NodeData* nodedata, const MaterialDatas& materialdatas)
{
    for(const auto& it : nodedata->modelNodeDatas)
    {
        if(it && getAttachNode(nodedata->id))
        {
            auto sprite = createSprite3DNode(nodedata,it,materialdatas);
            if (sprite)
            {
                getAttachNode(nodedata->id)->addChild(sprite);
            }
        }
    }
    for(const auto& it : nodedata->children)
    {
        createAttachSprite3DNode(it,materialdatas);
    }
}

void Sprite3D::setMaterial(Material *material)
{
    setMaterial(material, -1);
}

void Sprite3D::setMaterial(Material *material, int meshIndex)
{
    CCASSERT(material, "Invalid Material");
    CCASSERT(meshIndex == -1 || (meshIndex >=0 && meshIndex < _meshes.size()), "Invalid meshIndex");


    if (meshIndex == -1)
    {
        for (ssize_t i = 0, size = _meshes.size(); i < size; ++i)
        {
            _meshes.at(i)->setMaterial(i == 0 ? material : material->clone());
        }
    }
    else
    {
        auto mesh = _meshes.at(meshIndex);
        mesh->setMaterial(material);
    }

    _usingAutogeneratedGLProgram = false;
}

Material* Sprite3D::getMaterial(int meshIndex) const
{
    CCASSERT(meshIndex >=0 && meshIndex < _meshes.size(), "Invalid meshIndex");
    return _meshes.at(meshIndex)->getMaterial();
}


void Sprite3D::genMaterial(bool useLight)
{
    _shaderUsingLight = useLight;

    using MaterialMap = std::unordered_map<const MeshVertexData*, Sprite3DMaterial*>;
    MaterialMap materials;
    MaterialMap alphaTestMaterials;
    
    for (auto& mesh: _meshes)
    {
        auto meshVertexData = mesh->getMeshIndexData()->getMeshVertexData();
        Sprite3DMaterial** m;
        bool isTransparent = mesh->_isTransparent;
        if (isTransparent) {
            m = &materials[meshVertexData];
        } else {
            m = &alphaTestMaterials[meshVertexData];
        }
        auto material = *m;
        if (!material) {
            *m = material = getSprite3DMaterialForAttribs(meshVertexData, useLight, !isTransparent);
        }
        
        CCASSERT(material, "material should not be null");
     
        //keep original state block if exist
        auto oldmaterial = mesh->getMaterial();
        if (oldmaterial)
        {
            material->setStateBlock(oldmaterial->getStateBlock());
        }

        if (material->getReferenceCount() == 1)
            mesh->setMaterial(material);
        else
            mesh->setMaterial(material->clone());
    }
}

void Sprite3D::createNode(NodeData* nodedata, Node* root, const MaterialDatas& materialdatas, bool singleSprite)
{
    Node* node=nullptr;
    for(const auto& it : nodedata->modelNodeDatas)
    {
        if(it)
        {
            if(it->bones.size() > 0 || singleSprite)
            {
                if(singleSprite && root!=nullptr)
                    root->setName(nodedata->id);
                auto mesh = createMesh(nodedata, it, materialdatas);
                if (mesh)
                {
                    _meshes.pushBack(mesh);
                    _meshesSorted.clear();
                    mesh->_visibleChanged = std::bind(&Sprite3D::onAABBDirty, this);
                    
                    Vec3 pos;
                    Quaternion qua;
                    Vec3 scale;
                    nodedata->transform.decompose(&scale, &qua, &pos);
                    setPosition3D(pos);
                    setRotationQuat(qua);
                    setScaleX(scale.x);
                    setScaleY(scale.y);
                    setScaleZ(scale.z);
                    
                    node = this;
                }
            }
            else
            {
                auto sprite = createSprite3DNode(nodedata,it,materialdatas);
                if (sprite)
                {
                    if(root)
                    {
                        root->addChild(sprite);
                    }
                }
                node=sprite;
            }
        }
    }
    if(nodedata->modelNodeDatas.empty())
    {
        node= Node::create();
        if(node)
        {
            node->setName(nodedata->id);
            
            // set locale transform
            Vec3 pos;
            Quaternion qua;
            Vec3 scale;
            nodedata->transform.decompose(&scale, &qua, &pos);
            node->setPosition3D(pos);
            node->setRotationQuat(qua);
            node->setScaleX(scale.x);
            node->setScaleY(scale.y);
            node->setScaleZ(scale.z);
            
            if(root)
            {
                root->addChild(node);
            }
        }
    }

    auto size = nodedata->children.size();
    for(const auto& it : nodedata->children)
    {
        createNode(it,node, materialdatas, size == 1);
    }
}

MeshIndexData* Sprite3D::getMeshIndexData(const std::string& indexId) const
{
    for (auto it : _meshVertexDatas) {
        auto index = it->getMeshIndexDataById(indexId);
        if (index)
            return index;
    }
    return nullptr;
}

void  Sprite3D::addMesh(Mesh* mesh)
{
    auto meshVertex = mesh->getMeshIndexData()->_vertexData;
    mesh->_visibleChanged = std::bind(&Sprite3D::onAABBDirty, this);
    _meshVertexDatas.pushBack(meshVertex);
    _meshes.pushBack(mesh);
    _meshesSorted.clear();
}

void Sprite3D::setTexture(const std::string& texFile)
{
    auto tex = Director::getInstance()->getTextureCache()->addImage(adjustTextureExtension(texFile));
    setTexture(tex);
}

void Sprite3D::setTexture(Texture2D* texture)
{
    for (auto mesh: _meshes) {
        mesh->setTexture(texture);
    }
}
AttachNode* Sprite3D::getAttachNode(const std::string& boneName)
{
    auto it = _attachments.find(boneName);
    if (it != _attachments.end())
        return it->second;
    
    if (_skeleton)
    {
        auto bone = _skeleton->getBoneByName(boneName);
        if (bone)
        {
            auto attachNode = AttachNode::create(bone);
            addChild(attachNode);
            _attachments[boneName] = attachNode;
            return attachNode;
        }
    }
    
    return nullptr;
}

void Sprite3D::removeAttachNode(const std::string& boneName)
{
    auto it = _attachments.find(boneName);
    if (it != _attachments.end())
    {
        removeChild(it->second);
        _attachments.erase(it);
    }
}

void Sprite3D::removeAllAttachNode()
{
    for (auto& it : _attachments) {
        removeChild(it.second);
    }
    _attachments.clear();
}

void Sprite3D::visit(cocos2d::Renderer *renderer, const cocos2d::Mat4 &parentTransform, uint32_t parentFlags)
{
    // quick return if not visible. children won't be drawn.
    if (!_visible)
    {
        return;
    }
    
    if (_meshesSorted.empty())
    {
        _meshesSorted = _meshes;
        std::stable_sort(_meshesSorted.begin(), _meshesSorted.end(), [](Mesh* a, Mesh* b) -> bool {
            return !a->_isTransparent;
        });
    }
    
    
    uint32_t flags = processParentFlags(parentTransform, parentFlags);
    flags |= FLAGS_RENDER_AS_3D;
    
    //
    Director* director = Director::getInstance();
    director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, _modelViewTransform);
    
    bool visibleByCamera = isVisitableByVisitingCamera();
    
    int i = 0;
    
    if(!_children.empty())
    {
        sortAllChildren();
        // draw children zOrder < 0
        for(auto size = _children.size() ; i < size; i++ )
        {
            auto node = _children.at(i);
            
            if (node && node->getLocalZOrder() < 0)
                node->visit(renderer, _modelViewTransform, flags);
            else
                break;
        }
        // self draw
        if (visibleByCamera)
            this->draw(renderer, _modelViewTransform, flags);
        
        for(auto it=_children.cbegin()+i, itCend = _children.cend(); it != itCend; ++it)
            (*it)->visit(renderer, _modelViewTransform, flags);
    }
    else if (visibleByCamera)
    {
        this->draw(renderer, _modelViewTransform, flags);
    }
    
    director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
}

void Sprite3D::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{
#if CC_USE_CULLING
    //TODO new-renderer: interface isVisibleInFrustum removal
    // camera clipping
//    if(_children.size() == 0 && Camera::getVisitingCamera() && !Camera::getVisitingCamera()->isVisibleInFrustum(&getAABB()))
//        return;
#endif
    
    if (_skeleton)
        _skeleton->updateBoneMatrix();
    
    Color4F color(getDisplayedColor());
    color.a = getDisplayedOpacity() / 255.0f;
    
    //check light and determine the shader used
    const auto& scene = Director::getInstance()->getRunningScene();

    // Don't override GLProgramState if using manually set Material
    if (_usingAutogeneratedGLProgram && scene)
    {
        const auto lights = scene->getLights();
        bool usingLight = false;
        for (const auto light : lights) {
            usingLight = light->isEnabled() && ((static_cast<unsigned int>(light->getLightFlag()) & _lightMask) > 0);
            if (usingLight)
                break;
        }
        if (usingLight != _shaderUsingLight)
        {
            genMaterial(usingLight);
        }
    }
    
    
    for (auto mesh: _meshesSorted)
    {
        mesh->setForce2DQueue(_force2Dqueue);
        mesh->setForceDisableDepthTest(_forceDisableDepthTest);
        mesh->draw(renderer,
                   _globalZOrder,
                   transform,
                   flags,
                   _lightMask,
                   Vec4(color.r, color.g, color.b, color.a),
                   _forceDepthWrite);

    }
}

void Sprite3D::setProgramState(backend::ProgramState* programState)
{
    for (auto state : _meshes) {
        state->setProgramState(programState->clone());
    }
}

void Sprite3D::setBlendFunc(const BlendFunc& blendFunc)
{
    if(_blend.src != blendFunc.src || _blend.dst != blendFunc.dst)
    {
        _blend = blendFunc;
        for(auto mesh: _meshes)
        {
            mesh->setBlendFunc(blendFunc);
        }
    }
}

const BlendFunc& Sprite3D::getBlendFunc() const
{
    return _blend;
}

AABB Sprite3D::getAABBRecursively()
{
    return getAABBRecursivelyImp(this);
}

const AABB& Sprite3D::getAABB() const
{
    Mat4 nodeToWorldTransform(getNodeToWorldTransform());
    
    // If nodeToWorldTransform matrix isn't changed, we don't need to transform aabb.
    //    if (memcmp(_nodeToWorldTransform.m, nodeToWorldTransform.m, sizeof(Mat4)) == 0 && !_aabbDirty)
    if (!_aabbDirty && memcmp(_nodeToWorldTransform.m, nodeToWorldTransform.m, sizeof(Mat4)) == 0)
    {
        return _aabb;
    }
    else
    {
        _aabb.reset();
        if (_meshes.size())
        {
            Mat4 transform(nodeToWorldTransform);
            for (const auto& it : _meshes) {
                if (it->isVisible())
                    _aabb.merge(it->getAABB());
            }
            
            _aabb.transform(transform);
            _nodeToWorldTransform = nodeToWorldTransform;
            _aabbDirty = false;
        }
    }
    
    return _aabb;
}

Action* Sprite3D::runAction(Action *action)
{
    // setForceDepthWrite(true);
    return Node::runAction(action);
}

Rect Sprite3D::getBoundingBox() const
{
    AABB aabb = getAABB();
    Rect ret(aabb._min.x, aabb._min.y, (aabb._max.x - aabb._min.x), (aabb._max.y - aabb._min.y));
    return ret;
}

void Sprite3D::setCullFace(CullFaceSide side)
{
    for (auto& it : _meshes) {
        it->getMaterial()->getStateBlock().setCullFaceSide(side);
//        it->getMeshCommand().setCullFace(cullFace);
    }
}

void Sprite3D::setCullFaceEnabled(bool enable)
{
    for (auto& it : _meshes) {
        it->getMaterial()->getStateBlock().setCullFace(enable);
//        it->getMeshCommand().setCullFaceEnabled(enable);
    }
}

Mesh* Sprite3D::getMeshByIndex(int index) const
{
    CCASSERT(index < _meshes.size(), "invalid index");
    return _meshes.at(index);
}

/**get Mesh by Name */
Mesh* Sprite3D::getMeshByName(const std::string& name) const
{
    for (const auto& it : _meshes) {
        if (it->getName() == name)
            return it;
    }
    return nullptr;
}

std::vector<Mesh*> Sprite3D::getMeshArrayByName(const std::string& name) const
{
    std::vector<Mesh*> meshes;
    for (const auto& it : _meshes) {
        if (it->getName() == name)
            meshes.push_back(it);
    }
    return meshes;
}

Mesh* Sprite3D::getMesh() const
{
    if(_meshes.empty())
    {
        return nullptr;
    }
    return _meshes.at(0);
}

void Sprite3D::setForce2DQueue(bool force2D)
{
    _force2Dqueue = force2D;
}

///////////////////////////////////////////////////////////////////////////////////
Sprite3DCache* Sprite3DCache::_cacheInstance = nullptr;
Sprite3DCache* Sprite3DCache::getInstance()
{
    if (_cacheInstance == nullptr)
        _cacheInstance = new (std::nothrow) Sprite3DCache();
    return _cacheInstance;
}
void Sprite3DCache::destroyInstance()
{
    if (_cacheInstance)
    {
        delete _cacheInstance;
        _cacheInstance = nullptr;
    }
}

Sprite3DCache::Sprite3DData* Sprite3DCache::getSpriteData(const std::string& key) const
{
    auto it = _spriteDatas.find(key);
    if (it != _spriteDatas.end())
        return it->second;
    return nullptr;
}

bool Sprite3DCache::addSprite3DData(const std::string& key, Sprite3DData* spritedata)
{
    auto it = _spriteDatas.find(key);
    if (it == _spriteDatas.end())
    {
        _spriteDatas.insert(key, spritedata);
        return true;
    }
    return false;
}

void Sprite3DCache::removeSprite3DData(const std::string& key)
{
    auto it = _spriteDatas.find(key);
    if (it != _spriteDatas.end())
    {
        _spriteDatas.erase(it);
    }
}

void Sprite3DCache::removeAllSprite3DData()
{
    _spriteDatas.clear();
}

Sprite3DCache::Sprite3DCache()
{
    
}
Sprite3DCache::~Sprite3DCache()
{
    removeAllSprite3DData();
}

//
// MARK: Helpers
//
static Sprite3DMaterial* getSprite3DMaterialForAttribs(const MeshVertexData* meshVertexData, bool usesLight, bool alphaTest)
{
    bool textured = meshVertexData->hasVertexAttrib(shaderinfos::VertexKey::VERTEX_ATTRIB_TEX_COORD);
    bool hasSkin = meshVertexData->hasVertexAttrib(shaderinfos::VertexKey::VERTEX_ATTRIB_BLEND_INDEX)
    && meshVertexData->hasVertexAttrib(shaderinfos::VertexKey::VERTEX_ATTRIB_BLEND_WEIGHT);
    bool hasNormal = meshVertexData->hasVertexAttrib(shaderinfos::VertexKey::VERTEX_ATTRIB_NORMAL);
    bool hasTangentSpace = meshVertexData->hasVertexAttrib(shaderinfos::VertexKey::VERTEX_ATTRIB_TANGENT)
    && meshVertexData->hasVertexAttrib(shaderinfos::VertexKey::VERTEX_ATTRIB_BINORMAL);
    
    Sprite3DMaterial::MaterialType type;
    if(textured)
    {
        if (hasTangentSpace){
            type = hasNormal && usesLight ? Sprite3DMaterial::MaterialType::BUMPED_DIFFUSE : Sprite3DMaterial::MaterialType::UNLIT;
        }
        else{
            type = hasNormal && usesLight ? Sprite3DMaterial::MaterialType::DIFFUSE : Sprite3DMaterial::MaterialType::UNLIT;
        }
    }
    else
    {
        type = hasNormal && usesLight ? Sprite3DMaterial::MaterialType::DIFFUSE_NOTEX : Sprite3DMaterial::MaterialType::UNLIT_NOTEX;
    }
    
    Sprite3DMaterial* ret = Sprite3DMaterial::createBuiltInMaterial(type, hasSkin, meshVertexData->getAtrSetId(), alphaTest);
    
    return ret;
}

Sprite3DCache::Sprite3DData::~Sprite3DData()
{
    meshVertexDatas.clear();
    programStates.clear();
}

bool Sprite3DCache::Sprite3DData::loadFromFile(const std::string &filePath)
{
    std::string ext = FileUtils::getInstance()->getFileExtension(filePath);
    if (ext == ".obj")
    {
        return loadFromObj(filePath);
    }
    else if (ext == ".c3b" || ext == ".c3t")
    {
        //load from .c3b or .c3t
        Bundle3D bundle;
        
        return bundle.load(filePath) && loadFromBundle(&bundle);
    }
    return false;
}

bool Sprite3DCache::Sprite3DData::loadFromObj(const std::string &filePath)
{
    NodeDatas nodedatas;
    MeshDatas meshdatas;
    MaterialDatas materialdatas;
    
    bool ok = Bundle3D::loadObj(meshdatas, materialdatas, nodedatas, filePath);
    if (ok) {
        apply(nodedatas, meshdatas, materialdatas);
    }
    return ok;
}

bool Sprite3DCache::Sprite3DData::loadFromBundle(Bundle3D *bundle)
{
    NodeDatas nodedatas;
    MeshDatas meshdatas;
    MaterialDatas materialdatas;
    
    bool ok = cocos2d::loadFromBundle(bundle, &nodedatas, &meshdatas, &materialdatas);
    
    if (ok) {
        apply(nodedatas, meshdatas, materialdatas);
    }
    
    return ok;
}

void Sprite3DCache::Sprite3DData::prepareMeshVertexData()
{
    if (meshdatas.meshDatas.empty()) {
        return;
    }
    meshVertexDatas.reserve(meshdatas.meshDatas.size());
    meshVertexDatas.clear();
    for(const auto& it : meshdatas.meshDatas)
    {
        if(it)
        {
            auto meshvertex = MeshVertexData::create(*it);
            meshVertexDatas.pushBack(meshvertex);
        }
    }
    meshdatas.resetData();
}

void Sprite3DCache::Sprite3DData::apply(NodeDatas &nodedatas, MeshDatas &meshdatas, MaterialDatas &materialdatas)
{
    programStates.clear();
    meshVertexDatas.clear();
    this->meshdatas.resetData();
    this->nodedatas.resetData();
    this->meshdatas = std::move(meshdatas);
    this->nodedatas = std::move(nodedatas);
    this->materialdatas = std::move(materialdatas);   
}

NS_CC_END
