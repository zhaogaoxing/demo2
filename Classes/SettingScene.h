#ifndef __SETTING_SCENE_H__
#define __SETTING_SCENE_H__

#include "cocos2d.h"

class Setting : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void onEnter();
	void onEnterTransitionDidFinish();
	void onExit();
	void onExitTransitionDidStart();
	void cleanup();

	void menuItem1Callback(cocos2d::Ref * pSender);

	void menuSoundToggleCallback(cocos2d::Ref * pSender);
	void menuOkCallback(cocos2d::Ref * pSender);
	CREATE_FUNC(Setting);
};

#endif // __SETTING_SCENE_H__