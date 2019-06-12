#pragma once
#include "stdfx.h"
#include "Game.h"
class Entity
{
protected:
	int _id;

	bool _active;

	float _speed;
	sf::Vector2f _velocity;
	sf::Vector2f _position;
	static Game* pGame;
public:
	//Constr / Destr
	Entity(bool active = true);
	Entity(bool active, float speed, int id = -1);
	~Entity();

	//General managers
	virtual void draw() = 0;
	virtual void execute() = 0;

	//Sets & gets
	//Position
	virtual void setPosition(sf::Vector2f position) { _position = position; }
	virtual sf::Vector2f getPosition() const { return _position; }
	//Id
	void setId(int id) { _id = id; }
	int getId() const { return _id; }
	//Speed
	void setSpeed(float speed) { _speed = speed; }
	float getSpeed() const { return _speed; }
	//Push
	virtual float getPush() const { return 0.0f; }
	//Body
	virtual sf::RectangleShape& getBody() { return *(new sf::RectangleShape); }

	static void setpGame(Game* pgm);
	static Game* getpGame();
};

