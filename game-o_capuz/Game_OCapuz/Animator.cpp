#include "Animator.h"

Animator::Animator(std::string texture_filePath, unsigned int spriteCount, float switchTime, sf::RectangleShape* pShape) :
	_nSprites (spriteCount),
	_switchTime(switchTime)
{
	_totalTime = 0.0f;
	_spriteCounter = 0;

	_texture.loadFromFile(texture_filePath);
	_spriteRect.width = _texture.getSize().x / spriteCount;
	_spriteRect.height = _texture.getSize().y;
	_spriteRect.top = 0;

	_pShape = pShape;
	_pShape->setTexture(&_texture);
}

Animator::~Animator()
{
}

void Animator::updateSprite(float& deltaTime, bool facingRight)
{
	_totalTime += deltaTime;

	if (_totalTime >= _switchTime)
	{
		_totalTime -= _switchTime;
		_spriteCounter++;

		if (_spriteCounter >= _nSprites)
			_spriteCounter = 0;
	}

	if (facingRight)
	{
		_spriteRect.left = _spriteCounter * _spriteRect.width;
		_spriteRect.width = abs(_spriteRect.width);
	}
	else
	{
		_spriteRect.left = (_spriteCounter + 1) * abs(_spriteRect.width);
		_spriteRect.width = -abs(_spriteRect.width);
	}

	_pShape->setTexture(&_texture);
	_pShape->setTextureRect(_spriteRect);
}

