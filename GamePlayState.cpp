#include "GamePlayState.h"


GamePlayState::GamePlayState()
{
	m_score = 0;
	m_powerValue = 0;
	m_mouseState = 0;
	isUlti = false;
}


GamePlayState::~GamePlayState()
{
	for (int i = 0; i < static_cast<int>(m_objectStates.size()); i++)
	{

		delete (m_objectStates[i]);
		m_objectStates.erase(m_objectStates.begin() + i);
		i--;
	}
}

void GamePlayState::OnInit(){
	// 1 PLANT OBJECT 
	this->m_objectStates.push_back(new SpaceShooter());

	// 20 ROCK OBJECT
	for (int i = 1; i <= NUM_ROCK; i++)
	{
		this->m_objectStates.push_back(new Rock());
	}
	
	// 30 BULLET OBJECT
	for (int i = 1; i <= NUM_BULLET; i++)
	{
		this->m_objectStates.push_back(new EddyBullet());
	}

}

void GamePlayState::OnUpdate(float deltaTime){

	std::vector<Object*>::iterator obj;
	obj = m_objectStates.begin();

	if (!obj[0]->CheckEnable()){
		GameOverState *nextState = new GameOverState();
		nextState->SetSavingScore(m_score);
		StateMachine::GetInstance()->SwitchState(nextState);
	}


	static float rockTimeout;
	rockTimeout -= GENER_ROCK_SPEED*deltaTime;
	if (rockTimeout <= 0.0f){
		for (int i = 1; i <= NUM_ROCK; i++)
		{
			if ( !obj[i]->CheckEnable() ){
				obj[i]->SetEnable(true);
				break;
			}
		}
		rockTimeout = (rand() % (MAX_ROCK_TIMEOUT - MIN_ROCK_TIMEOUT + 1) + MIN_ROCK_TIMEOUT);
	}

	static float bulletTimeout;
	bulletTimeout -= GENER_BULLET_SPEED*deltaTime;
	float x_pos;
	float y_pos;
	float angle = -PI / 6.0;

	if (bulletTimeout <= 0.0f ) {
		if (isUlti == true){
			static int count_bullet;
			count_bullet = 0;
			for (int bullet_id = NUM_ROCK + 1; bullet_id <= NUM_ROCK + NUM_BULLET && count_bullet < 3; bullet_id++)
			{
				if (!obj[bullet_id]->CheckEnable()){
					count_bullet++;
					x_pos = obj[0]->GetPosition().x + WIDTH_SPACE_SHOOTER / 2.0 - 2 * WIDTH_BULLET / 3.0;
					y_pos = obj[0]->GetPosition().y;
					obj[bullet_id]->SetPosition(x_pos, y_pos);
					obj[bullet_id]->SetDirection(Vector2(sin(angle)*y_pos, cos(angle)*y_pos));
					angle += PI / 6.0;
					obj[bullet_id]->SetEnable(true);
				}
			}
			m_powerValue -= deltaTime*LOADING_BAR_SPEED*4;
			if (m_powerValue <= 0){
				isUlti = false;
			}
			bulletTimeout = BULLET_TIMEOUT;
		}
		else if ( m_mouseState != 2 ){
			for (int i = 1 + NUM_ROCK; i <= NUM_ROCK + NUM_BULLET; i++)
			{
				if (!obj[i]->CheckEnable()){
					x_pos = obj[0]->GetPosition().x + WIDTH_SPACE_SHOOTER / 2.0 - 2 * WIDTH_BULLET / 3.0;
					y_pos = obj[0]->GetPosition().y;
					obj[i]->SetPosition(x_pos, y_pos);

					obj[i]->SetEnable(true);
					obj[i]->SetPosition(x_pos, y_pos);
					obj[i]->SetDirection(Vector2(0, y_pos));
					break;
				}
			}
				bulletTimeout = BULLET_TIMEOUT;
		}
	}


	//Check collision rock and bullet
	for (int rock_id = 1; rock_id <= NUM_ROCK; rock_id++)
	{
		if (!obj[rock_id]->CheckEnable())
			continue;
		for (int bullet_id = NUM_ROCK + 1; bullet_id <= NUM_ROCK + NUM_BULLET; bullet_id++)
		{
			if (!obj[bullet_id]->CheckEnable())
				continue;
			if (obj[bullet_id]->GetPosition().y >= obj[rock_id]->GetPosition().y
				&& obj[bullet_id]->GetPosition().y <= obj[rock_id]->GetPosition().y + HEIGH_ROCK){
				if (obj[bullet_id]->GetPosition().x + WIDTH_BULLET >= obj[rock_id]->GetPosition().x &&
					obj[bullet_id]->GetPosition().x <= obj[rock_id]->GetPosition().x + WIDTH_ROCK){
					float x_rand = rand() % (SCREEN_WIDTH - int(WIDTH_ROCK) + 1);
					obj[rock_id]->SetPosition(x_rand, 0);
					obj[rock_id]->SetEnable(false);
					obj[bullet_id]->SetEnable(false);
					m_score++;
				}
			}
		}
	}

	//static float deadTimeout;

	//Check collision rock and plane
	for (int rock_id = 1; rock_id <= NUM_ROCK; rock_id++)
	{
		if (!obj[rock_id]->CheckEnable())
			continue;
		if (obj[0]->GetPosition().y >= obj[rock_id]->GetPosition().y
			&& obj[0]->GetPosition().y <= obj[rock_id]->GetPosition().y + HEIGH_ROCK){

			if (obj[0]->GetPosition().x + WIDTH_SPACE_SHOOTER >= obj[rock_id]->GetPosition().x &&
				obj[0]->GetPosition().x  <= obj[rock_id]->GetPosition().x + WIDTH_ROCK){
				float x_rand = rand() % (SCREEN_WIDTH - int(WIDTH_ROCK) + 1);
				obj[rock_id]->SetPosition(x_rand, 0);
				obj[rock_id]->SetEnable(false);
				//deadTimeout = DEAD_TIMEOUT;
				obj[0]->SetEnable(false);
			}
		}
	}

	//if (deadTimeout > 0){
	//	deadTimeout -= DEAD_SPEED*deltaTime;
	//	for (int bullet_id = NUM_ROCK + 1; bullet_id <= NUM_ROCK + NUM_BULLET; bullet_id++)
	//	{
	//		obj[bullet_id]->SetEnable(false);
	//	}
	//}
	//else if (deadTimeout < 0){
	//	obj[0]->SetEnable(false);
	//}


	if (m_mouseState == 2 && m_powerValue < BAR_WIDTH && isUlti == false){
		m_powerValue += deltaTime*LOADING_BAR_SPEED*3;
	}
	else if (m_mouseState == 0 && isUlti == false && m_powerValue < BAR_WIDTH){
		m_powerValue = 0;
	}
	else if (m_powerValue >= BAR_WIDTH && m_mouseState != 2){
		isUlti = true;
	}


	for (; obj != m_objectStates.end(); obj++)
	{
		(*obj)->Update(deltaTime);
	}

	m_mouseState = 0;
}


std::string numScore(int number){
	std::stringstream ss;
	ss << "Score: " << number;
	return ss.str();
}

void GamePlayState::OnRender(Graphics *graphics){
	graphics->DrawImage(ResourceManager::GetInstance()->GetImageById(BACKGROUND_ID), 0, 0, 0);
	std::vector<Object*>::iterator obj;

	obj = m_objectStates.begin();
	obj[0]->Render(graphics);
	for (; obj != m_objectStates.end(); obj++)
	{
		if ((*obj)->CheckEnable()){
			(*obj)->Render(graphics);
		}
	}
		graphics->DrawTextWithFont(ResourceManager::GetInstance()->GetFontById(FONT_ID),
		10.0f, SCREEN_HEIGHT / 20.0f, numScore(m_score).c_str());

		graphics->SetColor(1.0f, 0.0f, 0.0f);	//Red
		graphics->DrawRect(SCREEN_WIDTH - BAR_HEIGHT - LOADING_BAR_PADDING, 5 * LOADING_BAR_PADDING,
							BAR_HEIGHT, BAR_WIDTH);
		//Draw loading progress
		if (m_powerValue >= BAR_WIDTH){
			graphics->SetColor(0.0f, 0.0f, 1.0f);	//Blue
		}
		else if (isUlti == true){
			graphics->SetColor(0.0f, 1.0f, 0.0f);	//Green
		}
		else {
			graphics->SetColor(1.0f, 1.0f, 1.0f);	//White
		}
		graphics->FillRect(SCREEN_WIDTH - BAR_HEIGHT - LOADING_BAR_PADDING,  5 * LOADING_BAR_PADDING + BAR_WIDTH, 
							BAR_HEIGHT - 1, -m_powerValue);
}

void GamePlayState::OnExit(){
	delete this;
}

void GamePlayState::TakeMousePoint(float x, float y, int mouseState){
	if (m_objectStates[0]->CheckEnable())
		m_objectStates[0]->SetPosition(x - WIDTH_SPACE_SHOOTER / 2.0, y - HEIGH_SPACE_SHOOTER / 2.0);		//Set location for Plane
	m_mouseState = mouseState;
}
