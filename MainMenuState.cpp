#include "MainMenuState.h"


MainMenuState::MainMenuState()
{
}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::OnInit(){

}

void MainMenuState::OnUpdate(float deltaTime){
	if (ResourceManager::GetInstance()->GetUIButtonById(BUTTON_ID)->IsPressedButton()){
		StateMachine::GetInstance()->SwitchState(new GamePlayState());
	}
}

void MainMenuState::OnRender(Graphics *graphics){
	graphics->DrawImage(ResourceManager::GetInstance()->GetImageById(BACKGROUND_ID), 0, 0, 0);
	Vector2 posButton = Vector2(SCREEN_WIDTH / 3.0f, SCREEN_HEIGHT / 2.0f);
	ResourceManager::GetInstance()->GetUIButtonById(BUTTON_ID)->SetPositionButton(posButton);
	graphics->DrawTextWithFont(ResourceManager::GetInstance()->GetFontById(FONT_ID), 
								SCREEN_WIDTH / 4.0f, SCREEN_HEIGHT / 4.0f, "Space shooter");
	graphics->DrawUIButton(ResourceManager::GetInstance()->GetUIButtonById(BUTTON_ID));

}

void MainMenuState::OnExit(){
	delete this;
}

