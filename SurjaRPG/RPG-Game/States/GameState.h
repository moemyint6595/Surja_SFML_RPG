#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"

class GameState :
	public State
{

public:

	GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	virtual ~GameState();

	// Inherited via State
	void endState() override;
	void update(const float& dt) override;
	void updateInput(const float& dt) override;
	void render(sf::RenderTarget* target = nullptr) override;

protected:

private:
	// Inherited via State
	void initKeybinds() override;

public:
	//public Variable
	Entity player;

private:
	//private Variables


};

#endif