#ifndef __ROCK_H__
#define __ROCK_H__
#include "Object.h"
#include "ResourceManager.h"
#include "GamePlayState.h"

class Rock:public Object
{
private:
	float m_rockSpeed;
public:
	virtual void Update(float deltaTime);
	virtual void Render(Graphics *graphics);
	Rock();
	~Rock();
};

#endif