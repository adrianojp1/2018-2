#pragma once
#include "Entity.h"
#include "stdfx.h"
class CollisiveEnt : virtual public Entity
{
protected:
	sf::RectangleShape _body;

public:
	CollisiveEnt();
	~CollisiveEnt();

	//Initializers
	virtual void initializeBody(const sf::Vector2f& body_size) = 0;
	
	//General managers
	virtual void draw() = 0;//temporary
	virtual void execute() = 0;

	//Body managers
	sf::RectangleShape& getBody() { return _body; }
};

