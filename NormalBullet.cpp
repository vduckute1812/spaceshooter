#include "NormalBullet.h"


NormalBullet::NormalBullet()
{
	image = ResourceManager::GetInstance()->GetImageById(BULLET_ID);
}


NormalBullet::~NormalBullet()
{
}

void NormalBullet::Update(float deltaTime){
	if (isEnable == true){
		position.x -= m_directionBullet.x*m_bulletSpeed*deltaTime;
		position.y -= m_directionBullet.y*m_bulletSpeed*deltaTime;
	}
	
	if (position.x <= 0 || position.y <= 0) {
		isEnable = false;
	}
}

void NormalBullet::Render(Graphics *graphics){
	graphics->DrawImage(image, position.x, position.y);
}

void NormalBullet::SetTypeBullet(int type){
	m_bulletType = type;
}

void NormalBullet::SetDirection(Vector2 pos){
	float length = sqrtf(pos.x*pos.x + pos.y*pos.y);

	m_directionBullet.x = pos.x/length;
	m_directionBullet.y = pos.y / length;
}
