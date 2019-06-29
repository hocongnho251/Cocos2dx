#include "GamePlayScene.h"
#include "ResourceManager.h"
#include "SpaceShooter.h"
#include "Rock.h"

USING_NS_CC;
using namespace std;

Rock* rock;
Scene* GamePlayScene::creatScene()
{

	return GamePlayScene::create();
}

bool GamePlayScene::init()
{
	if (! Scene::init())
	{
		return false;
	}

	for (int i = 0; i < 10; i++)
	{
		rock = new Rock(this);
		m_rocks.push_back(rock);

	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto background2 = ResourceManager::GetInstance()->GetSpriteById(0);
	background2->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	background2->removeFromParent();
	addChild(background2,-1);

	this->m_spaceShip = new SpaceShooter(this);

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(GamePlayScene::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(GamePlayScene::onTouchMoved, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
	this->schedule(CC_SCHEDULE_SELECTOR(GamePlayScene::ShootBullet), 0.3);
	this->schedule(CC_SCHEDULE_SELECTOR(GamePlayScene::RockDown), 0.2);
	this->scheduleUpdate();
	return true;
}

void GamePlayScene::update(float deltaTime)
{
	
}

void GamePlayScene::GenerateRock()
{
	
	for (auto i : m_rocks)
	{
		if (i->getSprite()->isVisible() == false)
		{
			i->Update(3);
			break;
		}
	}
	
}
void GamePlayScene::ShootBullet(float deltaTime)
{
	this->m_spaceShip->Update(deltaTime);
	this->m_spaceShip->Collision(m_rocks);
}

void GamePlayScene::RockDown(float deltalTime)
{
	 GenerateRock();
}
bool GamePlayScene::onTouchBegan(Touch *touch, Event *unevent)
{

	return true;

}

void GamePlayScene::onTouchMoved(Touch *touch, Event *event)
{
	auto touchLocation = touch->getLocation();
	m_spaceShip->getSprite()->setPosition(touchLocation);
}