#pragma once
#include "cocos2d.h"
#include "Objects.h"
#include<iostream>
#include"Rock.h"
#include"ResourceManager.h"


class SpaceShooter :public Objects 
{
public:
	std::list<Objects*> m_bullets;
	SpaceShooter(cocos2d::Scene* scene);
	~SpaceShooter();
	void Init() override;
	void Update(float deltaTime) override;
	void Shoot();
	void Collision(std::vector<Rock*>);

};