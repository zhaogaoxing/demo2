#ifndef __PLAYSCENE4_SCENE_H__
#define __PLAYSCENE4_SCENE_H__
//动作速度控制
#include "cocos2d.h"
#include "MyActionScene4.h"

enum {
	kEaseIn = 1
	,kEaseOut
	,kEaseInOut
	,kEaseSineIn
	,kEaseSineOut
	,kEaseSineInOut
	,kEaseExponentialIn
	,kEaseExponentialOut
	,kEaseExponentialInOut
	,kSpeed
	,kback
};

class PlayScene4 : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	void OnClikMenu(cocos2d::Ref * pSender);
	void OnBack(cocos2d::Ref * pSender);

	CREATE_FUNC(PlayScene4);
};

#endif // __PLAYSCENE4_SCENE_H__