#ifndef __MAINMENUSTATE_H__
#define __MAINMENUSTATE_H__
#include "State.h"
#include "GameEngine.h"
#include "StateMachine.h"
#include "GamePlayState.h"
#include "ResourceManager.h"


class MainMenuState:public State
{
public:
	virtual void OnInit();
	virtual void OnUpdate(float deltaTime);
	virtual void OnRender(Graphics *graphics);
	virtual void OnExit();
	MainMenuState();
	~MainMenuState();
};

#endif