#include"GameMenuScene.h"
#include"ui/CocosGUI.h"
#include"LoadingScene.h"
#include"GamePlayScene.h"


Scene* GameMenuScene::createScene()
{
	return GameMenuScene::create();
}

bool GameMenuScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	
	auto screenSize = Director::getInstance()->getVisibleSize();

	auto background1 = ResourceManager::GetInstance()->GetSpriteById(0);
	background1->setPosition(screenSize.height / 2, screenSize.width / 2);
	background1->setScale(2);
	background1->removeFromParent();
	addChild(background1, -1);

	

	auto logo = ResourceManager::GetInstance()->GetSpriteById(1);
	logo->setPosition(Vec2(320, 600));
	logo->removeFromParent();
    addChild(logo, 1);

	auto buttonPlay = ResourceManager::GetInstance()->GetButtonById(0);
	buttonPlay->setPosition(Vec2(320, 480));
	buttonPlay->addClickEventListener([&] (Ref* event) {
		auto gotoNext = CallFunc::create([]() {

			Director::getInstance()->replaceScene(GamePlayScene::creatScene());

		});

		auto sequence = Sequence::create(DelayTime::create(0.1), gotoNext,
			nullptr);

		runAction(sequence);
	});
	addChild(buttonPlay,1);
	return true;
}