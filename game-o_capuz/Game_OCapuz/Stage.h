#pragma once
#include "stdfx.h"
#include "Player1.h"
#include "Player2.h"
#include "Kibe.h"
#include "Platform.h"
#include "Background.h"
#include "EntitiesList.h"

class Stage : public Entity
{
protected:
	bool _paused;
	sf::Text _pauseTxt;
	static int* _nPlayers;

	static Player1* _player1;
	static Player2* _player2;
	//static Player2* _player2;

	Background* _background1;
	EntitiesList _allEntities;

	//EntitiesList* EntList;
	//Save* currSave;
	static sf::Clock _stgClock;
	static float deltaTime;
public:
	Stage(int* nPlayers);
	~Stage();

	//Initializers
	virtual void initialize() = 0;
	
	static float getGravity() { return GRAVITY; }

	//Clockers
	static float getClock();
	static float* getClockPtr();
	static void resetClock();
	
	//Runners
	virtual void start() = 0;
	void unpause();
	void pause();
	bool running() { if (!_paused) return true; return false; }

	virtual void draw() = 0;
	virtual void execute() = 0;

	static sf::Vector2f getViewCenter() { return _player1->getPosition(); }
	
	//Collision managers
	
	static bool checkCollision(sf::RectangleShape& _body1, sf::RectangleShape& _body2, sf::Vector2f* _direction, float _pushCoefic);
	static void moveByCollision(sf::RectangleShape& _body, float dx, float dy) { _body.move(dx, dy); }
	

/*Static const*/protected:
	static const float		 GRAVITY;
	static const std::string PAUSE_STR;
};

