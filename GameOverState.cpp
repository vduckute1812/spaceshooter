#include "GameOverState.h"


GameOverState::GameOverState()
{
}


GameOverState::~GameOverState()
{
}

void GameOverState::OnInit(){
}

void GameOverState::OnUpdate(float deltaTime){
	if (ResourceManager::GetInstance()->GetUIButtonById(REPLAY_BUTTON_ID)->IsPressedButton()){
		StateMachine::GetInstance()->SwitchState(new GamePlayState());
	}

	if (ResourceManager::GetInstance()->GetUIButtonById(BACK_BUTTON_NORMAL_ID)->IsPressedButton()){
		StateMachine::GetInstance()->SwitchState(new MainMenuState());
	}
}


void GameOverState::OnRender(Graphics *graphics){
	graphics->DrawImage(ResourceManager::GetInstance()->GetImageById(BACKGROUND_ID), 0, 0, 0);
	graphics->DrawTextWithFont(ResourceManager::GetInstance()->GetFontById(FONT_ID),
		SCREEN_WIDTH / 3.0f, SCREEN_HEIGHT / 8.0f, "Game Over");
	std::stringstream ss;
	ss << "Score: " << m_savingScore;
	graphics->DrawTextWithFont(ResourceManager::GetInstance()->GetFontById(FONT_ID),
		SCREEN_WIDTH / 3.0f, SCREEN_HEIGHT / 5.0f, ss.str().c_str());

	Vector2 posButton = Vector2(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 3.0f);
	ResourceManager::GetInstance()->GetUIButtonById(REPLAY_BUTTON_ID)->SetPositionButton(posButton);
	graphics->DrawUIButton(ResourceManager::GetInstance()->GetUIButtonById(REPLAY_BUTTON_ID));

	Vector2 posButton_2 = Vector2(SCREEN_WIDTH / 4.0f, SCREEN_HEIGHT / 3.0f);
	ResourceManager::GetInstance()->GetUIButtonById(BACK_BUTTON_NORMAL_ID)->SetPositionButton(posButton_2);
	graphics->DrawUIButton(ResourceManager::GetInstance()->GetUIButtonById(BACK_BUTTON_NORMAL_ID));

}

void GameOverState::OnExit(){
	delete this;
}

void GameOverState::SetSavingScore(int saveValue){
	m_savingScore = saveValue;
}
