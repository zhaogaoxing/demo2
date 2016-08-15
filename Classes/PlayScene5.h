#ifndef __PLAYSCENE5_SCENE_H__
#define __PLAYSCENE5_SCENE_H__
//动作速度控制
#include "cocos2d.h"
#include "MyActionScene5.h"

enum {
	func = 1,
	funcN,
	fback,
};

class PlayScene5 : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	void OnClikMenu(cocos2d::Ref * pSender);
	void OnBack(cocos2d::Ref * pSender);

	CREATE_FUNC(PlayScene5);
};

#endif // __PLAYSCENE5_SCENE_H__