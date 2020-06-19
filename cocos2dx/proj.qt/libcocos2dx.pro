include(libcocos2dx.pri)

QT += core gui widgets

CONFIG += c++11 warn_off
DESTDIR = $$COCOS2DX_LIB
TARGET = cocos2dx
TEMPLATE = lib
CONFIG += staticlib

CONFIG(debug, debug|release) {
    DEFINES += DEBUG
} else {
    DEFINES += NDEBUG
}

!isEmpty(DEBUG_COCOS) {
    emscripten:DEFINES += QT_FORCE_ASSERTS
}

msvc {
    QMAKE_CXXFLAGS_WARN_OFF -= -W0
    QMAKE_CXXFLAGS += -W3 /wd4251 /wd4573
    DEFINES += _CRT_SECURE_NO_WARNINGS
    DEFINES += _SCL_SECURE_NO_WARNINGS
    CONFIG += no_batch
    QMAKE_CXXFLAGS += /wd4005 /wd4244 /bigobj
} else {
    clang|gcc {
        QMAKE_CXXFLAGS += \
            -Wno-unknown-pragmas \
            -Wno-overloaded-virtual \
            -Wno-unused-function \
            -Wno-deprecated-declarations

        clang:QMAKE_CXXFLAGS += \
            -Wno-unused-private-field \
            -Wno-unneeded-internal-declaration \
            -Wno-null-conversion \
            -Wno-unsequenced \
            -Wno-nonnull
        else:gcc:QMAKE_CXXFLAGS += \
            -Wno-nonnull-compare \
            -Wno-sequence-point \
            -Wno-sign-compare \
            -Wno-misleading-indentation

        INCLUDEPATH += \
            $$COCOS2DX_PATH/cocos2dx/platform \
            $$COCOS2DX_PATH/cocos2dx/cocoa \
            $$COCOS2DX_PATH/cocos2dx/text_input_node \
            $$COCOS2DX_PATH/cocos2dx/touch_dispatcher
        DEFINES += USE_FILE32API
    }
}

SOURCES +=\
    src/QtCocosContext.cpp \
    src/QtCocosHelper.cpp \
    src/QtCocosExtension.cpp \
    src/QtCocosEGLView.cpp \
    src/QtCocosWindow.cpp \
    $$COCOS2DX_PATH/extensions/GUI/CCControlExtension/CCScale9Sprite.cpp \
    $$COCOS2DX_PATH/cocos2dx/base_nodes/CCGLBufferedNode.cpp \
    $$COCOS2DX_PATH/cocos2dx/base_nodes/CCAtlasNode.cpp \
    $$COCOS2DX_PATH/cocos2dx/base_nodes/CCNode.cpp \
    $$COCOS2DX_PATH/cocos2dx/ccFPSImages.c \
    $$COCOS2DX_PATH/cocos2dx/cocoa/CCAffineTransform.cpp \
    $$COCOS2DX_PATH/cocos2dx/cocoa/CCArray.cpp \
    $$COCOS2DX_PATH/cocos2dx/cocoa/CCAutoreleasePool.cpp \
    $$COCOS2DX_PATH/cocos2dx/cocoa/CCDataVisitor.cpp \
    $$COCOS2DX_PATH/cocos2dx/cocoa/CCDictionary.cpp \
    $$COCOS2DX_PATH/cocos2dx/cocoa/CCGeometry.cpp \
    $$COCOS2DX_PATH/cocos2dx/cocoa/CCNS.cpp \
    $$COCOS2DX_PATH/cocos2dx/cocoa/CCObject.cpp \
    $$COCOS2DX_PATH/cocos2dx/cocoa/CCSet.cpp \
    $$COCOS2DX_PATH/cocos2dx/cocoa/CCString.cpp \
    $$COCOS2DX_PATH/cocos2dx/cocoa/CCZone.cpp \
    $$COCOS2DX_PATH/cocos2dx/draw_nodes/CCDrawingPrimitives.cpp \
    $$COCOS2DX_PATH/cocos2dx/draw_nodes/CCDrawNode.cpp \
    $$COCOS2DX_PATH/cocos2dx/effects/CCGrabber.cpp \
    $$COCOS2DX_PATH/cocos2dx/effects/CCGrid.cpp \
    $$COCOS2DX_PATH/cocos2dx/actions/CCAction.cpp \
    $$COCOS2DX_PATH/cocos2dx/actions/CCActionCamera.cpp \
    $$COCOS2DX_PATH/cocos2dx/actions/CCActionCatmullRom.cpp \
    $$COCOS2DX_PATH/cocos2dx/actions/CCActionEase.cpp \
    $$COCOS2DX_PATH/cocos2dx/actions/CCActionGrid.cpp \
    $$COCOS2DX_PATH/cocos2dx/actions/CCActionGrid3D.cpp \
    $$COCOS2DX_PATH/cocos2dx/actions/CCActionInstant.cpp \
    $$COCOS2DX_PATH/cocos2dx/actions/CCActionInterval.cpp \
    $$COCOS2DX_PATH/cocos2dx/actions/CCActionManager.cpp \
    $$COCOS2DX_PATH/cocos2dx/actions/CCActionPageTurn3D.cpp \
    $$COCOS2DX_PATH/cocos2dx/actions/CCActionProgressTimer.cpp \
    $$COCOS2DX_PATH/cocos2dx/actions/CCActionTiledGrid.cpp \
    $$COCOS2DX_PATH/cocos2dx/actions/CCActionTween.cpp \
    $$COCOS2DX_PATH/cocos2dx/label_nodes/CCLabelAtlas.cpp \
    $$COCOS2DX_PATH/cocos2dx/label_nodes/CCLabelBMFont.cpp \
    $$COCOS2DX_PATH/cocos2dx/label_nodes/CCLabelTTF.cpp \
    $$COCOS2DX_PATH/cocos2dx/layers_scenes_transitions_nodes/CCLayer.cpp \
    $$COCOS2DX_PATH/cocos2dx/layers_scenes_transitions_nodes/CCScene.cpp \
    $$COCOS2DX_PATH/cocos2dx/layers_scenes_transitions_nodes/CCTransition.cpp \
    $$COCOS2DX_PATH/cocos2dx/layers_scenes_transitions_nodes/CCTransitionPageTurn.cpp \
    $$COCOS2DX_PATH/cocos2dx/layers_scenes_transitions_nodes/CCTransitionProgress.cpp \
    $$COCOS2DX_PATH/cocos2dx/menu_nodes/CCMenu.cpp \
    $$COCOS2DX_PATH/cocos2dx/menu_nodes/CCMenuItem.cpp \
    $$COCOS2DX_PATH/cocos2dx/misc_nodes/CCClippingNode.cpp \
    $$COCOS2DX_PATH/cocos2dx/misc_nodes/CCMotionStreak.cpp \
    $$COCOS2DX_PATH/cocos2dx/misc_nodes/CCProgressTimer.cpp \
    $$COCOS2DX_PATH/cocos2dx/misc_nodes/CCRenderTexture.cpp \
    $$COCOS2DX_PATH/cocos2dx/particle_nodes/CCParticleBatchNode.cpp \
    $$COCOS2DX_PATH/cocos2dx/particle_nodes/CCParticleExamples.cpp \
    $$COCOS2DX_PATH/cocos2dx/particle_nodes/CCParticleSystem.cpp \
    $$COCOS2DX_PATH/cocos2dx/particle_nodes/CCParticleSystemQuad.cpp \
    $$COCOS2DX_PATH/cocos2dx/platform/CCEGLViewProtocol.cpp \
    $$COCOS2DX_PATH/cocos2dx/platform/CCFileUtils.cpp \
    $$COCOS2DX_PATH/cocos2dx/platform/CCSAXParser.cpp \
    $$COCOS2DX_PATH/cocos2dx/platform/platform.cpp \
    $$COCOS2DX_PATH/cocos2dx/platform/qt/CCImage.cpp \
    $$COCOS2DX_PATH/cocos2dx/shaders/CCGLProgram.cpp \
    $$COCOS2DX_PATH/cocos2dx/shaders/ccGLStateCache.cpp \
    $$COCOS2DX_PATH/cocos2dx/shaders/CCShaderCache.cpp \
    $$COCOS2DX_PATH/cocos2dx/shaders/ccShaders.cpp \
    $$COCOS2DX_PATH/cocos2dx/sprite_nodes/CCAnimation.cpp \
    $$COCOS2DX_PATH/cocos2dx/sprite_nodes/CCAnimationCache.cpp \
    $$COCOS2DX_PATH/cocos2dx/sprite_nodes/CCSprite.cpp \
    $$COCOS2DX_PATH/cocos2dx/sprite_nodes/CCSpriteBatchNode.cpp \
    $$COCOS2DX_PATH/cocos2dx/sprite_nodes/CCSpriteFrame.cpp \
    $$COCOS2DX_PATH/cocos2dx/sprite_nodes/CCSpriteFrameCache.cpp \
    $$COCOS2DX_PATH/cocos2dx/support/base64.cpp \
    $$COCOS2DX_PATH/cocos2dx/support/CCNotificationCenter.cpp \
    $$COCOS2DX_PATH/cocos2dx/support/CCPointExtension.cpp \
    $$COCOS2DX_PATH/cocos2dx/support/CCProfiling.cpp \
    $$COCOS2DX_PATH/cocos2dx/support/ccUTF8.cpp \
    $$COCOS2DX_PATH/cocos2dx/support/ccUtils.cpp \
    $$COCOS2DX_PATH/cocos2dx/support/CCVertex.cpp \
    $$COCOS2DX_PATH/cocos2dx/support/component/CCComponent.cpp \
    $$COCOS2DX_PATH/cocos2dx/support/component/CCComponentContainer.cpp \
    $$COCOS2DX_PATH/cocos2dx/support/tinyxml2/tinyxml2.cpp \
    $$COCOS2DX_PATH/cocos2dx/support/TransformUtils.cpp \
    $$COCOS2DX_PATH/cocos2dx/support/data_support/ccCArray.cpp \
    $$COCOS2DX_PATH/cocos2dx/support/image_support/TGAlib.cpp \
    $$COCOS2DX_PATH/cocos2dx/support/user_default/CCUserDefault.cpp \
    $$COCOS2DX_PATH/cocos2dx/support/zip_support/ioapi.cpp \
    $$COCOS2DX_PATH/cocos2dx/support/zip_support/unzip.cpp \
    $$COCOS2DX_PATH/cocos2dx/support/zip_support/ZipUtils.cpp \
    $$COCOS2DX_PATH/cocos2dx/textures/CCTexture2D.cpp \
    $$COCOS2DX_PATH/cocos2dx/textures/CCTextureAtlas.cpp \
    $$COCOS2DX_PATH/cocos2dx/textures/CCTextureCache.cpp \
    $$COCOS2DX_PATH/cocos2dx/textures/CCTextureETC.cpp \
    $$COCOS2DX_PATH/cocos2dx/textures/CCTexturePVR.cpp \
    $$COCOS2DX_PATH/cocos2dx/tilemap_parallax_nodes/CCParallaxNode.cpp \
    $$COCOS2DX_PATH/cocos2dx/tilemap_parallax_nodes/CCTileMapAtlas.cpp \
    $$COCOS2DX_PATH/cocos2dx/tilemap_parallax_nodes/CCTMXLayer.cpp \
    $$COCOS2DX_PATH/cocos2dx/tilemap_parallax_nodes/CCTMXObjectGroup.cpp \
    $$COCOS2DX_PATH/cocos2dx/tilemap_parallax_nodes/CCTMXTiledMap.cpp \
    $$COCOS2DX_PATH/cocos2dx/tilemap_parallax_nodes/CCTMXXMLParser.cpp \
    $$COCOS2DX_PATH/cocos2dx/touch_dispatcher/CCTouch.cpp \
    $$COCOS2DX_PATH/cocos2dx/touch_dispatcher/CCTouchDispatcher.cpp \
    $$COCOS2DX_PATH/cocos2dx/touch_dispatcher/CCTouchHandler.cpp \
    $$COCOS2DX_PATH/cocos2dx/keypad_dispatcher/CCKeypadDelegate.cpp \
    $$COCOS2DX_PATH/cocos2dx/keypad_dispatcher/CCKeypadDispatcher.cpp \
    $$COCOS2DX_PATH/cocos2dx/text_input_node/CCIMEDispatcher.cpp \
    $$COCOS2DX_PATH/cocos2dx/text_input_node/CCTextFieldTTF.cpp \
    $$COCOS2DX_PATH/cocos2dx/script_support/CCScriptSupport.cpp \
    $$COCOS2DX_PATH/cocos2dx/kazmath/src/aabb.c \
    $$COCOS2DX_PATH/cocos2dx/kazmath/src/mat3.c \
    $$COCOS2DX_PATH/cocos2dx/kazmath/src/mat4.c \
    $$COCOS2DX_PATH/cocos2dx/kazmath/src/plane.c \
    $$COCOS2DX_PATH/cocos2dx/kazmath/src/quaternion.c \
    $$COCOS2DX_PATH/cocos2dx/kazmath/src/ray2.c \
    $$COCOS2DX_PATH/cocos2dx/kazmath/src/utility.c \
    $$COCOS2DX_PATH/cocos2dx/kazmath/src/vec2.c \
    $$COCOS2DX_PATH/cocos2dx/kazmath/src/vec3.c \
    $$COCOS2DX_PATH/cocos2dx/kazmath/src/vec4.c \
    $$COCOS2DX_PATH/cocos2dx/kazmath/src/GL/mat4stack.c \
    $$COCOS2DX_PATH/cocos2dx/kazmath/src/GL/matrix.c \
    $$COCOS2DX_PATH/cocos2dx/CCCamera.cpp \
    $$COCOS2DX_PATH/cocos2dx/CCConfiguration.cpp \
    $$COCOS2DX_PATH/cocos2dx/CCDirector.cpp \
    $$COCOS2DX_PATH/cocos2dx/CCScheduler.cpp \
    $$COCOS2DX_PATH/cocos2dx/cocos2d.cpp

HEADERS += \
    src/QtCocosContext.h \
    src/QtCocosHelper.h \
    src/QtCocosExtension.h \
    src/cocos2dx_qt.h \
    src/cocos_warnings_off.h \
    src/cocos_warnings_pop.h \
    src/QtCocosEGLView.h \
    src/QtCocosWindow.h \
    $$COCOS2DX_PATH/extensions/GUI/CCControlExtension/CCScale9Sprite.h \
    $$COCOS2DX_PATH/cocos2dx/base_nodes/CCGLBufferedNode.h \
    $$COCOS2DX_PATH/cocos2dx/base_nodes/CCAtlasNode.h \
    $$COCOS2DX_PATH/cocos2dx/base_nodes/CCNode.h \
    $$COCOS2DX_PATH/cocos2dx/ccFPSImages.h \
    $$COCOS2DX_PATH/cocos2dx/cocoa/CCAffineTransform.h \
    $$COCOS2DX_PATH/cocos2dx/cocoa/CCArray.h \
    $$COCOS2DX_PATH/cocos2dx/cocoa/CCAutoreleasePool.h \
    $$COCOS2DX_PATH/cocos2dx/cocoa/CCBool.h \
    $$COCOS2DX_PATH/cocos2dx/cocoa/CCDataVisitor.h \
    $$COCOS2DX_PATH/cocos2dx/cocoa/CCDictionary.h \
    $$COCOS2DX_PATH/cocos2dx/cocoa/CCDouble.h \
    $$COCOS2DX_PATH/cocos2dx/cocoa/CCFloat.h \
    $$COCOS2DX_PATH/cocos2dx/cocoa/CCGeometry.h \
    $$COCOS2DX_PATH/cocos2dx/cocoa/CCInteger.h \
    $$COCOS2DX_PATH/cocos2dx/cocoa/CCNS.h \
    $$COCOS2DX_PATH/cocos2dx/cocoa/CCObject.h \
    $$COCOS2DX_PATH/cocos2dx/cocoa/CCSet.h \
    $$COCOS2DX_PATH/cocos2dx/cocoa/CCString.h \
    $$COCOS2DX_PATH/cocos2dx/cocoa/CCZone.h \
    $$COCOS2DX_PATH/cocos2dx/draw_nodes/CCDrawingPrimitives.h \
    $$COCOS2DX_PATH/cocos2dx/draw_nodes/CCDrawNode.h \
    $$COCOS2DX_PATH/cocos2dx/effects/CCGrabber.h \
    $$COCOS2DX_PATH/cocos2dx/effects/CCGrid.h \
    $$COCOS2DX_PATH/cocos2dx/actions/CCAction.h \
    $$COCOS2DX_PATH/cocos2dx/actions/CCActionCamera.h \
    $$COCOS2DX_PATH/cocos2dx/actions/CCActionCatmullRom.h \
    $$COCOS2DX_PATH/cocos2dx/actions/CCActionEase.h \
    $$COCOS2DX_PATH/cocos2dx/actions/CCActionGrid.h \
    $$COCOS2DX_PATH/cocos2dx/actions/CCActionGrid3D.h \
    $$COCOS2DX_PATH/cocos2dx/actions/CCActionInstant.h \
    $$COCOS2DX_PATH/cocos2dx/actions/CCActionInterval.h \
    $$COCOS2DX_PATH/cocos2dx/actions/CCActionManager.h \
    $$COCOS2DX_PATH/cocos2dx/actions/CCActionPageTurn3D.h \
    $$COCOS2DX_PATH/cocos2dx/actions/CCActionProgressTimer.h \
    $$COCOS2DX_PATH/cocos2dx/actions/CCActionTiledGrid.h \
    $$COCOS2DX_PATH/cocos2dx/actions/CCActionTween.h \
    $$COCOS2DX_PATH/cocos2dx/include/ccConfig.h \
    $$COCOS2DX_PATH/cocos2dx/include/CCEventType.h \
    $$COCOS2DX_PATH/cocos2dx/include/ccMacros.h \
    $$COCOS2DX_PATH/cocos2dx/include/CCProtocols.h \
    $$COCOS2DX_PATH/cocos2dx/include/ccTypes.h \
    $$COCOS2DX_PATH/cocos2dx/include/ccTypeInfo.h \
    $$COCOS2DX_PATH/cocos2dx/include/cocos2d.h \
    $$COCOS2DX_PATH/cocos2dx/label_nodes/CCLabelAtlas.h \
    $$COCOS2DX_PATH/cocos2dx/label_nodes/CCLabelBMFont.h \
    $$COCOS2DX_PATH/cocos2dx/label_nodes/CCLabelTTF.h \
    $$COCOS2DX_PATH/cocos2dx/layers_scenes_transitions_nodes/CCLayer.h \
    $$COCOS2DX_PATH/cocos2dx/layers_scenes_transitions_nodes/CCScene.h \
    $$COCOS2DX_PATH/cocos2dx/layers_scenes_transitions_nodes/CCTransition.h \
    $$COCOS2DX_PATH/cocos2dx/layers_scenes_transitions_nodes/CCTransitionPageTurn.h \
    $$COCOS2DX_PATH/cocos2dx/layers_scenes_transitions_nodes/CCTransitionProgress.h \
    $$COCOS2DX_PATH/cocos2dx/menu_nodes/CCMenu.h \
    $$COCOS2DX_PATH/cocos2dx/menu_nodes/CCMenuItem.h \
    $$COCOS2DX_PATH/cocos2dx/misc_nodes/CCClippingNode.h \
    $$COCOS2DX_PATH/cocos2dx/misc_nodes/CCMotionStreak.h \
    $$COCOS2DX_PATH/cocos2dx/misc_nodes/CCProgressTimer.h \
    $$COCOS2DX_PATH/cocos2dx/misc_nodes/CCRenderTexture.h \
    $$COCOS2DX_PATH/cocos2dx/particle_nodes/CCParticleBatchNode.h \
    $$COCOS2DX_PATH/cocos2dx/particle_nodes/CCParticleExamples.h \
    $$COCOS2DX_PATH/cocos2dx/particle_nodes/CCParticleSystem.h \
    $$COCOS2DX_PATH/cocos2dx/particle_nodes/CCParticleSystemQuad.h \
    $$COCOS2DX_PATH/cocos2dx/platform/CCAccelerometerDelegate.h \
    $$COCOS2DX_PATH/cocos2dx/platform/CCApplicationProtocol.h \
    $$COCOS2DX_PATH/cocos2dx/platform/CCCommon.h \
    $$COCOS2DX_PATH/cocos2dx/platform/CCEGLViewProtocol.h \
    $$COCOS2DX_PATH/cocos2dx/platform/CCFileUtils.h \
    $$COCOS2DX_PATH/cocos2dx/platform/CCImage.h \
    $$COCOS2DX_PATH/cocos2dx/platform/CCPlatformConfig.h \
    $$COCOS2DX_PATH/cocos2dx/platform/CCPlatformMacros.h \
    $$COCOS2DX_PATH/cocos2dx/platform/CCSAXParser.h \
    $$COCOS2DX_PATH/cocos2dx/platform/CCThread.h \
    $$COCOS2DX_PATH/cocos2dx/platform/platform.h \
    $$COCOS2DX_PATH/cocos2dx/shaders/CCGLProgram.h \
    $$COCOS2DX_PATH/cocos2dx/shaders/ccGLStateCache.h \
    $$COCOS2DX_PATH/cocos2dx/shaders/CCShaderCache.h \
    $$COCOS2DX_PATH/cocos2dx/shaders/ccShaderEx_SwitchMask_frag.h \
    $$COCOS2DX_PATH/cocos2dx/shaders/ccShaders.h \
    $$COCOS2DX_PATH/cocos2dx/shaders/ccShader_PositionColorLengthTexture_frag.h \
    $$COCOS2DX_PATH/cocos2dx/shaders/ccShader_PositionColorLengthTexture_vert.h \
    $$COCOS2DX_PATH/cocos2dx/shaders/ccShader_PositionColor_frag.h \
    $$COCOS2DX_PATH/cocos2dx/shaders/ccShader_PositionColor_vert.h \
    $$COCOS2DX_PATH/cocos2dx/shaders/ccShader_PositionTextureA8Color_frag.h \
    $$COCOS2DX_PATH/cocos2dx/shaders/ccShader_PositionTextureA8Color_vert.h \
    $$COCOS2DX_PATH/cocos2dx/shaders/ccShader_PositionTextureColorAlphaTest_frag.h \
    $$COCOS2DX_PATH/cocos2dx/shaders/ccShader_PositionTextureColor_frag.h \
    $$COCOS2DX_PATH/cocos2dx/shaders/ccShader_PositionTextureColor_vert.h \
    $$COCOS2DX_PATH/cocos2dx/shaders/ccShader_PositionTexture_frag.h \
    $$COCOS2DX_PATH/cocos2dx/shaders/ccShader_PositionTexture_uColor_frag.h \
    $$COCOS2DX_PATH/cocos2dx/shaders/ccShader_PositionTexture_uColor_vert.h \
    $$COCOS2DX_PATH/cocos2dx/shaders/ccShader_PositionTexture_vert.h \
    $$COCOS2DX_PATH/cocos2dx/shaders/ccShader_Position_uColor_frag.h \
    $$COCOS2DX_PATH/cocos2dx/shaders/ccShader_Position_uColor_vert.h \
    $$COCOS2DX_PATH/cocos2dx/sprite_nodes/CCAnimation.h \
    $$COCOS2DX_PATH/cocos2dx/sprite_nodes/CCAnimationCache.h \
    $$COCOS2DX_PATH/cocos2dx/sprite_nodes/CCSprite.h \
    $$COCOS2DX_PATH/cocos2dx/sprite_nodes/CCSpriteBatchNode.h \
    $$COCOS2DX_PATH/cocos2dx/sprite_nodes/CCSpriteFrame.h \
    $$COCOS2DX_PATH/cocos2dx/sprite_nodes/CCSpriteFrameCache.h \
    $$COCOS2DX_PATH/cocos2dx/support/base64.h \
    $$COCOS2DX_PATH/cocos2dx/support/CCNotificationCenter.h \
    $$COCOS2DX_PATH/cocos2dx/support/CCPointExtension.h \
    $$COCOS2DX_PATH/cocos2dx/support/CCProfiling.h \
    $$COCOS2DX_PATH/cocos2dx/support/ccUTF8.h \
    $$COCOS2DX_PATH/cocos2dx/support/ccUtils.h \
    $$COCOS2DX_PATH/cocos2dx/support/CCVertex.h \
    $$COCOS2DX_PATH/cocos2dx/support/component/CCComponent.h \
    $$COCOS2DX_PATH/cocos2dx/support/component/CCComponentContainer.h \
    $$COCOS2DX_PATH/cocos2dx/support/tinyxml2\tinyxml2.h \
    $$COCOS2DX_PATH/cocos2dx/support/TransformUtils.h \
    $$COCOS2DX_PATH/cocos2dx/support/data_support/ccCArray.h \
    $$COCOS2DX_PATH/cocos2dx/support/data_support/uthash.h \
    $$COCOS2DX_PATH/cocos2dx/support/data_support/utlist.h \
    $$COCOS2DX_PATH/cocos2dx/support/image_support/TGAlib.h \
    $$COCOS2DX_PATH/cocos2dx/support/user_default/CCUserDefault.h \
    $$COCOS2DX_PATH/cocos2dx/support/zip_support/ioapi.h \
    $$COCOS2DX_PATH/cocos2dx/support/zip_support/unzip.h \
    $$COCOS2DX_PATH/cocos2dx/support/zip_support/ZipUtils.h \
    $$COCOS2DX_PATH/cocos2dx/textures/CCTexture2D.h \
    $$COCOS2DX_PATH/cocos2dx/textures/CCTextureAtlas.h \
    $$COCOS2DX_PATH/cocos2dx/textures/CCTextureCache.h \
    $$COCOS2DX_PATH/cocos2dx/textures/CCTextureETC.h \
    $$COCOS2DX_PATH/cocos2dx/textures/CCTexturePVR.h \
    $$COCOS2DX_PATH/cocos2dx/tilemap_parallax_nodes/CCParallaxNode.h \
    $$COCOS2DX_PATH/cocos2dx/tilemap_parallax_nodes/CCTileMapAtlas.h \
    $$COCOS2DX_PATH/cocos2dx/tilemap_parallax_nodes/CCTMXLayer.h \
    $$COCOS2DX_PATH/cocos2dx/tilemap_parallax_nodes/CCTMXObjectGroup.h \
    $$COCOS2DX_PATH/cocos2dx/tilemap_parallax_nodes/CCTMXTiledMap.h \
    $$COCOS2DX_PATH/cocos2dx/tilemap_parallax_nodes/CCTMXXMLParser.h \
    $$COCOS2DX_PATH/cocos2dx/touch_dispatcher/CCTouch.h \
    $$COCOS2DX_PATH/cocos2dx/touch_dispatcher/CCTouchDelegateProtocol.h \
    $$COCOS2DX_PATH/cocos2dx/touch_dispatcher/CCTouchDispatcher.h \
    $$COCOS2DX_PATH/cocos2dx/touch_dispatcher/CCTouchHandler.h \
    $$COCOS2DX_PATH/cocos2dx/keypad_dispatcher/CCKeypadDelegate.h \
    $$COCOS2DX_PATH/cocos2dx/keypad_dispatcher/CCKeypadDispatcher.h \
    $$COCOS2DX_PATH/cocos2dx/text_input_node/CCIMEDelegate.h \
    $$COCOS2DX_PATH/cocos2dx/text_input_node/CCIMEDispatcher.h \
    $$COCOS2DX_PATH/cocos2dx/text_input_node/CCTextFieldTTF.h \
    $$COCOS2DX_PATH/cocos2dx/script_support/CCScriptSupport.h \
    $$COCOS2DX_PATH/cocos2dx/kazmath/include/kazmath/aabb.h \
    $$COCOS2DX_PATH/cocos2dx/kazmath/include/kazmath/kazmath.h \
    $$COCOS2DX_PATH/cocos2dx/kazmath/include/kazmath/mat3.h \
    $$COCOS2DX_PATH/cocos2dx/kazmath/include/kazmath/mat4.h \
    $$COCOS2DX_PATH/cocos2dx/kazmath/include/kazmath/plane.h \
    $$COCOS2DX_PATH/cocos2dx/kazmath/include/kazmath/quaternion.h \
    $$COCOS2DX_PATH/cocos2dx/kazmath/include/kazmath/ray2.h \
    $$COCOS2DX_PATH/cocos2dx/kazmath/include/kazmath/utility.h \
    $$COCOS2DX_PATH/cocos2dx/kazmath/include/kazmath/vec2.h \
    $$COCOS2DX_PATH/cocos2dx/kazmath/include/kazmath/vec3.h \
    $$COCOS2DX_PATH/cocos2dx/kazmath/include/kazmath/vec4.h \
    $$COCOS2DX_PATH/cocos2dx/kazmath/include/kazmath/GL/mat4stack.h \
    $$COCOS2DX_PATH/cocos2dx/kazmath/include/kazmath/GL/matrix.h \
    $$COCOS2DX_PATH/cocos2dx/CCCamera.h \
    $$COCOS2DX_PATH/cocos2dx/CCConfiguration.h \
    $$COCOS2DX_PATH/cocos2dx/CCDirector.h \
    $$COCOS2DX_PATH/cocos2dx/CCScheduler.h \
    $$COCOS2DX_PATH/cocos2dx/CCObjectHolder.h


macx {
SOURCES +=\
    $$COCOS2DX_PATH/cocos2dx/platform/mac/CCWindow.m \
    $$COCOS2DX_PATH/cocos2dx/platform/mac/CCApplication.mm \
    $$COCOS2DX_PATH/cocos2dx/platform/mac/CCCommon.mm \
    $$COCOS2DX_PATH/cocos2dx/platform/mac/CCDevice.mm \
    $$COCOS2DX_PATH/cocos2dx/platform/mac/CCDirectorCaller.mm \
    $$COCOS2DX_PATH/cocos2dx/platform/mac/CCEGLView.mm \
    $$COCOS2DX_PATH/cocos2dx/platform/mac/CCEventDispatcher.mm \
    $$COCOS2DX_PATH/cocos2dx/platform/mac/CCFileUtilsMac.mm \
    $$COCOS2DX_PATH/cocos2dx/platform/mac/CCThread.mm \
    $$COCOS2DX_PATH/cocos2dx/platform/mac/EAGLView.mm

HEADERS +=\
    $$COCOS2DX_PATH/cocos2dx/platform/mac/CCAccelerometer.h \
    $$COCOS2DX_PATH/cocos2dx/platform/mac/CCApplication.h \
    $$COCOS2DX_PATH/cocos2dx/platform/mac/CCDirectorCaller.h \
    $$COCOS2DX_PATH/cocos2dx/platform/mac/CCEGLView.h \
    $$COCOS2DX_PATH/cocos2dx/platform/mac/CCEventDispatcher.h \
    $$COCOS2DX_PATH/cocos2dx/platform/mac/CCFileUtilsMac.h \
    $$COCOS2DX_PATH/cocos2dx/platform/mac/CCGL.h \
    $$COCOS2DX_PATH/cocos2dx/platform/mac/CCPlatformDefine.h \
    $$COCOS2DX_PATH/cocos2dx/platform/mac/CCStdC.h \
    $$COCOS2DX_PATH/cocos2dx/platform/mac/CCWindow.h \
    $$COCOS2DX_PATH/cocos2dx/platform/mac/EAGLView.h
}

win32 {
SOURCES +=\
    $$COCOS2DX_PATH/cocos2dx/platform/win32/CCAccelerometer.cpp \
    $$COCOS2DX_PATH/cocos2dx/platform/win32/CCApplication.cpp \
    $$COCOS2DX_PATH/cocos2dx/platform/win32/CCCommon.cpp \
    $$COCOS2DX_PATH/cocos2dx/platform/win32/CCDevice.cpp \
    $$COCOS2DX_PATH/cocos2dx/platform/win32/CCEGLView.cpp \
    $$COCOS2DX_PATH/cocos2dx/platform/win32/CCFileUtilsWin32.cpp \
    $$COCOS2DX_PATH/cocos2dx/platform/win32/CCStdC.cpp \
    $$COCOS2DX_PATH/cocos2dx/platform/CCThread.cpp

HEADERS +=\
    $$COCOS2DX_PATH/cocos2dx/platform/win32/CCAccelerometer.h \
    $$COCOS2DX_PATH/cocos2dx/platform/win32/CCApplication.h \
    $$COCOS2DX_PATH/cocos2dx/platform/win32/CCEGLView.h \
    $$COCOS2DX_PATH/cocos2dx/platform/win32/CCFileUtilsWin32.h \
    $$COCOS2DX_PATH/cocos2dx/platform/win32/CCGL.h \
    $$COCOS2DX_PATH/cocos2dx/platform/win32/CCPlatformDefine.h \
    $$COCOS2DX_PATH/cocos2dx/platform/win32/CCStdC.h
}


emscripten {
SOURCES +=\
    $$COCOS2DX_PATH/cocos2dx/platform/emscripten/CCApplication.cpp \
    $$COCOS2DX_PATH/cocos2dx/platform/emscripten/CCCommon.cpp \
    $$COCOS2DX_PATH/cocos2dx/platform/emscripten/CCDevice.cpp \
    $$COCOS2DX_PATH/cocos2dx/platform/emscripten/CCEGLView.cpp \
    $$COCOS2DX_PATH/cocos2dx/platform/emscripten/CCFileUtilsEmscripten.cpp \
    $$COCOS2DX_PATH/cocos2dx/platform/CCThread.cpp

HEADERS +=\
    $$COCOS2DX_PATH/cocos2dx/platform/emscripten/CCAccelerometer.h \
    $$COCOS2DX_PATH/cocos2dx/platform/emscripten/CCApplication.h \
    $$COCOS2DX_PATH/cocos2dx/platform/emscripten/CCEGLView.h \
    $$COCOS2DX_PATH/cocos2dx/platform/emscripten/CCFileUtilsEmscripten.h \
    $$COCOS2DX_PATH/cocos2dx/platform/emscripten/CCGL.h \
    $$COCOS2DX_PATH/cocos2dx/platform/emscripten/CCPlatformDefine.h \
    $$COCOS2DX_PATH/cocos2dx/platform/emscripten/CCStdC.h
}


linux {
SOURCES +=\
    src/CCEGLViewLinux.cpp \
    $$COCOS2DX_PATH/cocos2dx/platform/linux/CCApplication.cpp \
    $$COCOS2DX_PATH/cocos2dx/platform/linux/CCCommon.cpp \
    $$COCOS2DX_PATH/cocos2dx/platform/linux/CCDevice.cpp \
    $$COCOS2DX_PATH/cocos2dx/platform/linux/CCFileUtilsLinux.cpp \
    $$COCOS2DX_PATH/cocos2dx/platform/linux/CCStdC.cpp \
    $$COCOS2DX_PATH/cocos2dx/platform/CCThread.cpp

HEADERS +=\
    $$COCOS2DX_PATH/cocos2dx/platform/linux/CCAccelerometer.h \
    $$COCOS2DX_PATH/cocos2dx/platform/linux/CCApplication.h \
    $$COCOS2DX_PATH/cocos2dx/platform/linux/CCEGLView.h \
    $$COCOS2DX_PATH/cocos2dx/platform/linux/CCFileUtilsLinux.h \
    $$COCOS2DX_PATH/cocos2dx/platform/linux/CCGL.h \
    $$COCOS2DX_PATH/cocos2dx/platform/linux/CCPlatformDefine.h \
    $$COCOS2DX_PATH/cocos2dx/platform/linux/CCStdC.h
}
