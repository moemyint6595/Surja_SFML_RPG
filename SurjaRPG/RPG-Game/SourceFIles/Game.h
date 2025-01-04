#ifndef GAME_H
#define GAME_H

#include "../States/GameState.h"

class Game
{
public:

	//Constructor/Destructor
	Game();
	virtual ~Game();

	//Functions
	void endApplication();

	//Update
	void updateDt();
	void updateSFMLEvents();
	void update();

	//Render
	void render();

	//Main
	void run();

public:
	//Variables
	

private:

	//Initializations
	void initWindow();
	void initStates();
	void initKeys();
	//Functions

private:
	//Variables
	sf::RenderWindow* window;
	sf::Event sfEvent;

	//Time
	sf::Clock dtClock;
	float dt;

	//States
	std::stack<GameState*> states;

	std::map<std::string, int> supportedKeys;
};

#endif
