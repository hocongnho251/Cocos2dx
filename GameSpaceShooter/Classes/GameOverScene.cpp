#include "GameOverScene.h"
#include "ResourceManager.h"
#include "GamePlayScene.h"
USING_NS_CC;

Scene* GameOverScene::createScene()
{
	return GameOverScene::create();
}

bool GameOverScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto screenSize = Director::getInstance()->getVisibleSize();

	auto background3 = ResourceManager::GetInstance()->GetSpriteById(0);
	background3->setPosition(screenSize.height / 2, screenSize.width / 2);
	background3->setScale(2);
	background3->removeFromParent();
	addChild(background3, -1);

	auto buttonPlay = ResourceManager::GetInstance()->GetButtonById(0);
	buttonPlay->setPosition(Vec2(320, 480));
	buttonPlay->addClickEventListener([&](Ref* event) {
		auto gotoNext = CallFunc::create([]() {

			Director::getInstance()->replaceScene(GamePlayScene::creatScene());

		});

		auto sequence = Sequence::create(DelayTime::create(0.1), gotoNext,
			nullptr);

		runAction(sequence);
	});
	addChild(buttonPlay, 1);
	return true;
}