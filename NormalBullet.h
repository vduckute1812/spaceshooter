#ifndef __NORMALBULLET_H__
#define __NORMALBULLET_H__
#include "Bullet.h"

class NormalBullet : public Bullet
{

public:
	virtual void SetTypeBullet(int type);
	virtual void Update(float deltaTime);
	virtual void Render(Graphics *graphics);
	virtual void SetDirection(Vector2);
	NormalBullet();
	~NormalBullet();
};

#endif