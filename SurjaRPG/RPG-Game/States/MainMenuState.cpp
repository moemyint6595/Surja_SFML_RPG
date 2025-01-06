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

void MainMenuState::initBackground()
{
	if (this->bg_texture.loadFromFile("./ResourceFiles/assets/background/menu_background.jpg")) 
	{
		std::cout << "Texture loaded" << std::endl;
		this->background.setTexture(bg_texture);
		sf::Vector2u windownSize = this->window->getSize();
		this->background.setTextureRect(sf::IntRect(0,0, windownSize.x, windownSize.y));
	}
}

void MainMenuState::initFonts()
{
	if (this->font.loadFromFile("./ResourceFiles/assets/Font/arial.ttf")) 
	{
		throw("ERROR : Main menu cound not load font.");
	}
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) 
	: State(window, supportedKeys)
{
	this->initKeybinds();
	this->initBackground();
	this->initFonts();
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
	this->updateMousePositions();
	this->updateInput(dt);

	system("cls");
	std::cout << "x =>" << this->mousePosView.x << std::endl;
	std::cout << "y =>" << this->mousePosView.y << std::endl;
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
}