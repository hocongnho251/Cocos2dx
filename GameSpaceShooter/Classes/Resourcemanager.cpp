#include "Resourcemanager.h"
#include <iostream>
#include <fstream>

using namespace std;
ResourceManager::ResourceManager()
{
	this->m_sprites ;
	this->s_instance = 0;
	this->m_buttons;
	this->m_dataFolderPath = "D:\SpaceShooet\Cocos2dx\GameSpaceShooter\Resources\res";
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
	this->m_dataFolderPath = path;
	Load("Data.bin");

}

void ResourceManager::Load(std::string fileName)
{
	ifstream fileInPut(fileName);
	string tempPath,stringIgnore,tempPathNormalButton,tempPathPressedButton;
	char tempId;
	int count;
	Sprite* sprite;
	ui::Button* button;
	Label* label;
	if (fileInPut.fail())
	{
		cout << "Load file ERROR !";
	}
	else
	{
		// Read Sprite
		fileInPut >> stringIgnore;
		fileInPut >> count;
		for (int i = 0; i < count; i++)
		{
			fileInPut >> stringIgnore;
			fileInPut >> tempId;
			fileInPut >> stringIgnore;
			fileInPut >> tempPath;
			sprite = Sprite::create(tempPath);
			m_sprites.insert(pair<char, Sprite*>(tempId,sprite));
		}
		// Read Button
		fileInPut >> stringIgnore;
		fileInPut >> count;
		for (int j = 0; j < count; j++)
		{
			fileInPut >> stringIgnore;
			fileInPut >> tempId;
			fileInPut >> stringIgnore;
			fileInPut >> tempPathNormalButton;
			fileInPut >> tempPathPressedButton;
			button = ui::Button::create(tempPathNormalButton, tempPathPressedButton);
			m_buttons.insert(pair<char, ui::Button*>(tempId, button));
		}
		//Read Label
		fileInPut >> stringIgnore;
		fileInPut >> count;
		for (int k = 0; k < count; k++)
		{
			fileInPut >> stringIgnore;
			fileInPut >> tempId;
			fileInPut >> stringIgnore;
			fileInPut >> tempPath;
			label = Label::createWithTTF("", tempPath,20);
			m_labels.insert(pair<char, Label*>(tempId, label));

		}


	}
}

Sprite* ResourceManager::GetSpriteById(char id)
{

}

ui::Button* ResourceManager::GetButtonById(char id)
{

}

Label* ResourceManager:: GetLabelById(char id)
{

}
