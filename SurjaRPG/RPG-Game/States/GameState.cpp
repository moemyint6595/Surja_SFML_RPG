#include "GameState.h"


GameState::GameState(sf::RenderWindow* window)
	:State(window)
{

}

GameState::~GameState()
{
}

void GameState::endState()
{
	std::cout << "Game state ended" << std::endl;
	//Can release resources
}

void GameState::updateKeyBinds(const float& dt)
{
	this->checkForQuit();
}


const bool& GameState::GetGameQuit() const
{
	return this->getQuit();
}

void GameState::update(const float& dt)
{
	//std::cout << "This is from game state" << std::endl;
	this->updateKeyBinds(dt);
}

void GameState::render(sf::RenderTarget* target)
{
	if (target != nullptr) 
	{
		std::cout << "This is render from game state" << std::endl;
	}
	
}



