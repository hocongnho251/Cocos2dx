
#pragma once
#include "cocos2d.h"
#include "ui\CocosGUI.h"

USING_NS_CC;
class ResourceManager
{
private:
	static ResourceManager* s_instance;
	std::string m_dataFolderPath;
	std::map<char, Sprite*> m_sprites;
	std::map<char,ui::Button*> m_buttons;
	std::map<char,Label*> m_labels;
public:
	ResourceManager();
	~ResourceManager();
	void Init(const std::string path);
	void Load(std::string fileName);
	Sprite* GetSpriteById(char id);
	ui::Button* GetButtonById(char id);
	Label* GetLabelById(char id);
    static ResourceManager* GetInstance();



};