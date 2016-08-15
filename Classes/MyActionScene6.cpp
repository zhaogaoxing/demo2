#include "MyActionScene6.h"
#include "PlayScene6.h"
USING_NS_CC;

Scene* MyAction6::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MyAction6::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MyAction6::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	gridNodeTarget = NodeGrid::create();
	addChild(gridNodeTarget);


	Sprite * bg = Sprite::create("girls/prettygirl6.jpg");
	bg->setScale(0.8, 0.8);
	bg->setPosition(Vec2(visibleSize.width / 2,
		visibleSize.height / 2));
	/*bg->setAnchorPoint(Vec2::ZERO);*/
	gridNodeTarget->addChild(bg);

	sprite = Sprite::create("catong2.png");
	sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	sprite->setScale(1, 1);
	this->addChild(sprite);

	auto backMenuItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
		CC_CALLBACK_1(MyAction6::backMenu, this));
	backMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(120, 100)));

	auto goMenuItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
		CC_CALLBACK_1(MyAction6::goMenu, this));
	goMenuItem->setPosition(visibleSize.width / 2, 100);
	Menu * mn = Menu::create(backMenuItem, goMenuItem, NULL);
	mn->setPosition(Vec2::ZERO);
	this->addChild(mn);

	return true;
}

void MyAction6::backMenu(Ref * pSender)
{
	auto sc = PlayScene6::createScene();
	auto reScene = TransitionSlideInL::create(1.0f, sc);
	Director::getInstance()->replaceScene(reScene);
}

void MyAction6::goMenu(Ref * pSender)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	log("Tag = %i", this->getTag());

	switch (this->getTag()){
	case kFlipX3D:
		gridNodeTarget->runAction(FlipX3D::create(3.0f));
		break;
	case kPageTurn3D:
		gridNodeTarget->runAction(PageTurn3D::create(3.0f, Size(15, 10)));
		break;
	case kLens3D:
		gridNodeTarget->runAction(Lens3D::create(3.0f, Size(15, 10),
			Vec2(visibleSize.width / 2, visibleSize.height / 2), 240));
		break;
	case kShaky3D:
		gridNodeTarget->runAction(Shaky3D::create(3.0f, Size(15, 10), 5, false));
		break;
	case kWaves3D:
		gridNodeTarget->runAction(Waves3D::create(3.0f, Size(15, 10), 5, 40));
		break;
	case kJumpTiles3D:
		gridNodeTarget->runAction(JumpTiles3D::create(3.0f, Size(15, 10), 2, 30));
		break;
	case kShakyTiles3D:
		gridNodeTarget->runAction(ShakyTiles3D::create(3.0f, Size(16, 12), 5, false));
		break;
	case kWavesTiles3D:
		gridNodeTarget->runAction(WavesTiles3D::create(3.0f, Size(15, 10), 4, 120));
		break;
	}
}

