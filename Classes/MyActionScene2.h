#ifndef __MyActionScene2_SCENE_H__
#define __MyActionScene2_SCENE_H__

#include "cocos2d.h"
#include "PlayScene2.h"


class MyAction2 : public cocos2d::Layer
{

	cocos2d::Sprite * sprite;

public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void goMenu2(cocos2d::Ref * pSender);
	void backMenu2(cocos2d::Ref * pSender);

	CREATE_FUNC(MyAction2);
};

#endif // __MyActionScene2_SCENE_H__