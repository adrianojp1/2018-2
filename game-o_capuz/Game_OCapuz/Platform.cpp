#include "Platform.h"



Platform::Platform(sf::Texture* Texture, sf::Vector2f size, sf::Vector2f position)
{
	_pushCoef = 1.0f;
	_body.setSize(size);
	_body.setOrigin(size / 2.0f);
	_body.setTexture(Texture);
	_body.setPosition(position);
}


Platform::~Platform()
{
}

void Platform::draw()
{
	pGame->draw(_body);
}

