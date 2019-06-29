#include"Bullet.h"

Bullet::Bullet(cocos2d::Scene* scene)
{
	this->Init();
	this->m_sprite->removeFromParent();
	m_sprite->setScale(2);
	scene->addChild(this->m_sprite,0);
}

Bullet::~Bullet()
{

}


void Bullet::Init()
{
	
	Sprite* sprite = ResourceManager::GetInstance()->GetSpriteById(2);
	m_sprite = DuplicateSprite(sprite);

}

void Bullet::Update(float deltaTime)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto outHeight = visibleSize.height +origin.y + 10;
	this->m_sprite->setVisible(true);		
	auto moveBy = MoveBy::create(deltaTime, Vec2(0, outHeight));
	auto setVisibleSprite = CallFunc::create([&]() {
		this->m_sprite->setVisible(false);
	});	
	auto sequence = Sequence::create(moveBy, setVisibleSprite, nullptr);
	this->m_sprite->runAction(sequence);
}


