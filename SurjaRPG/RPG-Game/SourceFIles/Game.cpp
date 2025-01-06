#include "Game.h"

//Static functions


//Initializer functions
void Game::initWindow()
{

	std::ifstream ifs("Config/window.ini");

	std::string title = "None";
	sf::VideoMode window_bounds(800,600);
	unsigned framerate_limit = 120;
	bool vertical_sync_enable = false;

	if (ifs.is_open())
	{
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enable;
	}

	ifs.close();

	this->window = new sf::RenderWindow(window_bounds, title);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enable);
	
}

void Game::initKeys()
{

	std::ifstream ifs("Config/support_keys.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		int key_value = 0;

		while (ifs >> key >> key_value) 
		{
			this->supportedKeys[key] = key_value;
		}
	}

	ifs.close();
	//DEBUG
	/*for (auto i : this->supportedKeys)
	{
		std::cout << i.first << " " << i.second << std::endl;
	}*/
}

void Game::initStates()
{
	MainMenuState* _MainMenuState = new MainMenuState(this->window, &this->supportedKeys);
	GameState* _GameState = new GameState(this->window, &this->supportedKeys);
	//Can create more states and push into stack

	this->states.push(_MainMenuState);
	//this->states.push(_GameState);
}


//=======================================Constructor/Destructor================================

Game::Game()
{
	this->initWindow();
	this->initKeys();
	this->initStates();

}

Game::~Game()
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}

//=======================================Functions================================
void Game::endApplication()
{
	//Release Application's resources
}


//=======================================Updates================================
void Game::updateSFMLEvents()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
		{
			this->window->close();
		}
	}
}

void Game::updateDt()
{
	/*Update dt with the time it takes to update and render for one fram*/
	this->dt = this->dtClock.restart().asSeconds();
}

void Game::update()
{
	this->updateSFMLEvents();

	//Update

	//Updating Current State
	if (!this->states.empty()) {

		this->states.top()->update(this->dt);

		if (this->states.top()->getQuit()) 
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	else {
		this->endApplication();
		this->window->close();
	}

	//Updating Games 

}

//=======================================Render================================
void Game::render()
{
	this->window->clear(sf::Color::Black);

	//Draw 

	//Drawing Current State's items
	if (!this->states.empty())
		this->states.top()->render();

	//Drawing Games items

	this->window->display();
}


//=======================================Main================================
void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}
