#ifndef MAINMENU_H
#define MAINMENU_H

#include "GameState.h"
#include "../Components/Button.h"

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
	void render(sf::RenderTarget* target = NULL) override;

	//ClassFunctions
	void updateButtons();
	void renderButtons(sf::RenderTarget* target = NULL);

private:
	// Inherited via State
	void initKeybinds() override;

	//Class function
	void initBackground();
	void initFonts();
	void initButtons();

public:
	//public Variable

private:
	//private Variable
	sf::Sprite background;
	sf::Texture bg_texture;

	sf::Font font;

	/*Button* gamestate_btn;*/
	std::map<std::string, Button*> buttons;

};
#endif // !MAINMENU_H