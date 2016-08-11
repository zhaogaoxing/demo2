#include "PlayScene.h"
#include "HelloWorldScene.h"
USING_NS_CC;

Scene* PlayScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = PlayScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool PlayScene::init()
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
	bg->setScale(1.5, 1.5);
	bg->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	/*bg->setAnchorPoint(Vec2::ZERO);*/
	this->addChild(bg, 0);

	auto  placeLabel = Label::createWithTTF("Place","fonts/LittleLordFontleroy.ttf",50 );
	auto placeMenu = MenuItemLabel::create(placeLabel,
		CC_CALLBACK_1(PlayScene::OnClikMenu, this));
	placeMenu->setTag(PLACE_TAG);

	auto flipXLabel = Label::createWithTTF("FlipX", "fonts/LittleLordFontleroy.ttf",50);
	auto flipXMenu = MenuItemLabel::create(flipXLabel,
		CC_CALLBACK_1(PlayScene::OnClikMenu, this));
	flipXMenu->setTag(FLIPX_TAG);

	auto flipYLabel = Label::createWithTTF("FlipY","fonts/LittleLordFontleroy.ttf",50);
	auto flipYMenu = MenuItemLabel::create(flipYLabel,
		CC_CALLBACK_1(PlayScene::OnClikMenu, this));
	flipYMenu->setTag(FLIPY_TAG);

	auto hideLabel = Label::createWithTTF("FlipX","fonts/LittleLordFontleroy.ttf",50);
	auto hideMenu = MenuItemLabel::create(hideLabel,
		CC_CALLBACK_1(PlayScene::OnClikMenu, this));
	hideMenu->setTag(HIDE_SHOW_TAG);

	auto toggleLabel = Label::createWithTTF("FlipX","fonts/LittleLordFontleroy.ttf",50);
	auto toggleMenu = MenuItemLabel::create(toggleLabel,
		CC_CALLBACK_1(PlayScene::OnClikMenu, this));
	toggleMenu->setTag(TOGGLE_TAG);

	auto backLabel = Label::createWithTTF("Back", "fonts/LittleLordFontleroy.ttf", 50);
	auto backMenu = MenuItemLabel::create(backLabel,
		CC_CALLBACK_1(PlayScene::OnBack, this));
	backMenu->setTag(BACK_TAG);


	auto mn = Menu::create(placeMenu, flipXMenu, flipYMenu, hideMenu, toggleMenu, backMenu, NULL);
	mn->alignItemsVertically();
	this->addChild(mn);

	return true;
}

void PlayScene::OnClikMenu(Ref * pSender)
{
	MenuItem * nmitem = (MenuItem *)pSender;

	auto sc = Scene::create();
	auto layer = MyAction::create();
	layer->setTag(nmitem->getTag());

	sc->addChild(layer);

	auto reScene = TransitionSlideInR::create(1.0f, sc);
	Director::getInstance()->replaceScene(reScene);
}

void PlayScene::OnBack(Ref * pSender)
{
	auto sc = HelloWorld::createScene();
	auto reScene = TransitionSlideInL::create(1.0f, sc);
	Director::getInstance()->replaceScene(reScene);
}