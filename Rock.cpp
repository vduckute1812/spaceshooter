#include "Rock.h"

Rock::Rock()
{
	image = ResourceManager::GetInstance()->GetImageById(ROCK_ID);
	m_rockSpeed = rand() % (MAX_ROCK_SPEED - MIN_ROCK_SPEED + 1) + MIN_ROCK_SPEED;
	position.x = rand() % (SCREEN_WIDTH - ROCK_PADDING + 1) + ROCK_PADDING;
	position.y = 0;

	type = ROCK_TYPE;
	isEnable = false;
}


Rock::~Rock()
{
}

void Rock::Update(float deltaTime){
	//Generate 
	if (isEnable == true){
		position.y = position.y + deltaTime * m_rockSpeed;
	}

	if (position.y >= SCREEN_HEIGHT){
		position.y = 0;
		isEnable = false;
	}
}

void Rock::Render(Graphics *graphics){
	graphics->DrawImage(image, position.x, position.y);
	
}
