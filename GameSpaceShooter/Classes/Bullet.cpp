#include"Bullet.h"

Bullet::Bullet(cocos2d::Scene* scene)
{
	cocos2d::Sprite* sprite = cocos2d::Sprite::create("bullet.png");
	sprite->setPosition(10,10);
	scene->addChild(sprite);
}

Bullet::~Bullet()
{

}

void Bullet::Init()
{

}

void Bullet::Update(float deltaTime)
{

}


