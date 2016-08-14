#include "MyActionScene4.h"
#include "PlayScene4.h"
USING_NS_CC;

Scene* MyAction4::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MyAction4::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MyAction4::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Sprite * bg = Sprite::create("girls/prettygirl6.jpg");
	bg->setScale(0.8, 0.8);
	bg->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	/*bg->setAnchorPoint(Vec2::ZERO);*/
	this->addChild(bg, 0);

	sprite = Sprite::create("catong2.png");
	sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	sprite->setScale(1, 1);
	this->addChild(sprite);

	auto backMenuItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
		CC_CALLBACK_1(MyAction4::backMenu, this));
	backMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(120, 100)));

	auto goMenuItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
		CC_CALLBACK_1(MyAction4::goMenu, this));
	goMenuItem->setPosition(visibleSize.width / 2, 100);
	Menu * mn = Menu::create(backMenuItem, goMenuItem, NULL);
	mn->setPosition(Vec2::ZERO);
	this->addChild(mn);

	return true;
}

void MyAction4::backMenu(Ref * pSender)
{
	auto sc = PlayScene4::createScene();
	auto reScene = TransitionSlideInL::create(1.0f, sc);
	Director::getInstance()->replaceScene(reScene);
}

void MyAction4::goMenu(Ref * pSender)
{
	log("Tag = %i", this->getTag());
	FiniteTimeAction * ac1 = (FiniteTimeAction*)MoveBy::create(2, Vec2(200, 0));
	FiniteTimeAction * ac2 = ((FiniteTimeAction*)ac1)->reverse();

	ActionInterval * ac = Sequence::create(ac1, ac2, NULL);
	switch (this->getTag()){
	case kEaseIn:
		sprite->runAction(EaseIn::create(ac, 3));
		break;
	case kEaseOut:
		sprite->runAction(EaseOut::create(ac, 3));
		break;
	case kEaseInOut:
		sprite->runAction(EaseInOut::create(ac, 3));
		break;
	case kEaseSineIn:
		sprite->runAction(EaseSineIn::create(ac));
		break;
	case kEaseSineOut:
		sprite->runAction(EaseSineOut::create(ac));
		break;
	case kEaseSineInOut:
		sprite->runAction(EaseSineInOut::create(ac));
		break;
	case kEaseExponentialIn:
		sprite->runAction(EaseExponentialIn::create(ac));
		break;
	case kEaseExponentialOut:
		sprite->runAction(EaseExponentialOut::create(ac));
		break;
	case kEaseExponentialInOut:
		sprite->runAction(EaseExponentialInOut::create(ac));
		break;
	case kSpeed:
		sprite->runAction(Speed::create(ac,(CCRANDOM_0_1() * 5)));
		break;
	}
}

