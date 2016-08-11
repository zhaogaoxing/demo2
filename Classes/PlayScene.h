#ifndef __PlayScene_SCENE_H__
#define __PlayScene_SCENE_H__

#include "cocos2d.h"
#include "MyActionScene.h"

typedef enum
{
	PLACE_TAG = 102
	, FLIPX_TAG
	, FLIPY_TAG
	, HIDE_SHOW_TAG
	, TOGGLE_TAG
	, BACK_TAG
}ActionTypes;

class PlayScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void OnClikMenu(cocos2d::Ref * pSender);
	void OnBack(cocos2d::Ref * pSender);

	CREATE_FUNC(PlayScene);
};

#endif // __PlayScene_SCENE_H__