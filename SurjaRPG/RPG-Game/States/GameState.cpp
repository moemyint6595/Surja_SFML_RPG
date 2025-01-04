#include "GameState.h"

void GameState::initKeybinds()
{
	this->keybinds.emplace("MOVE_LEFT", this->supportedKeys->at("A"));
	this->keybinds.emplace("MOVE_RIGHT", this->supportedKeys->at("D"));
	this->keybinds.emplace("MOVE_UP", this->supportedKeys->at("W"));
	this->keybinds.emplace("MOVE_DOWN", this->supportedKeys->at("S"));
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
	:State(window, supportedKeys)
{
	this->initKeybinds();
}

GameState::~GameState()
{
}

void GameState::endState()
{
	std::cout << "Game state ended" << std::endl;
	//Can release resources
}

void GameState::updateInput(const float& dt)
{
	this->checkForQuit();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player.move(dt, -1.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player.move(dt, 1.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
		this->player.move(dt, 0.0f, -1.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->player.move(dt, 0.0f, 1.0f);
}


const bool& GameState::GetGameQuit() const
{
	return this->getQuit();
}

void GameState::update(const float& dt)
{
	//std::cout << "This is from game state" << std::endl;
	this->updateInput(dt);
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	this->player.render(target);
}



