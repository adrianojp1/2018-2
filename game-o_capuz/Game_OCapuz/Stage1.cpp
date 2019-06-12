#include "Stage1.h"

const std::string Stage1::BG1_L1_FILEPATH ("Media/Background.png");

Stage1::Stage1(int* nPlayers) : Stage(nPlayers)
{
	initialize();
	start();
}

Stage1::~Stage1()
{
}

void Stage1::initialize()
{
	Stage1::_player1->setPosition(sf::Vector2f{ 0.0f, 35.0f });
	if (*_nPlayers == 2)
		Stage1::_player2->setPosition(sf::Vector2f{ -50.0f, 35.0f });

	kibe1 = new Kibe(sf::Vector2f(50.0f, 35.0f));

	_background1 = new Background(Stage::_player1);
	_background1->add_layer(BG1_L1_FILEPATH);

	_allEntities.pushBack(static_cast<Entity*> (_background1));
	_allEntities.pushBack(static_cast<Entity*> (new Platform(nullptr, sf::Vector2f(2000.0f, 30.0f), sf::Vector2f(0.0f, 100.0f))));
	_allEntities.pushBack(static_cast<Entity*> (new Platform(nullptr, sf::Vector2f(100.0f, 30.0f), sf::Vector2f(-200.0f, 70.0f))));
	_allEntities.pushBack(static_cast<Entity*> (new Platform(nullptr, sf::Vector2f(200.0f, 30.0f), sf::Vector2f(200.0f, 70.0f))));
	_allEntities.pushBack(static_cast<Entity*> (kibe1));

	Platforms.push_back(Platform(nullptr, sf::Vector2f(2000.0f, 30.0f), sf::Vector2f(0.0f, 100.0f)));
	Platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 30.0f), sf::Vector2f(-200.0f, 70.0f)));
	Platforms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 30.0f), sf::Vector2f(200.0f, 70.0f)));

}

void Stage1::start()
{
	this->unpause();
}

void Stage1::draw()
{
	_allEntities.draw();

	_player1->draw();
	if (*_nPlayers == 2)
		_player2->draw();

	if (_paused)
		pGame->draw(_pauseTxt);
}

void Stage1::execute()
{
	Stage::resetClock();
	if (!_paused)
	{
		_background1->execute();

		_player1->execute();
		if (*_nPlayers == 2)
			_player2->execute();

		kibe1->execute();

		sf::Vector2f collidingDirection;

		_allEntities.handleCollisions(_player1, &collidingDirection);
		if (checkCollision(kibe1->getBody(), _player1->getBody(), &collidingDirection, 0.5f))
		{
			_player1->onCollision(collidingDirection);
			_player1->takeDmg(kibe1->getDamage());
		}
		_player1->updateSprite();

		if (*_nPlayers == 2)
		{
			_allEntities.handleCollisions(_player2, &collidingDirection);
			if (checkCollision(kibe1->getBody(), _player2->getBody(), &collidingDirection, 0.5f))
			{
				_player2->onCollision(collidingDirection);
				_player2->takeDmg(kibe1->getDamage());
			}
			_player2->updateSprite();
		}

		_allEntities.handleCollisions(kibe1, &collidingDirection);
			kibe1->onCollision(collidingDirection);
		kibe1->updateSprite();
	}
	else
		_pauseTxt.setPosition(pGame->getView()->getCenter() - sf::Vector2f{100.0f, 30.0f});
}