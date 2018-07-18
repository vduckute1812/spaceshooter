#ifndef __GAMEPLAYSTATE_H__
#define __GAMEPLAYSTATE_H__
#include "State.h"
#include "GameEngine.h"
#include "SpaceShooter.h"
#include "StateMachine.h"
#include "GameOverState.h"
#include "Rock.h"
#include "NormalBullet.h"
#include "EddyBullet.h"
#include <string>

class GamePlayState: public State
{
private:
	int m_score;
	float m_powerValue;
	bool isUlti;
public:
	virtual void TakeMousePoint(float x, float y, int mouseState);
	virtual void OnInit();
	virtual void OnUpdate(float deltaTime);
	virtual void OnRender(Graphics *graphics);
	virtual void OnExit();

	GamePlayState();
	~GamePlayState();
};

#endif