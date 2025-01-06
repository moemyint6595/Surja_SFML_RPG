#ifndef STATE_H
#define STATE_H

#include "../Entities/Entity.h"


class State
{
public:
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	virtual ~State();

	
	virtual void checkForQuit();
	virtual const bool& getQuit() const;
	virtual void updateMousePositions();

	virtual void endState() = 0;
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;

public:
	

private:

protected:
	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	bool quit;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Resources
	std::vector<sf::Texture> textures;

protected:
	virtual void initKeybinds() = 0;

private:

};

#endif

