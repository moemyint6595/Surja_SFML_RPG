#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"


class State
{
public:
	State(sf::RenderWindow* window);
	virtual ~State();

	
	virtual void checkForQuit();
	const bool& getQuit() const;

	virtual void updateKeyBinds(const float& dt) = 0;
	virtual void endState() = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
	
	

public:
	

private:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	bool quit;

private:

};

#endif

