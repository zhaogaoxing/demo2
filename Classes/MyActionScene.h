#ifndef __MyActionScene_SCENE_H__
#define __MyActionScene_SCENE_H__

#include "cocos2d.h"
#include "PlayScene.h"


class MyAction : public cocos2d::Layer
{

	bool hiddenFlag;
	cocos2d::Sprite * sprite;

public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void goMenu(cocos2d::Ref * pSender);
	void backMenu(cocos2d::Ref * pSender);

	CREATE_FUNC(MyAction);
};

#endif // __MyActionScene_SCENE_H__