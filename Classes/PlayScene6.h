#ifndef __PLAYSCENE6_SCENE_H__
#define __PLAYSCENE6_SCENE_H__
//ÌØÐ§
#include "cocos2d.h"
#include "MyActionScene6.h"

enum {
	kFlipX3D = 101,
	kPageTurn3D,
	kLens3D,
	kShaky3D,
	kWaves3D,
	kJumpTiles3D,
	kShakyTiles3D,
	kWavesTiles3D,
	sback
};

class PlayScene6 : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	void OnClikMenu(cocos2d::Ref * pSender);
	void OnBack(cocos2d::Ref * pSender);

	CREATE_FUNC(PlayScene6);
};

#endif // __PLAYSCENE6_SCENE_H__