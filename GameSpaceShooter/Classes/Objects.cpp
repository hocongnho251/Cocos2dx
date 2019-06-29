

#include "Objects.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;



Objects::Objects()
{
	this->m_sprite;
}


Objects::~Objects()
{

}


void Objects::Init()
{


}

void Objects::Update(float deltaTime)
{

}

void Objects::setSptire(Sprite* sprite)
{
	this->m_sprite = sprite;
}

Sprite* Objects::getSprite()
{
	return this->m_sprite;
}
Sprite* Objects::DuplicateSprite(Sprite * sprite)
{
	Sprite* pRet = Sprite::createWithTexture(sprite->getTexture());
	pRet->setVisible(false);
	if (sprite->getChildrenCount() > 0)
	{
		for (int child = 0; child < sprite->getChildrenCount(); child++)
		{
			Sprite* spriteChild = (Sprite*)sprite->getChildren().at(child);
			Sprite* clone = DuplicateSprite((Sprite*)spriteChild);
			clone->boundingBox() = spriteChild->boundingBox();
			clone->setContentSize(spriteChild->getContentSize());
			clone->setPosition(spriteChild->getPosition());
			clone->setAnchorPoint(spriteChild->getAnchorPoint());
			pRet->addChild(clone, spriteChild->getZOrder(), spriteChild->getTag());
		}
	}
	return pRet;
}


