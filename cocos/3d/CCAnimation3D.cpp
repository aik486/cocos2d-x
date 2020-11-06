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

#include "3d/CCAnimation3D.h"
#include "3d/CCBundle3D.h"
#include "platform/CCFileUtils.h"

NS_CC_BEGIN

Animation3D* Animation3D::create(const std::string& fileName, const std::string& animationName)
{
    std::string fullPath = FileUtils::getInstance()->fullPathForFilename(fileName);
    std::string key = fullPath + "#" + animationName;
    auto animation = Animation3DCache::getInstance()->getAnimation(key);
    if (animation != nullptr)
        return animation;
    
    animation = new (std::nothrow) Animation3D();
    if(animation && animation->initWithFile(fileName, animationName))
    {
        animation->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(animation);
    }
    
    return animation;
}

Animation3D *Animation3D::createWithBundle(Bundle3D* bundle, const std::string &animationName)
{
    auto animation = new (std::nothrow) Animation3D();   
    if (animation && animation->initWithBundle(bundle, animationName)) {
        animation->autorelease();
    } else {
        CC_SAFE_DELETE(animation);
    }
    
    return animation;
}

bool Animation3D::initWithFile(const std::string& filename, const std::string& animationName)
{
    std::string fullPath = FileUtils::getInstance()->fullPathForFilename(filename);
    
    //load animation here
    Bundle3D bundle;
    if (bundle.load(fullPath) && initWithBundle(&bundle, animationName))
    {
        std::string key = fullPath + "#" + animationName;
        Animation3DCache::getInstance()->addAnimation(key, this);
        return true;
    }
    
    return false;
}

Animation3D::Curve* Animation3D::getBoneCurveByName(const std::string& name) const
{
    auto it = _boneCurves.find(name);
    if (it != _boneCurves.end())
        return it->second;
    
    return nullptr;
}

Animation3D::Animation3D()
: _duration(0)
{
    
}

Animation3D::~Animation3D()
{
    for (const auto& itor : _boneCurves) {
        Curve* curve = itor.second;
        CC_SAFE_DELETE(curve);
    }
}

Animation3D::Curve::Curve()
: translateCurve(nullptr)
, rotCurve(nullptr)
, scaleCurve(nullptr)
{
    
}
Animation3D::Curve::~Curve()
{
    CC_SAFE_RELEASE_NULL(translateCurve);
    CC_SAFE_RELEASE_NULL(rotCurve);
    CC_SAFE_RELEASE_NULL(scaleCurve);
}

bool Animation3D::init(const Animation3DData &data)
{
    _duration = data._totalTime;

    std::vector<float> keys;
    std::vector<float> values;
    for(const auto& iter : data._translationKeys)
    {
        Curve* curve = _boneCurves[iter.first];
        if( curve == nullptr)
        {
            curve = new (std::nothrow) Curve();
            _boneCurves[iter.first] = curve;
        }

        auto count = iter.second.size();        
        if(count == 0) continue;
        keys.clear();
        values.clear();
        keys.reserve(count);
        values.reserve(count * 3);
        for(const auto& keyIter : iter.second)
        {
            keys.push_back(keyIter._time);
            values.push_back(keyIter._key.x);
            values.push_back(keyIter._key.y);
            values.push_back(keyIter._key.z);
        }
        
        if (auto tc = curve->translateCurve = new (std::nothrow) Curve::AnimationCurveVec3) {
            tc->init(&keys[0], &values[0], (int)keys.size());
        }
    }
    
    for(const auto& iter : data._rotationKeys)
    {
        Curve* curve = _boneCurves[iter.first];
        if( curve == nullptr)
        {
            curve = new (std::nothrow) Curve();
            _boneCurves[iter.first] = curve;
        }
        
        auto count = iter.second.size();        
        if(count == 0) continue;
        keys.clear();
        values.clear();
        keys.reserve(count);
        values.reserve(count * 4);
        for(const auto& keyIter : iter.second)
        {
            keys.push_back(keyIter._time);
            values.push_back(keyIter._key.x);
            values.push_back(keyIter._key.y);
            values.push_back(keyIter._key.z);
            values.push_back(keyIter._key.w);
        }
        
        if (auto rotCurve = curve->rotCurve = new (std::nothrow) Curve::AnimationCurveQuat) {
            rotCurve->init(&keys[0], &values[0], (int)keys.size());
        }
    }
    
    for(const auto& iter : data._scaleKeys)
    {
        Curve* curve = _boneCurves[iter.first];
        if( curve == nullptr)
        {
            curve = new (std::nothrow) Curve();
            _boneCurves[iter.first] = curve;
        }
        
        auto count = iter.second.size();        
        if(count == 0) continue;
        keys.clear();
        values.clear();
        keys.reserve(count);
        values.reserve(count * 3);
        for(const auto& keyIter : iter.second)
        {
            keys.push_back(keyIter._time);
            values.push_back(keyIter._key.x);
            values.push_back(keyIter._key.y);
            values.push_back(keyIter._key.z);
        }
        
        if (auto scaleCurve = curve->scaleCurve = new (std::nothrow)  Curve::AnimationCurveVec3) {
            curve->scaleCurve->init(&keys[0], &values[0], (int)keys.size());
        }
    }
    
    return true;
}

bool Animation3D::initWithBundle(Bundle3D *bundle, const std::string& animationName)
{
    if (!bundle || !bundle->isLoaded()) {
        return false;
    }   
    
    Animation3DData animationdata;
    return bundle->loadAnimationData(animationName, &animationdata) && init(animationdata);
}

////////////////////////////////////////////////////////////////
Animation3DCache* Animation3DCache::_cacheInstance = nullptr;

Animation3DCache* Animation3DCache::getInstance()
{
    if (_cacheInstance == nullptr)
        _cacheInstance = new (std::nothrow) Animation3DCache();
    
    return _cacheInstance;
}
void Animation3DCache::destroyInstance()
{
    CC_SAFE_DELETE(_cacheInstance);
}

Animation3D* Animation3DCache::getAnimation(const std::string& key)
{
    auto it = _animations.find(key);
    if (it != _animations.end())
        return it->second;
    return nullptr;
}

void Animation3DCache::addAnimation(const std::string& key, Animation3D* animation)
{
    const auto& it = _animations.find(key);
    if (it != _animations.end())
    {
        return; // already have this key
    }
    _animations.insert(key, animation);
}

void Animation3DCache::removeAnimation(const std::string &key)
{
    _animations.erase(key);
}

void Animation3DCache::removeAllAnimations()
{
    _animations.clear();
}

void Animation3DCache::removeUnusedAnimations()
{
    for (auto itor = _animations.begin(); itor != _animations.end(); ) {
        if (itor->second->getReferenceCount() == 1)
        {
            itor = _animations.erase(itor);
        }
        else
            ++itor;
    }
}

Animation3DCache::Animation3DCache()
{
    
}
Animation3DCache::~Animation3DCache()
{
    removeAllAnimations();
}

NS_CC_END
