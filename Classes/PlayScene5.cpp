#include "HelloWorldScene.h"
#include "PlayScene5.h"
#include "MyActionScene5.h"
//动作速度控制
USING_NS_CC;

Scene* PlayScene5::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = PlayScene5::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool PlayScene5::init()
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

	auto Label1 = Label::createWithTTF("CallFunc", "fonts/LittleLordFontleroy.ttf", 50);
	auto Menu1 = MenuItemLabel::create(Label1,
		CC_CALLBACK_1(PlayScene5::OnClikMenu, this));
	Menu1->setTag(func);

	auto Label2 = Label::createWithTTF("CallFuncN", "fonts/LittleLordFontleroy.ttf", 50);
	auto Menu2 = MenuItemLabel::create(Label2,
		CC_CALLBACK_1(PlayScene5::OnClikMenu, this));
	Menu2->setTag(funcN);


	auto backLabel = Label::createWithTTF("Back", "fonts/LittleLordFontleroy.ttf", 50);
	auto backMenu = MenuItemLabel::create(backLabel,
		CC_CALLBACK_1(PlayScene5::OnBack, this));
	backMenu->setTag(fback);


	auto mn = Menu::create(Menu1, Menu2,backMenu, NULL);
	mn->alignItemsVertically();
	this->addChild(mn);

	return true;
}

void PlayScene5::OnClikMenu(Ref * pSender)
{
	MenuItem * nmitem = (MenuItem *)pSender;

	auto sc = Scene::create();
	auto layer = MyAction5::create();
	layer->setTag(nmitem->getTag());

	sc->addChild(layer);

	auto reScene = TransitionSlideInR::create(1.0f, sc);
	Director::getInstance()->replaceScene(reScene);
}

void PlayScene5::OnBack(Ref * pSender)
{
	auto sc = HelloWorld::createScene();
	auto reScene = TransitionSlideInL::create(1.0f, sc);
	Director::getInstance()->replaceScene(reScene);
}
