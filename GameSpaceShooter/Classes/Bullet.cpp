#include"Bullet.h"

Bullet::Bullet(cocos2d::Scene* scene)
{
	this->m_sprite = ResourceManager::GetInstance()->GetSpriteById('2');
	Init();
	scene->addChild(m_sprite);
}

Bullet::~Bullet()
{

}

void Bullet::Init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	m_sprite->setPosition(visibleSize.height / 2, visibleSize.width / 2);
}

void Bullet::Update(float deltaTime)
{

}


