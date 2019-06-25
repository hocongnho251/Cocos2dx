#include "ResourceManager.h"
#include <iostream>
#include <fstream>

using namespace std;

ResourceManager* ResourceManager::s_instance = NULL;
ResourceManager::ResourceManager()
{
	this->m_sprites ;
	this->m_buttons ;
	this->m_dataFolderPath = "";
	this->m_labels;
}

ResourceManager::~ResourceManager()
{
	

}

ResourceManager* ResourceManager::GetInstance()
{
	if (s_instance == NULL)
	{
		s_instance = new ResourceManager();
	}

	return s_instance;
}

void ResourceManager::Init(const std::string path)
{
	this->m_dataFolderPath = path;
	Load("res/Data.bin");

}

void ResourceManager::Load(std::string fileName)
{
	ifstream fileInPut(fileName);
	string tempPath,stringIgnore,tempPathNormalButton,tempPathPressedButton;
	int tempId;
	int count;
	Sprite* sprite;
	ui::Button* button;
	Label* label;
	if (!fileInPut.is_open())
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
			//int temP=(int)tempId;
			fileInPut >> stringIgnore;
			fileInPut >> tempPath;
			tempPath.replace(0, 2, this->m_dataFolderPath);
		    sprite = Sprite::create(tempPath);
			sprite->retain();
			m_sprites.insert(pair<int, Sprite*>(tempId,sprite));
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
			tempPathNormalButton.replace(0, 2, this->m_dataFolderPath);
			fileInPut >> tempPathPressedButton;
			tempPathPressedButton.replace(0, 2, this->m_dataFolderPath);
			button = ui::Button::create(tempPathNormalButton, tempPathPressedButton);
			button->retain();
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
			tempPath.replace(0, 2, this->m_dataFolderPath);
			label = Label::createWithTTF("", tempPath,20);
			//label->retain();
			m_labels.insert(pair<char, Label*>(tempId, label));

		}

	}


}

Sprite* ResourceManager::GetSpriteById(char id)
{
	map<char, Sprite*>::iterator idOfSprite;
	
	for (idOfSprite = m_sprites.begin(); idOfSprite != m_sprites.end(); idOfSprite++)
	{
		
		if (id == idOfSprite->first)
		{
			return idOfSprite->second;
		}
	}
}

ui::Button* ResourceManager::GetButtonById(char id)
{
	map<char, ui::Button*>::iterator idOfButton;
	for (idOfButton = m_buttons.begin(); idOfButton != m_buttons.end(); idOfButton++)
	{
		if (id == idOfButton->first)
		{
			idOfButton->second->retain();
			return idOfButton->second;
		}
	}
}

Label* ResourceManager:: GetLabelById(char id)
{
	map<char, Label*>::iterator idOfLabel;
	for (idOfLabel = m_labels.begin(); idOfLabel != m_labels.end(); idOfLabel++)
	{
		if (id == idOfLabel->first)
		{
			idOfLabel->second->retain();
			return idOfLabel->second;
		}
	}

}
