#include"Rock.h"

Rock::Rock(cocos2d::Scene* scene)
{
	this->m_sprite = ResourceManager::GetInstance()->GetSpriteById('3');
	m_sprite->setPosition(10, 10);
	scene->addChild(m_sprite);
}

Rock::~Rock()
{

}

void Rock::Init()
{

}

void Rock::Update(float deltaTime)
{

}


