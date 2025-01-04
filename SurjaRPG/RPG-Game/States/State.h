#ifndef STATE_H
#define STATE_H

#include "../Entities/Entity.h"


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

protected:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	bool quit;

private:

};

#endif

