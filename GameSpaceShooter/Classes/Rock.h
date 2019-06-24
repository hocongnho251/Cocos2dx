#include "cocos2d.h"
#include "Objects.h"
#include<iostream>


class Rock :public Objects
{
public:
	Rock(cocos2d::Scene* scene);
	~Rock();
	void Init() override;
	void Update(float deltaTime) override;

};