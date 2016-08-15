#ifndef __MyActionScene5_SCENE_H__
#define __MyActionScene5_SCENE_H__

#include "cocos2d.h"
#include "PlayScene5.h"


class MyAction5 : public cocos2d::Layer
{

	cocos2d::Sprite * sprite;

public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void goMenu(cocos2d::Ref * pSender);
	void backMenu(cocos2d::Ref * pSender);

	void OnCallFunc(cocos2d::Ref * pSender);
	void OnCallFuncN(cocos2d::Ref * pSender);

	void CallBack1();
	void CallBack2(cocos2d::Ref *pSender);


	CREATE_FUNC(MyAction5);
};

#endif // __MyActionScene5_SCENE_H__