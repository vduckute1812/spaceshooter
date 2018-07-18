#include "Bullet.h"


Bullet::Bullet()
{
	this->position.x = 0;
	this->position.y = 0;

	m_bulletSpeed = BULLET_SPEED;
	type = BULLET_TYPE;
	isEnable = false;
}


Bullet::~Bullet()
{
}

void Bullet::Update(float deltaTime){

}

void Bullet::Render(Graphics *graphics){

}

void Bullet::SetDirection(Vector2 dir){ 

}
