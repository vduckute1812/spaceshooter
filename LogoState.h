#ifndef __LOGOSTATE_H__
#define __LOGOSTATE_H__
#include "Object.h"
#include "State.h"
#include "StateMachine.h"
#include "MainMenuState.h"
#include "GameEngine.h"

class LogoState:public State
{
private:
	float m_timeLoading;
public:
	virtual void OnInit();
	virtual void OnUpdate(float deltaTime);
	virtual void OnRender(Graphics *graphics);
	virtual void OnExit();
	LogoState();
	~LogoState();
};

#endif

