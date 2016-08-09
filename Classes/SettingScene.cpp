#include "SettingScene.h"

USING_NS_CC;

Scene* Setting::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Setting::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool Setting::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	log("Setting init");

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Sprite * bg = Sprite::create("background/prettygirl3.jpg");
	bg->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	/*bg->setAnchorPoint(Vec2::ZERO);*/
	this->addChild(bg, 0);

	//音效
	auto soundOnMenuItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseNormal.png");
	auto soundOffMenuItem = MenuItemImage::create(
		"CloseSelected.png",
		"CloseSelected.png");

	auto soundToggleMenuItem = MenuItemToggle::createWithCallback(
		CC_CALLBACK_1(Setting::menuSoundToggleCallback, this),
		soundOnMenuItem,
		soundOffMenuItem,
		NULL);
	soundToggleMenuItem->setPosition(
		Director::getInstance()->convertToGL(Vec2(800, 100)));

	//返回上一页的按钮
	auto okMenuItem = MenuItemImage::create(
		"fontpage.png",
		"fontpage.png",
		CC_CALLBACK_1(Setting::menuOkCallback, this));

	okMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(512, 400)));

	Menu * mu2 = Menu::create(soundToggleMenuItem, okMenuItem, NULL);
	mu2->setPosition(Vec2::ZERO);
	this->addChild(mu2);

	return true;
}
void Setting::menuSoundToggleCallback(Ref * pSender)
{
	/*MenuItem * item = (MenuItem *)pSender;
	log("Touch", item);*/

	Director::getInstance()->popScene();

}

void Setting::menuOkCallback(Ref * pSender)
{
	/*MenuItem * item = (MenuItem *)pSender;
	log("Touch", item);*/
	Director::getInstance()->popScene();

}


void Setting::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	log("onEnterTransitionDidFinish");
}
void Setting::onEnter()
{
	Layer::onEnter();
	log("onEnter");
}
void Setting::onExit()
{
	Layer::onExit();
	log("onExit");
}
void Setting::onExitTransitionDidStart()
{
	Layer::onExitTransitionDidStart();
	log("onExitTransitionDidStart");
}
void Setting::cleanup()
{
	Layer::cleanup();
	log("cleanup");
}