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

void Game::initStates()
{

	GameState* currentState = new GameState(this->window);

	//Can create more states and push into stack

	this->states.push(currentState);
}


//Constructor/Destructor
Game::Game()
{
	this->initWindow();
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

//Functions
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
	if (!this->states.empty())
		this->states.top()->update(this->dt);

	//Updating Games 

}


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

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}
