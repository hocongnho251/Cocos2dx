#pragma once
#include"cocos2d.h"
#include"Rock.h"
#include "SpaceShooter.h"

class GamePlayScene :public cocos2d::Scene
{
public:
	std::vector<Rock*> m_rocks;
	SpaceShooter* m_spaceShip;
public:
	static cocos2d::Scene* creatScene();
	bool init();
	void update(float deltaTime);
	void GenerateRock();
	void ShootBullet(float deltaTime);
	void RockDown(float deltaTime);
	bool onTouchBegan(Touch *touch, Event *event);
	void onTouchMoved(Touch *touch, Event *event);
	CREATE_FUNC(GamePlayScene);
};