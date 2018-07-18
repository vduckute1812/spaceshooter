#include "LogoState.h"


LogoState::LogoState()
{
	OnInit();
}


LogoState::~LogoState()
{
}

void LogoState::OnInit(){
	m_timeLoading = 0;
}

void LogoState::OnUpdate(float deltaTime){
	m_timeLoading += deltaTime*LOADING_BAR_SPEED;
	if (m_timeLoading >= BAR_WIDTH - 2 * LOADING_BAR_PADDING){
		StateMachine::GetInstance()->SwitchState(new MainMenuState());
	}
}

void LogoState::OnRender(Graphics *graphics){
	graphics->SetColor(1.0f, 0.0f, 0.0f);	//Red
	graphics->DrawRect(SCREEN_WIDTH / 2.0f - BAR_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, BAR_WIDTH, BAR_HEIGHT);
	//Draw loading progress
	graphics->SetColor(1.0f, 1.0f, 1.0f);	//White
	graphics->FillRect(SCREEN_WIDTH / 2.0f - BAR_WIDTH / 2.0f + LOADING_BAR_PADDING, 
		SCREEN_HEIGHT / 2.0f + LOADING_BAR_PADDING, m_timeLoading, BAR_HEIGHT - 2 * LOADING_BAR_PADDING);
}

void LogoState::OnExit(){
	delete this;
}

