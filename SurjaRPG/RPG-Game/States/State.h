#ifndef STATE_H
#define STATE_H

#include "../Entities/Entity.h"


class State
{
public:
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	virtual ~State();

	
	virtual void checkForQuit();
	const bool& getQuit() const;
	virtual void updateInput(const float& dt) = 0;
	virtual void endState() = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
	
	

public:
	

private:

protected:
	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	bool quit;

	//Resources
	std::vector<sf::Texture> textures;

protected:
	virtual void initKeybinds() = 0;

private:

};

#endif

