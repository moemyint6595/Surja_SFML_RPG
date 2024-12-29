#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "RPG Game");

	sf::CircleShape shape(50.0f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) 
			{
				window.close();
			}
		}

		window.clear(sf::Color::Black);

		window.draw(shape);

		window.display();
	}

    return 0;
}
