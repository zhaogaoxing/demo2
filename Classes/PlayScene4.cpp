#include "HelloWorldScene.h"
#include "PlayScene4.h"
#include "MyActionScene4.h"
//动作速度控制
USING_NS_CC;

Scene* PlayScene4::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = PlayScene4::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool PlayScene4::init()
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

	auto Label1 = Label::createWithTTF("EaseIn", "fonts/LittleLordFontleroy.ttf", 50);
	auto Menu1 = MenuItemLabel::create(Label1,
		CC_CALLBACK_1(PlayScene4::OnClikMenu, this));
	Menu1->setTag(kEaseIn);

	auto Label2 = Label::createWithTTF("EaseOut", "fonts/LittleLordFontleroy.ttf", 50);
	auto Menu2 = MenuItemLabel::create(Label2,
		CC_CALLBACK_1(PlayScene4::OnClikMenu, this));
	Menu2->setTag(kEaseOut);

	auto Label3 = Label::createWithTTF("EaseInOut", "fonts/LittleLordFontleroy.ttf", 50);
	auto Menu3 = MenuItemLabel::create(Label3,
		CC_CALLBACK_1(PlayScene4::OnClikMenu, this));
	Menu3->setTag(kEaseInOut);

	auto Label4 = Label::createWithTTF("EaseSineIn", "fonts/LittleLordFontleroy.ttf", 50);
	auto Menu4 = MenuItemLabel::create(Label4,
		CC_CALLBACK_1(PlayScene4::OnClikMenu, this));
	Menu4->setTag(kEaseSineIn);

	auto Label5 = Label::createWithTTF("EaseSineOut", "fonts/LittleLordFontleroy.ttf", 50);
	auto Menu5 = MenuItemLabel::create(Label5,
		CC_CALLBACK_1(PlayScene4::OnClikMenu, this));
	Menu5->setTag(kEaseSineOut);

	auto Label6 = Label::createWithTTF("EaseSineInOut", "fonts/LittleLordFontleroy.ttf", 50);
	auto Menu6 = MenuItemLabel::create(Label6,
		CC_CALLBACK_1(PlayScene4::OnClikMenu, this));
	Menu6->setTag(kEaseSineInOut);

	auto Label7 = Label::createWithTTF("EaseExponentialIn", "fonts/LittleLordFontleroy.ttf", 50);
	auto Menu7 = MenuItemLabel::create(Label7,
		CC_CALLBACK_1(PlayScene4::OnClikMenu, this));
	Menu7->setTag(kEaseExponentialIn);

	auto Label8 = Label::createWithTTF("EaseExponentialOut", "fonts/LittleLordFontleroy.ttf", 50);
	auto Menu8 = MenuItemLabel::create(Label8,
		CC_CALLBACK_1(PlayScene4::OnClikMenu, this));
	Menu8->setTag(kEaseExponentialOut);

	auto Label9 = Label::createWithTTF("EaseExponentialInOut", "fonts/LittleLordFontleroy.ttf", 50);
	auto Menu9 = MenuItemLabel::create(Label9,
		CC_CALLBACK_1(PlayScene4::OnClikMenu, this));
	Menu9->setTag(kEaseExponentialInOut);

	auto Label10 = Label::createWithTTF("Speed", "fonts/LittleLordFontleroy.ttf", 50);
	auto Menu10 = MenuItemLabel::create(Label10,
		CC_CALLBACK_1(PlayScene4::OnClikMenu, this));
	Menu10->setTag(kSpeed);

	auto backLabel = Label::createWithTTF("Back", "fonts/LittleLordFontleroy.ttf", 50);
	auto backMenu = MenuItemLabel::create(backLabel,
		CC_CALLBACK_1(PlayScene4::OnBack, this));
	backMenu->setTag(kback);


	auto mn = Menu::create(Menu1, Menu2, Menu3,Menu4,Menu5,Menu6,Menu7,Menu8,Menu9,Menu10,backMenu, NULL);
	mn->alignItemsInColumns(2, 2, 2, 2, 2, 1,NULL);
	this->addChild(mn);

	return true;
}

void PlayScene4::OnClikMenu(Ref * pSender)
{
	MenuItem * nmitem = (MenuItem *)pSender;

	auto sc = Scene::create();
	auto layer = MyAction4::create();
	layer->setTag(nmitem->getTag());

	sc->addChild(layer);

	auto reScene = TransitionSlideInR::create(1.0f, sc);
	Director::getInstance()->replaceScene(reScene);
}

void PlayScene4::OnBack(Ref * pSender)
{
	auto sc = HelloWorld::createScene();
	auto reScene = TransitionSlideInL::create(1.0f, sc);
	Director::getInstance()->replaceScene(reScene);
}
