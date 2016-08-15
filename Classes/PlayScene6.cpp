#include "HelloWorldScene.h"
#include "PlayScene6.h"
#include "MyActionScene6.h"
//ÌØÐ§
USING_NS_CC;

Scene* PlayScene6::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = PlayScene6::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool PlayScene6::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Sprite * bg = Sprite::create("girls/prettygirl5.jpg");
	//bg->setScale(1.5, 1.5);
	bg->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	/*bg->setAnchorPoint(Vec2::ZERO);*/
	this->addChild(bg, 0);

	auto Label1 = Label::createWithTTF("FlipX3D", "fonts/LittleLordFontleroy.ttf", 50);
	auto Menu1 = MenuItemLabel::create(Label1,
		CC_CALLBACK_1(PlayScene6::OnClikMenu, this));
	Menu1->setTag(kFlipX3D);

	auto Label2 = Label::createWithTTF("PageTurn3D", "fonts/LittleLordFontleroy.ttf", 50);
	auto Menu2 = MenuItemLabel::create(Label2,
		CC_CALLBACK_1(PlayScene6::OnClikMenu, this));
	Menu2->setTag(kPageTurn3D);

	auto Label3 = Label::createWithTTF("Lens3D", "fonts/LittleLordFontleroy.ttf", 50);
	auto Menu3 = MenuItemLabel::create(Label3,
		CC_CALLBACK_1(PlayScene6::OnClikMenu, this));
	Menu3->setTag(kLens3D);

	auto Label4 = Label::createWithTTF("Shaky3Ds", "fonts/LittleLordFontleroy.ttf", 50);
	auto Menu4 = MenuItemLabel::create(Label4,
		CC_CALLBACK_1(PlayScene6::OnClikMenu, this));
	Menu4->setTag(kShaky3D);

	auto Label5 = Label::createWithTTF("Waves3D", "fonts/LittleLordFontleroy.ttf", 50);
	auto Menu5 = MenuItemLabel::create(Label5,
		CC_CALLBACK_1(PlayScene6::OnClikMenu, this));
	Menu5->setTag(kWaves3D);

	auto Label6 = Label::createWithTTF("JumpTiles3D", "fonts/LittleLordFontleroy.ttf", 50);
	auto Menu6 = MenuItemLabel::create(Label6,
		CC_CALLBACK_1(PlayScene6::OnClikMenu, this));
	Menu6->setTag(kJumpTiles3D);

	auto Label7 = Label::createWithTTF("ShakyTiles3D", "fonts/LittleLordFontleroy.ttf", 50);
	auto Menu7 = MenuItemLabel::create(Label7,
		CC_CALLBACK_1(PlayScene6::OnClikMenu, this));
	Menu7->setTag(kShakyTiles3D);

	auto Label8= Label::createWithTTF("WavesTiles3D", "fonts/LittleLordFontleroy.ttf", 50);
	auto Menu8 = MenuItemLabel::create(Label8,
		CC_CALLBACK_1(PlayScene6::OnClikMenu, this));
	Menu8->setTag(kWavesTiles3D);

	auto backLabel = Label::createWithTTF("Back", "fonts/LittleLordFontleroy.ttf", 50);
	auto backMenu = MenuItemLabel::create(backLabel,
		CC_CALLBACK_1(PlayScene6::OnBack, this));
	backMenu->setTag(sback);


	auto mn = Menu::create(Menu1, Menu2, Menu3,Menu4,Menu5,Menu6,Menu7,Menu8,backMenu, NULL);
	mn->alignItemsInColumns(2, 2, 2, 2, 1, NULL);
	this->addChild(mn);

	return true;
}

void PlayScene6::OnClikMenu(Ref * pSender)
{
	MenuItem * nmitem = (MenuItem *)pSender;

	auto sc = Scene::create();
	auto layer = MyAction6::create();
	layer->setTag(nmitem->getTag());

	sc->addChild(layer);

	auto reScene = TransitionSlideInR::create(1.0f, sc);
	Director::getInstance()->replaceScene(reScene);
}

void PlayScene6::OnBack(Ref * pSender)
{
	auto sc = HelloWorld::createScene();
	auto reScene = TransitionSlideInL::create(1.0f, sc);
	Director::getInstance()->replaceScene(reScene);
}