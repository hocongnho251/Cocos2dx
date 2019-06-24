#include "cocos2d.h"

class Objects 
{
public :
	static cocos2d::Sprite* m_sprite;

	Objects();
	~Objects();
	virtual void Init()=0;
	virtual void Update(float deltaTime)=0;


};