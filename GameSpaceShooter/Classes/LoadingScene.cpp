#include"LoadingScene.h"
#include"GameMenuScene.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;
Scene* LoadingScene::createScene()
{
	return LoadingScene::create();
}

bool LoadingScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto playMusic = SimpleAudioEngine::getInstance();

	playMusic->playBackgroundMusic("mymusic.mp3", true);
	update(3);
//	auto tilemap = TMXTiledMap::create("tilemap.tmx");
//	tilemap->removeFromParent();
//	addChild(tilemap);

	return true;
}

void LoadingScene::update(float deltaTime)
{
	auto screenSize = Director::getInstance()->getVisibleSize();

	auto background = ResourceManager::GetInstance()->GetSpriteById(0);
	background->setPosition(screenSize.height / 2,screenSize.width/2);
	background->setScale(2);
	background->removeFromParent();
	addChild(background, -1);


	auto loading = ResourceManager::GetInstance()->GetSpriteById(5);
	loading->setPosition(Vec2(320, 480));
	loading->removeFromParent();
	addChild(loading, 0);

	auto progress = ResourceManager::GetInstance()->GetSpriteById(6);
	progress->setPosition(Vec2(240, 480));
	progress->setAnchorPoint(Vec2(0, 0.5));
	progress->setScaleX(0);
	progress->removeFromParent();
	auto scaleTo = ScaleTo::create(deltaTime, 1.0f);
	addChild(progress, 0);
	progress->runAction(scaleTo);

	auto gotoNext = CallFunc::create([]() {

		Director::getInstance()->replaceScene(GameMenuScene::createScene());

	});

	auto sequence = Sequence::create(DelayTime::create(3), gotoNext,
		nullptr);

	runAction(sequence);
	
}
