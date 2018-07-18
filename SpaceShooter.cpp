#include "SpaceShooter.h"


SpaceShooter::SpaceShooter()
{
	plant = ResourceManager::GetInstance()->GetAnimationById(BLUE_PLANT_ID);
	plant->PlayAnimation();
	image = ResourceManager::GetInstance()->GetImageById(SPACE_SHOOTER_ID);
	m_currentPosition.x = SCREEN_WIDTH / 2.0f - plant->GetWidth() / 2.0f;
	m_currentPosition.y = SCREEN_HEIGHT - plant->GetHeight();
	position = m_currentPosition;
	type = PLANT_TYPE;
	isEnable = true;
}


SpaceShooter::~SpaceShooter()
{
}

void SpaceShooter::Update(float deltaTime){
	m_currentPosition.x += GetDirection().x*SPACE_SHOOTER_SPEED*deltaTime;
	m_currentPosition.y += GetDirection().y*SPACE_SHOOTER_SPEED*deltaTime;
	
	float dx = position.x - m_currentPosition.x;
	float dy = position.y - m_currentPosition.y;
	float length = sqrtf(dx*dx + dy*dy);

	if (length < 3){
		m_currentPosition = position;
	}

	if (isEnable == false){
		plant = ResourceManager::GetInstance()->GetAnimationById(DIE_STATUS_BLUE_ANIMATION);
		if (!plant->IsEnableAnimation()){
			plant->PlayAnimation();
			position = m_currentPosition;
			//isEnable = true;
		}
	}
}

void SpaceShooter::Render(Graphics *graphics){
	graphics->DrawAnimation(plant, m_currentPosition.x, m_currentPosition.y, 0);
}

Vector2 SpaceShooter::GetPosition(){
	return m_currentPosition;
}

Vector2 SpaceShooter::GetDirection(){
	float dx = position.x - m_currentPosition.x;
	float dy = position.y - m_currentPosition.y;
	float length = sqrtf(dx*dx + dy*dy);
	if (length == 0){
		m_direction = Vector2(0, 0);
	}
	else{
		m_direction = Vector2(dx / length, dy / length);
	}
	return m_direction;
}
