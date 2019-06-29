#pragma once
#include "cocos2d.h"
#include "ResourceManager.h"


class GameOverScene : public cocos2d::Scene
{
public:

	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameOverScene);

};