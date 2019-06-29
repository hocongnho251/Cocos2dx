#pragma once
#include "cocos2d.h"
#include"ResourceManager.h"
class Objects 
{
public :
	cocos2d::Sprite* m_sprite;

	Objects();
	~Objects();
	virtual void Init()=0;
	virtual void Update(float deltaTime)=0;
	void setSptire(Sprite* sprite);
	Sprite* getSprite();

	Sprite * DuplicateSprite(Sprite * sprite);

};