#ifndef __OBJECT_H__
#define __OBJECT_H__
#include "GameEngine.h"

class Object
{
protected:
	Vector2 position;
	Vector2 velocity;
	Image *image;
	int type;
	bool isEnable;
public:
	virtual void Update(float deltaTime) = 0;
	virtual void Render(Graphics *graphics) = 0;
	virtual void SetPosition(float x, float y);
	virtual void SetDirection(Vector2);
	virtual Vector2 GetPosition();
	int GetType();
	void SetEnable(bool status);
	bool CheckEnable();
	int GetObjWidth();
	int GetObjHeigh();

	Object();
	virtual ~Object();
};

#endif
