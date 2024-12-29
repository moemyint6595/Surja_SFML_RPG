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
	void updateDt();
	void updateSFMLEvents();
	void update();
	void render();
	void run();

public:
	//Variables
	

private:

	//Initializations
	void initWindow();
	void initStates();

	//Functions

private:
	//Variables
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	std::stack<GameState*> states;
};

#endif
