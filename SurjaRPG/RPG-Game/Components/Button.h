#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

enum button_states
{
	BTN_IDEL = 0, BTN_HOVER, BTN_ACTIVE
};

class Button
{
public:
	Button(float x, float y, float width, float height, sf::Font* font, std::string label, sf::Color idelColor, sf::Color hoverColor, sf::Color activeColor );
	~Button();

	//Accessors
	const bool isPressed() const;

	//Public functions
	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);

private:


public:
	//public variable

private:
	//private variables
	short unsigned buttonState;

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color idelColor;
	sf::Color hoverColor;
	sf::Color activeColor;


};

#endif // !BUTTON_H