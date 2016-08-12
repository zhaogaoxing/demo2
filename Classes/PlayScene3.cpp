
#include "HelloWorldScene.h"
#include "PlayScene3.h"

USING_NS_CC;

Scene* PlayScene3::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = PlayScene3::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool PlayScene3::init()
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

	auto SequenceLabel = Label::createWithTTF("Sequence", "fonts/LittleLordFontleroy.ttf", 50);
	auto SequenceMenu = MenuItemLabel::create(SequenceLabel,
		CC_CALLBACK_1(PlayScene3::OnClikMenu, this));
	SequenceMenu->setTag(kSequence);

	auto SpawnLabel = Label::createWithTTF("Spawn", "fonts/LittleLordFontleroy.ttf", 50);
	auto SpawnMenu = MenuItemLabel::create(SpawnLabel,
		CC_CALLBACK_1(PlayScene3::OnClikMenu, this));
	SpawnMenu->setTag(kSpawn);

	auto RepeateLabel = Label::createWithTTF("Repeate", "fonts/LittleLordFontleroy.ttf", 50);
	auto RepeateMenu = MenuItemLabel::create(RepeateLabel,
		CC_CALLBACK_1(PlayScene3::OnClikMenu, this));
	RepeateMenu->setTag(kRepeate);

	auto RepeateForever1Label = Label::createWithTTF("RepeateForever1", "fonts/LittleLordFontleroy.ttf", 50);
	auto RepeateForever1Menu = MenuItemLabel::create(RepeateForever1Label,
		CC_CALLBACK_1(PlayScene3::OnClikMenu, this));
	RepeateForever1Menu->setTag(kRepeateForever1);

	auto ReverseLabel = Label::createWithTTF("Reverse", "fonts/LittleLordFontleroy.ttf", 50);
	auto ReverseMenu = MenuItemLabel::create(ReverseLabel,
		CC_CALLBACK_1(PlayScene3::OnBack, this));
	ReverseMenu->setTag(kReverse);


	auto backLabel = Label::createWithTTF("Back", "fonts/LittleLordFontleroy.ttf", 50);
	auto backMenu = MenuItemLabel::create(backLabel,
		CC_CALLBACK_1(PlayScene3::OnBack, this));
	backMenu->setTag(back);


	auto mn = Menu::create(SequenceMenu, SpawnMenu, RepeateMenu, RepeateForever1Menu, ReverseMenu, backMenu, NULL);
	mn->alignItemsVertically();
	this->addChild(mn);

	return true;
}

void PlayScene3::OnClikMenu(Ref * pSender)
{
	MenuItem * nmitem = (MenuItem *)pSender;

	auto sc = Scene::create();
	auto layer = MyAction3::create();
	layer->setTag(nmitem->getTag());

	sc->addChild(layer);

	auto reScene = TransitionSlideInR::create(1.0f, sc);
	Director::getInstance()->replaceScene(reScene);
}

void PlayScene3::OnBack(Ref * pSender)
{
	auto sc = HelloWorld::createScene();
	auto reScene = TransitionSlideInL::create(1.0f, sc);
	Director::getInstance()->replaceScene(reScene);
}
