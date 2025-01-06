#ifndef MAINMENU_H
#define MAINMENU_H

#include "State.h"

class MainMenuState :
	public State
{
public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	virtual ~MainMenuState();

	// Inherited via State
	void endState() override;
	void update(const float& dt) override;
	void updateInput(const float& dt) override;
	void render(sf::RenderTarget* target = nullptr) override;

private:

private:

	// Inherited via State
	void initKeybinds() override;


};
#endif // !MAINMENU_H