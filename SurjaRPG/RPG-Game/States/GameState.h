#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"

class GameState :
	State
{

public:

	GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	virtual ~GameState();

	// Inherited via State
	void endState() override;
	void update(const float& dt) override;
	void updateInput(const float& dt) override;
	void render(sf::RenderTarget* target = nullptr) override;

	//Own function----- gonna remove later ??? maybe
	const bool& GetGameQuit() const;

public:
	Entity player;

protected:

private:


	// Inherited via State
	void initKeybinds() override;

};

#endif