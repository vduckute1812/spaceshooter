#ifndef __GAMEOVERSTATE_H__
#define __GAMEOVERSTATE_H__
#include "ResourceManager.h"
#include "GameEngine.h"
#include "StateMachine.h"
#include "State.h"


class GameOverState :public State
{
private:
	int m_savingScore;
public:
	void SetSavingScore(int);
	virtual void OnInit();
	virtual void OnUpdate(float deltaTime);
	virtual void OnRender(Graphics *graphics);
	virtual void OnExit();

	GameOverState();
	~GameOverState();
};

#endif