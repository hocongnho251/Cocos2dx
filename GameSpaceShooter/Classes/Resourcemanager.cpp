#include "Resourcemanager.h"

ResourceManager::ResourceManager()
{
	this->m_sprites;
	this->s_instance = 0;
	this->m_buttons;
	this->m_dataFolderPath;
	this->m_labels;
}

ResourceManager::~ResourceManager()
{
	

}

ResourceManager* ResourceManager::GetInstance()
{
	if (s_instance == 0)
	{
		s_instance = new ResourceManager();
	}

	return s_instance;
}

void ResourceManager::Init(const std::string path)
{

}

void ResourceManager::Load(std::string fileName)
{

}

Sprite* ResourceManager::GetSpriteById(char* id)
{

}

ui::Button* ResourceManager::GetButtonById(char* id)
{

}

Label* ResourceManager:: GetLabelById(char* id)
{

}
