#include "Stage.h"

Player1*	Stage::_player1(NULL);
Player2*	Stage::_player2(NULL);
sf::Clock	Stage::_stgClock;
float		Stage::deltaTime;
int*		Stage::_nPlayers(NULL);

const float Stage::GRAVITY(981.0f);
const std::string Stage::PAUSE_STR("- Pause -");

Stage::Stage(int* nPlayers)
{
	_nPlayers = nPlayers;
	_paused = true;
	
	_player1 = new Player1();
	if (*_nPlayers == 2)
		_player2 = new Player2();

	_pauseTxt.setFont(*pGame->getMenuFont());
	_pauseTxt.setString(PAUSE_STR);
	_pauseTxt.setCharacterSize(50);
	_pauseTxt.setOutlineColor(sf::Color::Black);
	_pauseTxt.setOutlineThickness(2);
}


Stage::~Stage()
{
}

void Stage::unpause()
{
	_paused = false;
}

void Stage::pause()
{
	_paused = true;
		
}

float* Stage::getClockPtr()
{
	return &Stage::deltaTime;
}

float Stage::getClock()
{
	return Stage::deltaTime;
}

void Stage::resetClock()
{
	Stage::deltaTime = _stgClock.restart().asSeconds();
	if (deltaTime > 1.0f / 20.0f)
		deltaTime = 1.0f / 20.0f;
}

bool Stage::checkCollision(sf::RectangleShape& _body1, sf::RectangleShape& _body2, sf::Vector2f* _direction, float _push)
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