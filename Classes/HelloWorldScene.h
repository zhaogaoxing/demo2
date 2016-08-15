#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "SettingScene.h"
#include "PlayScene.h"
#include "PlayScene4.h"
#include "PlayScene5.h"

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

	void onEnter();
	void onEnterTransitionDidFinish();
	void onExit();
	void onExitTransitionDidStart();
	void cleanup();

	void menuItemSettingCallback(cocos2d::Ref * pSender);
	void menuItemStartCallback(cocos2d::Ref * pSender);
	void menuItemHelpCallback(cocos2d::Ref * pSender);
	void menuItemSpeedCallback(cocos2d::Ref * pSender);
	void menuItemFuncCallback(cocos2d::Ref * pSender);
	void menuItemSpecCallback(cocos2d::Ref * pSender);


    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
