#include "EddyBullet.h"


EddyBullet::EddyBullet()
{
	image = ResourceManager::GetInstance()->GetImageById(BULLET_ID);
	radius = RADIUS_EDDY_BULLET;
}


EddyBullet::~EddyBullet()
{
}


void EddyBullet::Update(float deltaTime){
	static int angle = 0;
	if (angle >= 360){
		angle = 0;
	}
	else angle++;

	if (isEnable == true){
		position.x = position.x - m_directionBullet.x*m_bulletSpeed*deltaTime - sin(angle*PI / 180)*radius;
		position.y = position.y - m_directionBullet.y*m_bulletSpeed*deltaTime*5 - cos(angle*PI / 180)*radius;
	}

	if (position.y <= 0) {
		isEnable = false;
	}
}

void EddyBullet::Render(Graphics *graphics){
	graphics->DrawImage(image, position.x, position.y);
}

void EddyBullet::SetTypeBullet(int type){
	m_bulletType = type;
}

void EddyBullet::SetDirection(Vector2 pos){
	float length = sqrtf(pos.x*pos.x + pos.y*pos.y);

	m_directionBullet.x = pos.x / length;
	m_directionBullet.y = pos.y / length;
}
