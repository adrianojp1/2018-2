#pragma once
#include "DLList.h"
#include "Entity.h"
#include "Player.h"
class EntitiesList
{
private:
	DLList<Entity*> _entities;
public:
	EntitiesList();
	~EntitiesList();
	
	typedef DLList<Entity*>::iterator iterator;

	void clear() { _entities.clear(); }
	void pushBack(Entity* pEnt) { _entities.pushBack(pEnt); }
	void remove(Entity* pEnt) { _entities.remove(pEnt); }
	
	void draw();
	void execute();

	void handleCollisions(Entity* pEnt, sf::Vector2f* collidingDirection);

	//bool checkCollision(sf::RectangleShape& _body1, sf::RectangleShape& _body2, sf::Vector2f* _direction);
	//void moveByCollision(sf::RectangleShape& _body, float dx, float dy) { _body.move(dx, dy); }
};

