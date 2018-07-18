#ifndef __BULLET_H__
#define __BULLET_H__
#include "Object.h"
#include "GameEngine.h"
#include "ValueGame.h"
#include "ResourceManager.h"

class Bullet: public Object
{
protected:
	int m_bulletType;
	float m_bulletSpeed;
	Vector2 m_directionBullet;
public:
	virtual void SetTypeBullet(int type) = 0;
	virtual void Update(float deltaTime);
	virtual void Render(Graphics *graphics);
	virtual void SetDirection(Vector2);

	Bullet();
	~Bullet();
};

#endif