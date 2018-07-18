#ifndef __EDDYBULLET_H__
#define __EDDYBULLET_H__
#include "Bullet.h"

class EddyBullet: public Bullet
{
private:
	float radius;
public:
	virtual void SetTypeBullet(int type);
	virtual void Update(float deltaTime);
	virtual void Render(Graphics *graphics);
	virtual void SetDirection(Vector2);
	EddyBullet();
	~EddyBullet();
};

#endif