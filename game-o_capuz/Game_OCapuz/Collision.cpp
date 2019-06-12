#include "Collision.h"

Collision::Collision(sf::RectangleShape& body1, sf::RectangleShape& body2,
					 sf::Vector2f* direction, float push) :
	_body1(body1), _body2(body2)
{
	_direction = direction;
	_push = push;
}


Collision::~Collision()
{
}

bool Collision::checkCollision()
{
	//Get the 2 colliders dimensions
	sf::Vector2f body2Position = _body2.getPosition();
	sf::Vector2f body2HalfSize = _body2.getSize() / 2.0f;

	sf::Vector2f body1Position = _body1.getPosition();
	sf::Vector2f body1HalfSize = _body1.getSize() / 2.0f;

	//Distance between the centers
	float deltaX = body2Position.x - body1Position.x;
	float deltaY = body2Position.y - body1Position.y;

	//Intersections
	float intersectX = abs(deltaX) - (body2HalfSize.x + body1HalfSize.x);
	float intersectY = abs(deltaY) - (body2HalfSize.y + body1HalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{	//Collision occurs
		_push = std::min(std::max(_push, 0.0f), 1.0f);

		if (intersectX > intersectY) //Negative numbers
		{	//Pushed in X axe
			if (deltaX > 0.0f)
			{ //Colliding on the right
				moveByCollision(_body1, intersectX * (1.0f - _push), 0.0f);
				moveByCollision(_body2, -intersectX * _push, 0.0f);

				_direction->x = 1.0f;
				_direction->y = 0.0f;
			}
			else
			{ //Colliding on the left
				moveByCollision(_body1, -intersectX * (1.0f - _push), 0.0f);
				moveByCollision(_body2, intersectX * _push, 0.0f);

				_direction->x = -1.0f;
				_direction->y = 0.0f;
			}
		}
		else
		{	//Pushed in Y axe
			if (deltaY > 0.0f)
			{ //Colliding on bottom
				moveByCollision(_body1, 0.0f, intersectY * (1.0f - _push));
				moveByCollision(_body2, 0.0f, -intersectY * _push);

				_direction->x = 0.0f;
				_direction->y = 1.0f;
			}
			else
			{ //Colliding on top
				moveByCollision(_body1, 0.0f, -intersectY * (1.0f - _push));
				moveByCollision(_body2, 0.0f, intersectY * _push);

				_direction->x = 0.0f;
				_direction->y = -1.0f;
			}
		}
		return true;
	}

	return false;
}
