#ifndef __PLAYSCENE3_SCENE_H__
#define __PLAYSCENE3_SCENE_H__

#include "cocos2d.h"
#include "MyActionScene3.h"

enum {
	kSequence = 100,
	kSpawn,
	kRepeate,
	kRepeateForever1,
	kReverse,
	back
};

class PlayScene3 : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	void OnClikMenu(cocos2d::Ref * pSender);
	void OnBack(cocos2d::Ref * pSender);

	CREATE_FUNC(PlayScene3);
};

#endif // __PLAYSCENE3_SCENE_H__
