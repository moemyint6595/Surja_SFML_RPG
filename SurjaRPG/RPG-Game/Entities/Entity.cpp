#include "Entity.h"

Entity::Entity()
{
	this->shape.setSize(sf::Vector2f(50.0f, 50.0f));
	this->movementSpeed = 100.0f;
}

Entity::~Entity()
{

}

void Entity::move(const float& dt, const float x_dir, const float y_dir)
{
	this->shape.move(x_dir * movementSpeed * dt , y_dir * movementSpeed * dt);
}

void Entity::update(const float& dt)
{

}

void Entity::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
