#ifndef __STATE_H__
#define __STATE_H__

#include "GameEngine.h"
#include <vector>
#include "Object.h"
#include "ValueGame.h"

class State
{
protected:
	std::vector<Object*> m_objectStates;
	int m_mouseState;

public:
	virtual void TakeMousePoint(float x, float y, int);
	virtual void OnInit() = 0; 
	virtual void OnUpdate(float deltaTime) = 0;
	virtual void OnRender(Graphics* graphics) = 0;
	virtual void OnExit() = 0;
	State();
	virtual ~State();
};

#endif