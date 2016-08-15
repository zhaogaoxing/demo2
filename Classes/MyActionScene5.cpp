#include "MyActionScene5.h"
#include "PlayScene5.h"
USING_NS_CC;

Scene* MyAction5::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MyAction5::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MyAction5::init()
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
		CC_CALLBACK_1(MyAction5::backMenu, this));
	backMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(120, 100)));

	auto goMenuItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
		CC_CALLBACK_1(MyAction5::goMenu, this));
	goMenuItem->setPosition(visibleSize.width / 2, 100);
	Menu * mn = Menu::create(backMenuItem, goMenuItem, NULL);
	mn->setPosition(Vec2::ZERO);
	this->addChild(mn);

	return true;
}

void MyAction5::backMenu(Ref * pSender)
{
	auto sc = PlayScene5::createScene();
	auto reScene = TransitionSlideInL::create(1.0f, sc);
	Director::getInstance()->replaceScene(reScene);
}

void MyAction5::goMenu(Ref * pSender)
{
	log("Tag = %i", this->getTag());
	switch (this->getTag()){
	case func:
		this->OnCallFunc(pSender);
		break;
	case funcN:
		this->OnCallFuncN(pSender);
		break;
	}
}

void MyAction5::OnCallFunc(Ref * pSender)
{
	FiniteTimeAction * ac1 = MoveBy::create(2, Vec2(100, 100));
	FiniteTimeAction * ac2 = ((FiniteTimeAction*)ac1)->reverse();

	FiniteTimeAction * acf = CallFunc::create(CC_CALLBACK_0(MyAction5::CallBack1, this));

	ActionInterval * seq = Sequence::create(ac1, acf, ac2, NULL);
	sprite->runAction(Sequence::create(seq, NULL));
}

void MyAction5::CallBack1()
{
	sprite->runAction(TintBy::create(0.5, 255, 0, 255));
}

void MyAction5::OnCallFuncN(Ref * pSender)
{
	FiniteTimeAction * ac1 = MoveBy::create(2, Vec2(100, 100));
	FiniteTimeAction * ac2 = ((FiniteTimeAction*)ac1)->reverse();

	FiniteTimeAction * acf = CallFuncN::create(CC_CALLBACK_1(MyAction5::CallBack2, this));

	ActionInterval * seq = Sequence::create(ac1, acf, ac2, NULL);
	sprite->runAction(Sequence::create(seq, NULL));
}

void MyAction5::CallBack2(Ref * pSender)
{
	Sprite * sp = (Sprite*)pSender;
	sp->runAction(TintBy::create(1, 255, 0, 255));
}