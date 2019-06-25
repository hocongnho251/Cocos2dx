#include"GameMenuScene.h"
#include"ui/CocosGUI.h"
#include"LoadingScene.h"

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
	auto logo = ResourceManager::GetInstance()->GetSpriteById(1);
	logo->setPosition(Vec2(320, 600));
	logo->removeFromParent();
	addChild(logo, 0);
	auto buttonPlay = ResourceManager::GetInstance()->GetButtonById(0);
	buttonPlay->setPosition(Vec2(320, 480));
	buttonPlay->addClickEventListener([&] (Ref* event) {
		auto gotoNext = CallFunc::create([]() {

			Director::getInstance()->replaceScene(LoadingScene::createScene());

		});

		auto sequence = Sequence::create(DelayTime::create(3), gotoNext,
			nullptr);

		runAction(sequence);
	});
	addChild(buttonPlay);
	return true;
}