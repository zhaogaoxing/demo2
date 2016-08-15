#ifndef __MyActionScene6_SCENE_H__
#define __MyActionScene6_SCENE_H__

#include "cocos2d.h"
#include "PlayScene6.h"


class MyAction6 : public cocos2d::Layer
{

	cocos2d::Sprite * sprite;
	cocos2d::NodeGrid * gridNodeTarget;

public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void goMenu(cocos2d::Ref * pSender);
	void backMenu(cocos2d::Ref * pSender);


	CREATE_FUNC(MyAction6);
};

#endif // __MyActionScene6_SCENE_H__