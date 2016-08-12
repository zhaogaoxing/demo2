#ifndef __MyActionScene3_SCENE_H__
#define __MyActionScene3_SCENE_H__

#include "cocos2d.h"
#include "PlayScene3.h"


class MyAction3 : public cocos2d::Layer
{

	cocos2d::Sprite * sprite;

public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void goMenu(cocos2d::Ref * pSender);
	void backMenu(cocos2d::Ref * pSender);

	void OnSequence(cocos2d::Ref * pSender);
	void OnSpawn(cocos2d::Ref * pSender);
	void OnRepeat(cocos2d::Ref * pSender);
	void OnReverse(cocos2d::Ref * pSender);
	void OnRepeatForever(cocos2d::Ref * pSender);

	CREATE_FUNC(MyAction3);
};

#endif // __MyActionScene3_SCENE_H__