#include "ResourceManager.h"
//
bool checkDigit(char c){
	return (c >= '0' && c <= '9');
}

ResourceManager::ResourceManager()
{
	m_numImages = 0;
	m_numFonts = 0;
	m_numButtons = 0;
	m_numSounds = 0;
}

ResourceManager::~ResourceManager()
{
	printf("Call destroy instance function. \n");
	int i;
	if (instance){

		//Remove Image data
		for (i = 1; i <= this->m_numImages; i++)
		{
			if (images[i] != NULL){
				delete images[i];
				images[i] = NULL;
			}
		}

		//Remove Font data
		for (i = 1; i <= this->m_numFonts; i++)
		{
			delete fonts[i];
			fonts[i] = NULL;
		}

		//Remove UIButton data
		for (i = 1; i <= this->m_numButtons; i++)
		{
			delete buttons[i];
			buttons[i] = NULL;
		}
	}

	//Remove Animation data
	for (i = 1; i <= 3; i++)
	{
		delete plants[i];
		plants[i] = NULL;
	}


	instance = 0;
}

ResourceManager *ResourceManager::instance = 0;

ResourceManager* ResourceManager::GetInstance(){
	if (!instance){
		printf("Call Init instance function. \n");
		instance = new ResourceManager();
	}
	return instance;
}

void ResourceManager::DestroyInstance(){
	if (instance)
		delete instance;
}

void ResourceManager::Init(const char* path){
	printf("Call Init data instance function. \n");

	//system("GetResources.py");		//Run script code generate Data.txt file

	FILE* f = fopen(path, "r");
	char data_type_path[100];
	char prev_btn_path[100];
	int itemId;
	char *p = data_type_path;

	fscanf(f, "#Fonts %d\n", &this->m_numFonts);
	for (int i = 1; i <= this->m_numFonts; i++)
	{
		fscanf(f, "- ID: %d\n", &itemId);
		fscanf(f, "- PATH:%s\n", data_type_path);
		printf("%s\n", data_type_path);

		fonts.insert(std::pair<int, Font*>(itemId, new Font(data_type_path)));
	}

	fscanf(f, "#Images %d\n", &this->m_numImages);
	for (int i = 1; i <= this->m_numImages; i++)
	{
		fscanf(f, "- ID: %d\n", &itemId);
		fscanf(f, "- PATH:%s\n", data_type_path);
		printf("%s\n", data_type_path);
		images.insert(std::pair<int, Image*>(itemId, new Image(data_type_path)));
	}

	fscanf(f, "#Sounds %d\n", &this->m_numSounds);
	for (int i = 1; i <= this->m_numSounds; i++)
	{
		fscanf(f, "- ID: %d\n", &itemId);
		printf("%d\n", itemId);
		fscanf(f, "- PATH:%s\n", data_type_path);
		printf("%s\n", data_type_path);
	}

	fscanf(f, "#UIButton %d\n", &this->m_numButtons);
	for (int i = 1; i <= this->m_numButtons; i++)
	{
		fscanf(f, "- ID: %d\n", &itemId);
		fscanf(f, "- PATH:%s\n", prev_btn_path);
		fscanf(f, "- PATH:%s\n", data_type_path);
		buttons.insert(std::pair<int, UIButton*>(itemId, new UIButton(prev_btn_path, data_type_path)));
	}

	fscanf(f, "#Animations_1 %d\n", &m_numImgAnima);
	for (int i = 1; i <= this->m_numImgAnima; i++)
	{
		fscanf(f, "- ID: %d\n", &itemId);
		fscanf(f, "- PATH:%s\n", data_type_path);
		
		listImage.push_back(new Image(data_type_path));
	}

	plants.insert(std::pair<int, Animation*>(1, new Animation(listImage, NUM_FRAME_SWITCH_IMAGE)));
	listImage.clear();
	fscanf(f, "#Animations_2 %d\n", &m_numImgAnima);
	for (int i = 1; i <= this->m_numImgAnima; i++)
	{
		fscanf(f, "- ID: %d\n", &itemId);
		fscanf(f, "- PATH:%s\n", data_type_path);
		listImage.push_back(new Image(data_type_path));
	}
	plants.insert(std::pair<int, Animation*>(2, new Animation(listImage, NUM_FRAME_SWITCH_IMAGE)));
	listImage.clear();

	fscanf(f, "#PLANT %d\n", &m_numImgAnima);
	for (int i = 1; i <= this->m_numImgAnima; i++)
	{
		fscanf(f, "- ID: %d\n", &itemId);
		fscanf(f, "- PATH:%s\n", data_type_path);
		listImage.push_back(new Image(data_type_path));
	}
	plants.insert(std::pair<int, Animation*>(3, new Animation(listImage, NUM_FRAME_SWITCH_IMAGE)));
	listImage.clear();

	//Stop read file
	fclose(f);
	
}

Image* ResourceManager::GetImageById(int id){
	return images.find(id)->second;
}

Font* ResourceManager::GetFontById(int id){
	return fonts.find(id)->second;
}

UIButton* ResourceManager::GetUIButtonById(int id){
	return buttons.find(id)->second;
}

Animation* ResourceManager::GetAnimationById(int id){
	return plants.find(id)->second;
}


int ResourceManager::GetId(char* strData){
	char* p = strData;
	int index = 0;
	while ((*p) != '\0')
	{
		if (checkDigit(*p)){
			index = index * 10 + (*p) - '0';
		}
		p++;
	}
	p = NULL;
	return index;
}