#include "MyActionScene2.h"
USING_NS_CC;

Scene* MyAction2::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MyAction2::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MyAction2::init()
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

	sprite = Sprite::create("catong.png");
	sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	sprite->setScale(1, 1);
	this->addChild(sprite);

	auto backMenuItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
		CC_CALLBACK_1(MyAction2::backMenu2, this));
	backMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(120, 100)));

	auto goMenuItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
		CC_CALLBACK_1(MyAction2::goMenu2, this));
	goMenuItem->setPosition(visibleSize.width / 2, 100);
	Menu * mn = Menu::create(backMenuItem, goMenuItem, NULL);
	mn->setPosition(Vec2::ZERO);
	this->addChild(mn);

	return true;
}

void MyAction2::backMenu2(Ref * pSender)
{
	auto sc = PlayScene2::createScene();
	auto reScene = TransitionSlideInL::create(1.0f, sc);
	Director::getInstance()->replaceScene(reScene);
}

void MyAction2::goMenu2(Ref * pSender)
{
	log("Tag = % i", this->getTag());
	Size size = Director::getInstance()->getVisibleSize();
	Vec2 p = Vec2(CCRANDOM_0_1() * size.width, CCRANDOM_0_1() * size.height);
	ccBezierConfig bezier;
	switch (this->getTag()){
	case kMoveTo:
		sprite->runAction(MoveTo::create(2,Vec2(size.width - 50,size.height - 50)));
		break;
	case kMoveBy:
		sprite->runAction(MoveBy::create(2,Vec2(-50,-50)));
		break;
	case kJumpTo:
		sprite->runAction(JumpTo::create(2,Vec2(150,150),30,5));
		break;
	case kJumpBy:
		sprite->runAction(JumpBy::create(2, Vec2(100, 100), 30, 5));
		break;
	case kBezierBy:
		bezier.controlPoint_1 = Vec2(0, size.height / 2);
		bezier.controlPoint_2 = Vec2(300, -size.height / 2);
		bezier.endPosition = Vec2(100, 100);
		sprite->runAction(BezierBy::create(3, bezier));
		break;
	case kScaleBy:
		sprite->runAction(ScaleBy::create(2, 0.5));
		break;
	case kScaleTo:
		sprite->runAction(ScaleTo::create(2, 4));
		break;
	case kRotateTo:
		sprite->runAction(RotateTo::create(2, 180));
		break;
	case kRotateBy:
		sprite->runAction(RotateBy::create(2,-180));
		break;
	case kBlink:
		sprite->runAction(Blink::create(3, 5));
		break;
	case kTintTo:
		sprite->runAction(TintTo::create(2,255,0,0));
		break;
	case kTintBy:
		sprite->runAction(TintBy::create(0.5,0,255,255));
		break;
	case kFadeTo:
		sprite->runAction(FadeTo::create(1,80));
		break;
	case kFadeIn:
		sprite->runAction(FadeIn::create(1));
		break;
	case kFadeOut:
		sprite->runAction(FadeOut::create(1));
		break;
	default:
		break;
	}
}