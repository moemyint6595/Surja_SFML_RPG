#include "MainMenuState.h"

void MainMenuState::initKeybinds()
{
	std::ifstream ifs("Config/mainmenustate_keybinds.ini");
	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";
		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}
	ifs.close();
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) 
	: State(window, supportedKeys)
{
	this->initKeybinds();
}

MainMenuState::~MainMenuState()
{

}


void MainMenuState::endState()
{
	std::cout << "MainMenu state ended" << std::endl;
}

void MainMenuState::updateInput(const float& dt)
{
	this->checkForQuit();
}

void MainMenuState::update(const float& dt)
{
	this->updateInput(dt);
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
}