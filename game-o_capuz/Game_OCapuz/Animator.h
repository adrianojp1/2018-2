#pragma once

#include "stdfx.h"

class Animator
{
private:
	unsigned int _spriteCounter;
	const unsigned int _nSprites;

	sf::IntRect _spriteRect;

	//Animation times
	float _totalTime;
	const float _switchTime;

	sf::RectangleShape* _pShape;
	sf::Texture _texture;

public:
	Animator(std::string texture_filePath, unsigned int spriteCount, float switchTime, sf::RectangleShape* pShape);
	~Animator();

	void updateSprite(float& deltaTime, bool facingRight);

	unsigned int getSpriteCounter() const { return _spriteCounter; }
	void setSpriteCounter(unsigned int spriteCounter) { _spriteCounter = spriteCounter; }
};

