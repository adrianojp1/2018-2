#include "Character.h"

Character::Character
	(
	const sf::Vector2f& body_size, int damage, float atk_cd, int full_hp, float jump_height,
	const sf::Vector2f startPosition, sf::RectangleShape* atk_hitBox
	) :
	CollisiveEnt(), DrawableEnt()
{
	initializeChar(jump_height, damage, atk_cd, atk_hitBox, full_hp);
	initializeBody(body_size);
	this->setPosition(startPosition);
}

Character::~Character()
{
}

void Character::initializeChar(float jump_height, int damage, float atk_cd, sf::RectangleShape* atk_hitBox, int full_hp)
{
	_alive = true;
	_facingRight = true;

	_jumpHeight = jump_height;
	_hp = full_hp;

	attack = new Attack(damage, atk_cd, atk_hitBox);
}

void Character::initializeBody(const sf::Vector2f& body_size)
{
	_body.setSize(body_size);
	_body.setFillColor(sf::Color::Transparent);
	_body.setOutlineColor(sf::Color::Green);
	_body.setOutlineThickness(0.5f);
	_body.setOrigin(_body.getSize() / 2.0f);
	_body.setPosition(this->getPosition());
}

void Character::draw()
{
	pGame->draw(_sprite);
	pGame->draw(_body);
}

void Character::onCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		//Collision on the left
		_velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		//Collision on the right
		_velocity.x = 0.0f;
	}
	if (direction.y < 0.0f)
	{
		//Collision on the bottom
		_velocity.y = 0.0f;
	}
	else if (direction.y > 0.0f)
	{
		//Collision on the top
		_velocity.y = 0.0f;
	}
}

void Character::updateSprite()
{
	_sprite.setPosition(_body.getPosition());
}

void Character::takeDmg(int dmg)
{
	if (_alive)
	{
		_hp -= dmg;
		if (_hp < 0)
		{
			die();
		}
	}
}

void Character::die()
{
	_alive = false;
}