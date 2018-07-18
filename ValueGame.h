#ifndef __VALUEGAME_H__
#define __VALUEGAME_H__

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 800;
const int BACKGROUND_ID = 5;

const int NUM_ROCK = 20;
const int NUM_BULLET = 30;
const int ROCK_PADDING = 10;
const int ROCK_ID = 1;
const int MIN_ROCK = 4;
const int MAX_ROCK = 7;

const float BAR_WIDTH = 500.0f;
const float BAR_HEIGHT = 50.0f;
const float LOADING_BAR_PADDING = 10.0f;
const float LOADING_BAR_SPEED = 200.0f;

const int BUTTON_ID = 2;
const int FONT_ID = 2;

const int BLUE_EXPL_ID = 1;
const int RED_EXPL_ID = 2;
const int BLUE_PLANT_ID = 3;

const int PLANT_TYPE = 0;
const int ROCK_TYPE = 1;
const int BULLET_TYPE = 2;

const int SPACE_SHOOTER_ID = 6;
const int MIN_ROCK_SPEED = 30;
const int MAX_ROCK_SPEED = 100;
const int MIN_ROCK_TIMEOUT = 1;		
const int MAX_ROCK_TIMEOUT = 3;		
const int GENER_ROCK_SPEED = 3;
const float WIDTH_ROCK = 48;
const float HEIGH_ROCK = 48;

const int BULLET_ID = 32;
const int BULLET_SPEED = 100;
const float BULLET_TIMEOUT = 1;
const int GENER_BULLET_SPEED = 3;

const float WIDTH_BULLET = 16;
const float HEIGH_BULLET = 22;

const float WIDTH_SPACE_SHOOTER = 128.0;
const float HEIGH_SPACE_SHOOTER = 128.0;

const float SPACE_SHOOTER_SPEED = 200;
const int DIE_STATUS_BLUE_ANIMATION = 1;
const int DIE_STATUS_RED_ANIMATION = 2;
const float DEAD_TIMEOUT = 20.0;
const int DEAD_SPEED = 1;

const int REPLAY_BUTTON_ID = 4;

const int BACK_BUTTON_NORMAL_ID = 1;

const float PI = 3.1415926;

const float RADIUS_EDDY_BULLET = 10;

#endif