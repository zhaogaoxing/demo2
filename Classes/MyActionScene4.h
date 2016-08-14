#ifndef __MyActionScene4_SCENE_H__
#define __MyActionScene4_SCENE_H__

#include "cocos2d.h"
#include "PlayScene4.h"


class MyAction4 : public cocos2d::Layer
{

	cocos2d::Sprite * sprite;

public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void goMenu(cocos2d::Ref * pSender);
	void backMenu(cocos2d::Ref * pSender);


	CREATE_FUNC(MyAction4);
};

#endif // __MyActionScene4_SCENE_H__