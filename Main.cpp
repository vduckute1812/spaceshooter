#include <GameEngine.h>
#include <stdlib.h>
#include <vld.h>
#include "ResourceManager.h"
#include "LogoState.h"
#include "SpaceShooter.h"

const char* FILE_DATA = "Data.txt";



#pragma comment(lib, "vld.lib")

/**
* The main Program
**/
int main()
{
    // Init Graphics 
    Device *device = Device::GetInstance();
    device->InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT);
    Graphics *graphics = device->GetGraphics();
    InputManager *inputManager = InputManager::GetInstance(); 
	StateMachine* stateMachine = StateMachine::GetInstance();
	stateMachine->Init(FILE_DATA);
	while (device->IsRunning())
    {
        // Update game status 
        // deltaTime = time of that frame
        float deltaTime = GameTime::GetFrameTime();       
        TouchData *touchData = inputManager->GetTouch();
		if (touchData != NULL
			&& (touchData->state == TOUCH_DOWN || touchData->state == TOUCH_MOVE)
			)
        {
			stateMachine->TakeMousePosition(touchData->position.x, touchData->position.y, touchData->state);
            // handle touch
			Logger::Debug("Touch::","Touch state: %d x: %f y: %f", touchData->state, touchData->position.x, touchData->position.y);
        }
		//Update
		stateMachine->Update(deltaTime);

		// Render the scene
		graphics->ClearScreen();
		stateMachine->Render(graphics);
	}

	//
    InputManager::DestroyInstance();
    Device::DestroyInstance();
	StateMachine::DestroyInstance();
	return 0;
}