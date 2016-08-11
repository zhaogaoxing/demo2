#include "PlayScene2.h"
#include "PlayScene.h"
#include "MyActionScene2.h"
USING_NS_CC;

Scene* PlayScene2::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = PlayScene2::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool PlayScene2::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Sprite * bg = Sprite::create("background/prettygirl.jpg");
	bg->setScale(1, 1);
	bg->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	/*bg->setAnchorPoint(Vec2::ZERO);*/
	this->addChild(bg, 0);

	auto  pItmLabel1 = Label::createWithTTF("MoveTo", "fonts/LittleLordFontleroy.ttf", 50);
	auto pItmMenu1 = MenuItemLabel::create(pItmLabel1,
		CC_CALLBACK_1(PlayScene2::OnClikMenu2, this));
	pItmMenu1->setTag(kMoveTo);

	auto pItmLabel2 = Label::createWithTTF("MoveBy", "fonts/LittleLordFontleroy.ttf", 50);
	auto pItmMenu2 = MenuItemLabel::create(pItmLabel2,
		CC_CALLBACK_1(PlayScene2::OnClikMenu2, this));
	pItmMenu2->setTag(kMoveBy);

	auto pItmLabel3 = Label::createWithTTF("JumpTo", "fonts/LittleLordFontleroy.ttf", 50);
	auto pItmMenu3 = MenuItemLabel::create(pItmLabel3,
		CC_CALLBACK_1(PlayScene2::OnClikMenu2, this));
	pItmMenu3->setTag(kJumpTo);

	auto pItmLabel4 = Label::createWithTTF("JumpBy", "fonts/LittleLordFontleroy.ttf", 50);
	auto pItmMenu4 = MenuItemLabel::create(pItmLabel4,
		CC_CALLBACK_1(PlayScene2::OnClikMenu2, this));
	pItmMenu4->setTag(kJumpBy);

	auto pItmLabel5 = Label::createWithTTF("BezierBy", "fonts/LittleLordFontleroy.ttf", 50);
	auto pItmMenu5 = MenuItemLabel::create(pItmLabel5,
		CC_CALLBACK_1(PlayScene2::OnClikMenu2, this));
	pItmMenu5->setTag(kBezierBy);

	auto pItmLabel6 = Label::createWithTTF("ScaleTo", "fonts/LittleLordFontleroy.ttf", 50);
	auto pItmMenu6 = MenuItemLabel::create(pItmLabel6,
		CC_CALLBACK_1(PlayScene2::OnClikMenu2, this));
	pItmMenu6->setTag(kScaleTo);

	auto pItmLabel7 = Label::createWithTTF("ScaleBy", "fonts/LittleLordFontleroy.ttf", 50);
	auto pItmMenu7 = MenuItemLabel::create(pItmLabel7,
		CC_CALLBACK_1(PlayScene2::OnClikMenu2, this));
	pItmMenu5->setTag(kScaleBy);

	auto pItmLabel8 = Label::createWithTTF("RotateTo", "fonts/LittleLordFontleroy.ttf", 50);
	auto pItmMenu8 = MenuItemLabel::create(pItmLabel8,
		CC_CALLBACK_1(PlayScene2::OnClikMenu2, this));
	pItmMenu5->setTag(kRotateTo);

	auto pItmLabel9 = Label::createWithTTF("RototaBy", "fonts/LittleLordFontleroy.ttf", 50);
	auto pItmMenu9 = MenuItemLabel::create(pItmLabel9,
		CC_CALLBACK_1(PlayScene2::OnClikMenu2, this));
	pItmMenu9->setTag(kRotateBy);

	auto pItmLabel10 = Label::createWithTTF("Blink", "fonts/LittleLordFontleroy.ttf", 50);
	auto pItmMenu10 = MenuItemLabel::create(pItmLabel10,
		CC_CALLBACK_1(PlayScene2::OnClikMenu2, this));
	pItmMenu10->setTag(kBlink);

	auto pItmLabel11 = Label::createWithTTF("TintTo", "fonts/LittleLordFontleroy.ttf", 50);
	auto pItmMenu11 = MenuItemLabel::create(pItmLabel11,
		CC_CALLBACK_1(PlayScene2::OnClikMenu2, this));
	pItmMenu11->setTag(kTintTo);

	auto pItmLabel12 = Label::createWithTTF("TintBy", "fonts/LittleLordFontleroy.ttf", 50);
	auto pItmMenu12 = MenuItemLabel::create(pItmLabel12,
		CC_CALLBACK_1(PlayScene2::OnClikMenu2, this));
	pItmMenu12->setTag(kTintBy);

	auto pItmLabel13 = Label::createWithTTF("FadeTo", "fonts/LittleLordFontleroy.ttf", 50);
	auto pItmMenu13 = MenuItemLabel::create(pItmLabel13,
		CC_CALLBACK_1(PlayScene2::OnClikMenu2, this));
	pItmMenu13->setTag(kFadeTo);

	auto pItmLabel14 = Label::createWithTTF("FadeIn", "fonts/LittleLordFontleroy.ttf", 50);
	auto pItmMenu14 = MenuItemLabel::create(pItmLabel14,
		CC_CALLBACK_1(PlayScene2::OnClikMenu2, this));
	pItmMenu14->setTag(kFadeIn);

	auto pItmLabel15 = Label::createWithTTF("FadeOut", "fonts/LittleLordFontleroy.ttf", 50);
	auto pItmMenu15 = MenuItemLabel::create(pItmLabel15,
		CC_CALLBACK_1(PlayScene2::OnClikMenu2, this));
	pItmMenu15->setTag(kFadeOut);

	auto pItmLabel16 = Label::createWithTTF("Back", "fonts/LittleLordFontleroy.ttf", 50);
	auto pItmMenu16 = MenuItemLabel::create(pItmLabel16,
		CC_CALLBACK_1(PlayScene2::OnBack2, this));
	pItmMenu16->setTag(kBack);


	auto mn = Menu::create(pItmMenu1,pItmMenu2,pItmMenu3,pItmMenu4,pItmMenu5,
		pItmMenu6,pItmMenu7,pItmMenu8,pItmMenu9,
		pItmMenu10,pItmMenu11,pItmMenu12,
		pItmMenu13,pItmMenu14,pItmMenu15,
		pItmMenu16, NULL);
	mn->alignItemsInColumns(3,3,3,3,3,1,NULL);
	this->addChild(mn);

	return true;
}

void PlayScene2::OnClikMenu2(Ref * pSender)
{
	MenuItem * nmitem2= (MenuItem *)pSender;

	auto sc = Scene::create();
	auto layer = MyAction2::create();
	layer->setTag(nmitem2->getTag());

	sc->addChild(layer);

	auto reScene = TransitionSlideInR::create(1.0f, sc);
	Director::getInstance()->replaceScene(reScene);
}

void PlayScene2::OnBack2(Ref * pSender)
{
	auto sc = PlayScene::createScene();
	auto reScene = TransitionSlideInL::create(1.0f, sc);
	Director::getInstance()->replaceScene(reScene);
}