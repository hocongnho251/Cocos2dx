#include"SpaceShooter.h"
#include"Bullet.h"
#include "Rock.h"

SpaceShooter::SpaceShooter(cocos2d::Scene* scene)
{
	this->m_sprite = ResourceManager::GetInstance()->GetSpriteById(4);
	m_sprite->setPosition(10, 10);
	scene->addChild(m_sprite);
}

SpaceShooter::~SpaceShooter()
{

}

void SpaceShooter::Init()
{

}

void SpaceShooter::Update(float deltaTime)
{
	Shoot();

}

void SpaceShooter::Shoot()
{
	std::map<int, Sprite*> map_bullet;

	

}

void SpaceShooter::Collision(std::vector<Rock*>)
{

}

