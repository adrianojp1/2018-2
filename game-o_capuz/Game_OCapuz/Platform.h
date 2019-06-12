#pragma once
#include "stdfx.h"
#include "CollisiveEnt.h"
#include "DrawableEnt.h"
class Platform : public CollisiveEnt, public DrawableEnt
{
private:
	float _pushCoef;
public:
	Platform(sf::Texture* Texture, sf::Vector2f size, sf::Vector2f position);
	~Platform();
	
	void draw();
	void execute() {}
	void initializeBody(const sf::Vector2f& body_size) {}
	void initializeShape() {}
	void initializeTextures() {}

	float getPush() const { return _pushCoef; }

	//Texture managers
	void updateSprite() {}
};

