#include"SpaceShooter.h"
#include"Bullet.h"
#include "Rock.h"
#include <iostream>
#include <fstream>
#include "GameOverScene.h"
#include "cocos2d.h"

USING_NS_CC;

using namespace std;


SpaceShooter::SpaceShooter(cocos2d::Scene* scene)
{
	
	this->Init();
	scene->addChild(this->m_sprite);
	for (int i = 0; i < 10; i++) {
		Bullet*  bullet = new Bullet(scene);
		m_bullets.push_back(bullet);
		
	}
	
}

SpaceShooter::~SpaceShooter()
{

}

void SpaceShooter::Init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	this->m_sprite = ResourceManager::GetInstance()->GetSpriteById(4);
	this->m_sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->m_sprite->setScale(2);
	
}

void SpaceShooter::Update(float deltaTime)
{
	
	this->Shoot();
}

void SpaceShooter::Shoot()
{

	for (auto i : m_bullets)
	{
		if (i->getSprite()->isVisible() == false)
		{
			i->getSprite()->setPosition(this->m_sprite->getPosition());
			i->Update(2);
			break;
		}
	}

}

void SpaceShooter::Collision(std::vector<Rock*> m_rocks)
{

	for (auto r : m_rocks)
	{
		if (r->getSprite()->getBoundingBox().intersectsRect(this->m_sprite->getBoundingBox()))
		{
			this->m_sprite->stopAllActions();
			//this->m_sprite->setVisible(false);
			Director::getInstance()->replaceScene(GameOverScene::createScene());
	
		}
		else
		{
			for (auto b : m_bullets)
			{
				if (r->getSprite()->getBoundingBox().intersectsRect(b->getSprite()->getBoundingBox()))
				{
					r->getSprite()->setVisible(false);
					r->getSprite()->stopAllActions();
					b->getSprite()->setVisible(false);
					b->getSprite()->stopAllActions();
				}
			}
		}
	}





}


