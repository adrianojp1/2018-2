#include "EntitiesList.h"
#include "Stage.h"


EntitiesList::EntitiesList()
{
}


EntitiesList::~EntitiesList()
{
	this->clear();
}

void EntitiesList::draw()
{
	for (DLList<Entity*>::iterator it = _entities.begin(); it != _entities.end(); it++)
	{
		it->draw();
	}
	
}

void EntitiesList::execute()
{
	for (DLList<Entity*>::iterator it = _entities.begin(); it != _entities.end(); it++)
	{
		it->execute();
	}
}

void EntitiesList::handleCollisions(Entity* pEnt, sf::Vector2f* collidingDirection)
{
	for (DLList<Entity*>::iterator it = _entities.begin(); it != _entities.end(); it++)
	{
		Stage::checkCollision(it->getBody(), pEnt->getBody(), collidingDirection, it->getPush());
	}
}