#include"LoadingScene.h"
#include"GameMenuScene.h"

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


	update(3);
	scheduleUpdate();
	auto gotoNext = CallFunc::create([]() {

		Director::getInstance()->replaceScene(GameMenuScene::createScene());

	});

	auto sequence = Sequence::create(DelayTime::create(3), gotoNext,
		nullptr);

	runAction(sequence);
	return true;
}

void LoadingScene::update(float deltaTime)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	auto loading = ResourceManager::GetInstance()->GetSpriteById(5);
	loading->setPosition(Vec2(320  , 480) );
	loading->setScale(2);
	loading->removeFromParent();
	addChild(loading, 0);
	auto progress = ResourceManager::GetInstance()->GetSpriteById(6);
	progress->setPosition(Vec2(180,480) );
	progress->setScale(2);
	progress->setScaleX(0.2);
	progress->removeFromParent();
	addChild(progress, 0);
	

}
