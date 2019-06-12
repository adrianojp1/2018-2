#pragma once
#include "Entity.h"
#include "Animator.h"

class DrawableEnt : virtual public Entity
{
protected:
	sf::RectangleShape _sprite;
public:
	DrawableEnt();
	~DrawableEnt();

	//Initializers
	virtual void initializeShape() = 0;
	virtual void initializeTextures() = 0;

	//General managers
	virtual void draw() = 0;
	virtual void execute() = 0;

	//Texture managers
	virtual void updateSprite() = 0;
};

