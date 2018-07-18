#ifndef __SPACESHOOTER_H__
#define __SPACESHOOTER_H__

#include <map>
#include "Object.h"
#include "GameEngine.h"
#include "ValueGame.h"
#include "ResourceManager.h"


class SpaceShooter:public Object
{
private:
	//Just for plant
	Animation* plant; 
	Vector2 m_currentPosition;
	Vector2 m_direction;
public:
	virtual Vector2 GetPosition();
	virtual void Update(float deltaTime);
	virtual void Render(Graphics *graphics);
	Vector2 GetDirection();
	SpaceShooter();
	~SpaceShooter();
};

#endif