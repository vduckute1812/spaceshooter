#include "Object.h"


Object::Object()
{
}


Object::~Object()
{
}

int Object::GetType(){
	return type;
}

void Object::SetEnable(bool status){
	isEnable = status;
}

bool Object::CheckEnable(){
	return isEnable;
}

void Object::SetPosition(float x, float y){
	this->position.x = x;
	this->position.y = y;
}

Vector2 Object::GetPosition(){
	return position;
}

int Object::GetObjWidth(){
	return image->GetWidth();
}

int Object::GetObjHeigh(){
	return image->GetHeight();
}

void Object::SetDirection(Vector2){

}
