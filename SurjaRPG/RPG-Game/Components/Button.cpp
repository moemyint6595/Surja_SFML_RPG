#include "Button.h"

/*==================Constuctor/Destructor============*/
Button::Button(float x, float y, float width, float height, sf::Font* font, std::string label, sf::Color idelColor, sf::Color hoverColor, sf::Color activeColor)
{
	this->buttonState = BTN_IDEL;

	this->shape.setPosition(sf::Vector2f(x, y));
	this->text.setPosition(shape.getPosition());
	this->shape.setSize(sf::Vector2f(width, height));

	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(label);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(15);

	/*sf::Vector2f shapePosition = this->shape.getPosition();
	sf::FloatRect textSize = this->text.getGlobalBounds();
	float x_pos = (shapePosition.x + ( shapePosition.x / 2.0f ) ) - (textSize.width / 2.0f);
	float y_pos = (shapePosition.y + ( shapePosition.y / 2.0f ) ) - (textSize.height / 2.0f);
	this->text.setPosition(x_pos,y_pos);*/

	
	sf::Vector2f textPosition = this->text.getPosition();
	sf::FloatRect textRect = this->text.getGlobalBounds();
	sf::FloatRect shapeRect = this->shape.getGlobalBounds();

	std::cout << "shape x position =>" << shapeRect.left << std::endl;
	std::cout << "shape y position =>" << shapeRect.top << std::endl;

	std::cout << "shape width =>" << shapeRect.width << std::endl;
	std::cout << "shape height =>" << shapeRect.height << std::endl;

	std::cout << "shape x position with getPos =>" << this->shape.getPosition().x << std::endl;
	std::cout << "shape y position with getPos =>" << this->shape.getPosition().y << std::endl;

	std::cout << "Text width =>" << textRect.width << std::endl;
	std::cout << "Text height =>" << textRect.height << std::endl;

	float x_pos = textPosition.x + ( shapeRect.width / 2.0f ) - (textRect.width / 2.0f);
	float y_pos = textPosition.y + (shapeRect.height / 2.0f) - (textRect.height);
	this->text.setPosition(x_pos, y_pos);



	this->idelColor = idelColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;
}

Button::~Button()
{
}


//==================Accessors==================
const bool Button::isPressed() const
{
	if (this->buttonState == BTN_HOVER)
		return true;
	return false;
}



//==================Functions==================
void Button::update(const sf::Vector2f mousePos)
{
	/* Update button core funtionality */
	this->buttonState = BTN_IDEL;

	/*system("cls");
	std::cout << "shape x =>" << this->shape.getLocalBounds().left << std::endl;
	std::cout << "shape y =>" << this->shape.getLocalBounds().top << std::endl;

	std::cout << "mouse x =>" << mousePos.x << std::endl;
	std::cout << "mouse y =>" << mousePos.y << std::endl;*/

	if (this->shape.getLocalBounds().contains(mousePos))
	{
		this->buttonState = BTN_HOVER;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonState = BTN_ACTIVE;
		}
	}

	switch (this->buttonState)
	{
	case BTN_IDEL:
		this->shape.setFillColor(this->idelColor);
		break;
	case BTN_HOVER:
		this->shape.setFillColor(this->hoverColor);
		break;
	case BTN_ACTIVE:
		this->shape.setFillColor(this->activeColor);
		break;
	default:
		this->shape.setFillColor(sf::Color::Red);
		break;
	}
	/*system("cls");
	std::cout << "BTN STATE =>" << this->buttonState << std::endl;*/
}

void Button::render(sf::RenderTarget* target)
{
	target->draw(shape);
	target->draw(text);
}
