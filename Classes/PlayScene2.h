#ifndef __PlayScene2_SCENE_H__
#define __PlayScene2_SCENE_H__

#include "cocos2d.h"
#include "MyActionScene2.h"
enum two
{
	kMoveTo = 100,
	kMoveBy,kJumpTo,kJumpBy,kBezierBy,
	kScaleTo,kScaleBy,kRotateTo,kRotateBy,
	kBlink,kTintTo,kTintBy,
	kFadeTo,kFadeIn,kFadeOut,
	kBack
};

class PlayScene2 : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void OnClikMenu2(cocos2d::Ref * pSender);
	void OnBack2(cocos2d::Ref * pSender);

	CREATE_FUNC(PlayScene2);
};

#endif // __PlayScene2_SCENE_H__