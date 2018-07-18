#ifndef __RESOURCEMANAGER_H__
#define __RESOURCEMANAGER_H__
#include <map>
#include "GameEngine.h"
#include <sstream>      // std::stringstream, std::stringbuf


const int NUM_PLANTS_ID = 3;
const int NUM_FRAME_SWITCH_IMAGE = 10;


class ResourceManager
{
private:
	int m_numImages;
	int m_numFonts;
	int m_numButtons;
	int m_numSounds;
	int m_numImgAnima;
	static ResourceManager *instance;
	std::map<int, Image*> images;
	std::map<int, Font*> fonts;
	std::map<int, UIButton*> buttons;
	std::map<int, Animation*> plants;

	std::list<Image*> listImage;

	ResourceManager();
	~ResourceManager();

public:
	static ResourceManager* GetInstance();
	static void DestroyInstance();
	void Init(const char* path);
	int GetId( char*);
	Image* GetImageById(int id);
	Font* GetFontById(int id);
	UIButton* GetUIButtonById(int id);
	Animation* GetAnimationById(int id);
};

#endif