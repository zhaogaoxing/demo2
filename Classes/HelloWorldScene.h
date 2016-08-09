#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "SettingScene.h"
#include "PlayScene.h"


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

	void menuItem1Callback(cocos2d::Ref * pSender);

    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
