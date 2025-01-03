#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"

class GameState :
	State
{

public:

	GameState(sf::RenderWindow* window);
	virtual ~GameState();

	// Inherited via State
	void endState() override;
	void update(const float& dt) override;
	void updateKeyBinds(const float& dt) override;
	void render(sf::RenderTarget* target = nullptr) override;

	//Own function----- gonna remove later ??? maybe
	const bool& GetGameQuit() const;

private:

};

#endif