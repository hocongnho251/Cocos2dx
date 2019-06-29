#include"Rock.h"
#include "GamePlayScene.h"

Rock::Rock(cocos2d::Scene* scene)
{
	this->Init();
	this->m_sprite->removeFromParent();
	m_sprite->setScale(2);
	scene->addChild(m_sprite);
}

Rock::~Rock()
{

}

void Rock::Init()
{
	Sprite* sprite = ResourceManager::GetInstance()->GetSpriteById(3);
	m_sprite = DuplicateSprite(sprite);
	this->m_sprite->runAction(RepeatForever::create(RotateBy::create(2, 360)));
}

void Rock::Update(float deltaTime)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto x = rand()% (int)visibleSize.width;
	auto y = rand() % (int)visibleSize.height;
	this->m_sprite->setVisible(true);
	this->m_sprite->setPosition(x, visibleSize.height);
	auto moveBy = MoveBy::create(deltaTime, Vec2(0,-visibleSize.height ));
	auto setVisibleSprite = CallFunc::create([&]() {
		this->m_sprite->setVisible(false);
	});
	auto sequence = Sequence::create(moveBy, setVisibleSprite, nullptr);
	this->m_sprite->runAction(sequence);

}


