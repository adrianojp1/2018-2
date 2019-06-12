#include "Entity.h"

Game* Entity::pGame = NULL;

Entity::Entity(bool active)
{
	_active = active;
	_id = -1;
	_speed = 0.0f;
	_position = { 0.0, 0.0 };
}

Entity::Entity(bool active, float speed, int id)
{
	_active = active;
	_id = id;
	_speed = speed;
}

Entity::~Entity()
{
	_id = -1;
}

void Entity::setpGame(Game* pgm)
{
	pGame = pgm;
}

Game* Entity::getpGame()
{
	return pGame;
}
