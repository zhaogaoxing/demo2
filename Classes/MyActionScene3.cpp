#include "MyActionScene3.h"
USING_NS_CC;

Scene* MyAction3::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MyAction3::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MyAction3::init()
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
		CC_CALLBACK_1(MyAction3::backMenu, this));
	backMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(120, 100)));

	auto goMenuItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
		CC_CALLBACK_1(MyAction3::goMenu, this));
	goMenuItem->setPosition(visibleSize.width / 2, 100);
	Menu * mn = Menu::create(backMenuItem, goMenuItem, NULL);
	mn->setPosition(Vec2::ZERO);
	this->addChild(mn);

	return true;
}

void MyAction3::backMenu(Ref * pSender)
{
	auto sc = PlayScene3::createScene();
	auto reScene = TransitionSlideInL::create(1.0f, sc);
	Director::getInstance()->replaceScene(reScene);
}

void MyAction3::goMenu(Ref * pSender)
{
	log("Tag = %i", this->getTag());
	switch (this->getTag()){
	case kSequence:
		this->OnSequence(pSender);
		break;
	case kSpawn:
		this->OnSpawn(pSender);
		break;
	case kRepeate:
		this->OnRepeat(pSender);
		break;
	case kRepeateForever1:
		this->OnRepeatForever(pSender);
		break;
	case kReverse:
		this->OnReverse(pSender);
		break;
	default:
		break;
	}
}

void MyAction3::OnSequence(Ref*pSender)
{
	Size size = Director::getInstance()->getVisibleSize();
	Vec2 p = Vec2(size.width / 2, 200);

	FiniteTimeAction* ac0 = (FiniteTimeAction*)sprite->runAction(Place::create(p));
	FiniteTimeAction* ac1 = (FiniteTimeAction*)sprite->runAction(
		MoveTo::create(2, Vec2(size.width - 130, size.height - 200)));
	FiniteTimeAction* ac2 = (FiniteTimeAction*)sprite->runAction(
		JumpBy::create(2, Vec2(8,8),6,3));
	FiniteTimeAction* ac3 = (FiniteTimeAction*)sprite->runAction(Blink::create(2,3));
	FiniteTimeAction* ac4 = (FiniteTimeAction*)sprite->runAction(
		TintBy::create(0.5,0,255,255));
	sprite->runAction(Sequence::create(ac0, ac1, ac2, ac3, ac4, ac0, NULL));
}

void MyAction3::OnSpawn(Ref*pSender)
{
	Size size = Director::getInstance()->getVisibleSize();
	Vec2 p = Vec2(size.width / 2, 200);

	sprite->setRotation(0);
	sprite->setPosition(p);

	FiniteTimeAction* ac1 = (FiniteTimeAction*)sprite->runAction(
		MoveTo::create(2, Vec2(size.width - 100, size.height - 100)));
	FiniteTimeAction* ac2 = (FiniteTimeAction*)sprite->runAction(RotateTo::create(2, 40));

	sprite->runAction(Spawn::create(ac1, ac2, NULL));
}

void MyAction3::OnRepeat(Ref*pSender)
{
	Size size = Director::getInstance()->getVisibleSize();
	Vec2 p = Vec2(size.width / 2, 200);
	sprite->setRotation(0);
	sprite->setPosition(p);

	FiniteTimeAction* ac1 = (FiniteTimeAction*)sprite->runAction(
		MoveTo::create(2, Vec2(size.width - 100, size.height - 100)));
	FiniteTimeAction* ac2 = (FiniteTimeAction*)sprite->runAction(
		JumpBy::create(2, Vec2(10,10), 20, 5));
	FiniteTimeAction* ac3 = (FiniteTimeAction*)sprite->runAction(
		JumpBy::create(2, Vec2(-10,-10), 20, 3));
	ActionInterval* seq = Sequence::create(ac1, ac2, ac3, NULL);
	sprite->runAction(Repeat::create(seq, 3));
}

void MyAction3::OnRepeatForever(Ref*pSender)
{
	Size size = Director::getInstance()->getVisibleSize();
	Vec2 p = Vec2(size.width / 2, 200);
	sprite->setRotation(0);
	sprite->setPosition(p);

	ccBezierConfig bezier;
	bezier.controlPoint_1 = Vec2(0, size.height / 2);
	bezier.controlPoint_2 = Vec2(10, -size.height / 2);
	bezier.endPosition = Vec2(10, 20);
	FiniteTimeAction* ac1 = (FiniteTimeAction*)sprite->runAction(BezierBy::create(2, bezier));
	FiniteTimeAction* ac2 = (FiniteTimeAction*)sprite->runAction(
		TintBy::create(0.5, 0, 255, 255));
	FiniteTimeAction* ac1Reverse = ((ActionInterval*)ac1)->reverse();
	FiniteTimeAction* ac2Repeat = (FiniteTimeAction*)sprite->runAction(
		Repeat::create((ActionInterval*)ac2, 4));
	FiniteTimeAction* ac3 = (FiniteTimeAction*)sprite->runAction(
		Spawn::create(ac1,ac2Repeat,NULL));
	FiniteTimeAction* ac4 = (FiniteTimeAction*)sprite->runAction(
		Spawn::create(ac1Reverse, ac2Repeat, NULL));
	ActionInterval* seq = Sequence::create(ac3, ac4, NULL);
	sprite->runAction(RepeatForever::create(seq));
}

void MyAction3::OnReverse(Ref*pSender)
{
	Size size = Director::getInstance()->getVisibleSize();
	Vec2 p = Vec2(size.width / 2, 200);
	sprite->setRotation(0);
	sprite->setPosition(p);

	FiniteTimeAction* ac1 = (FiniteTimeAction*)sprite->runAction(
		MoveBy::create(2,Vec2(40,60)));
	Action* ac2 = ac1->reverse();
	ActionInterval* seq = Sequence::create(ac1, ac2, NULL);
	sprite->runAction(Repeat::create(seq, 2));
}