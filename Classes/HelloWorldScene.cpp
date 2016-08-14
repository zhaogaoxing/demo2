#include "HelloWorldScene.h"
#include "PlayScene3.h"
#include "PlayScene4.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
	log("HelloWorld init");

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Sprite * bg = Sprite::create("background/backgirl2.jpg");
	bg->setScale(1.6, 1.6);
	bg->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	/*bg->setAnchorPoint(Vec2::ZERO);*/
	this->addChild(bg,0);


	//开始精灵
	Sprite * startSpriteNormal = Sprite::create("Play.png");
	Sprite * startSpriteSelected = Sprite::create("Play_on.png");

	MenuItemSprite * startMenuItem = MenuItemSprite:: create(startSpriteNormal,
		startSpriteSelected,
		CC_CALLBACK_1(HelloWorld::menuItemStartCallback, this));
	startMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(visibleSize.width / 2, visibleSize.height / 2)));
	//设置图片菜单项
	MenuItemImage * settingMenuItem = MenuItemImage::create(
		"Options.png",
		"Options_on.png",
		CC_CALLBACK_1(HelloWorld::menuItemSettingCallback, this));
	settingMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(visibleSize.width / 2 - 100, visibleSize.height / 2 +100)));
	//商店图片菜单项
	MenuItemImage * helpMenuItem = MenuItemImage::create(
		"Store.png",
		"Store_on.png",
		CC_CALLBACK_1(HelloWorld::menuItemHelpCallback, this));
	helpMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(visibleSize.width / 2 + 100, visibleSize.height / 2 + 100)));
	
	//动作速度控制
	/*MenuItemFont::setFontName("Times New Roman");
	MenuItemFont::setFontSize(40);*/
	//MenuItemFont::setColor(Color3B(100, 100, 100));
	MenuItemImage * itemSpeed = MenuItemImage::create(
		"Store.png",
		"Store_on.png",
		CC_CALLBACK_1(HelloWorld::menuItemSpeedCallback, this));
	itemSpeed->setPosition(Director::getInstance()->convertToGL(Vec2(visibleSize.width / 2 - 100, visibleSize.height / 2 + 200)));

	Menu * mu = Menu::create(startMenuItem, settingMenuItem, helpMenuItem,itemSpeed, NULL);
	mu->setPosition(Vec2::ZERO);
	this->addChild(mu);
	//开关菜单

	//文本类型的开关
	/*MenuItemFont::setFontSize(80);
	auto toggleMenuItem = MenuItemToggle::createWithCallback(
		CC_CALLBACK_1(HelloWorld::menuItem1Callback, this),
		MenuItemFont::create("on"),
		MenuItemFont::create("off"),
		NULL);
	toggleMenuItem->setColor(Color3B(255, 255, 255));
	toggleMenuItem->setPosition(
		Director::getInstance()->convertToGL(Vec2(512, 400)));
*/

	
	////sprite 精灵的创建
	//auto prettygirl = Sprite::create("prettygirl.jpg", Rect(800, 200, 200, 300));
	//prettygirl->setPosition(Vec2(150, 200));
	//this->addChild(prettygirl, 0);

	//Texture2D* cache = Director::getInstance()->getTextureCache()->addImage("prettygirl.jpg");
	//auto prettygirl2 = Sprite::create();
	//prettygirl2->setTexture(cache);
	//prettygirl2->setTextureRect(Rect(800, 200, 200, 300));
	//prettygirl2->setPosition(Vec2(850, 200));
	//this->addChild(prettygirl2, 0);


    return true;
}

void HelloWorld::menuItemSettingCallback(Ref * pSender)
{
	auto sc = Setting::createScene();
	//Director:;getInstance()->replaceScence(sc);
	auto reScene = TransitionFadeTR::create(1.0f, sc);
	Director::getInstance()->pushScene(reScene);

}

void HelloWorld::menuItemStartCallback(Ref * pSender)
{
	auto ss = PlayScene::createScene();
	auto reScene = TransitionFadeTR::create(1.0f, ss);
	Director::getInstance()->pushScene(reScene);

}
void HelloWorld::menuItemHelpCallback(Ref * pSender)
{
	auto sd = PlayScene3::createScene();
	auto reScene = TransitionFadeTR::create(1.0f, sd);
	Director::getInstance()->pushScene(reScene);
}

void HelloWorld::menuItemSpeedCallback(Ref * pSender)
{
	auto speed = PlayScene4::createScene();
	auto reScene = TransitionFadeTR::create(1.0f, speed);
	Director::getInstance()->pushScene(reScene);
}



void HelloWorld::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	log("onEnterTransitionDidFinish");
}
void HelloWorld::onEnter()
{
	Layer::onEnter();
	log("onEnter");
}
void HelloWorld::onExit()
{
	Layer::onExit();
	log("onExit");
}
void HelloWorld::onExitTransitionDidStart()
{
	Layer::onExitTransitionDidStart();
	log("onExitTransitionDidStart");
}
void HelloWorld::cleanup()
{
	Layer::cleanup();
	log("cleanup");
}
