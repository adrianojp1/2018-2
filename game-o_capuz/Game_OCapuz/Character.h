#pragma once
#include "stdfx.h"
#include "CollisiveEnt.h"
#include "DrawableEnt.h"
#include "Attack.h"
class Character : public DrawableEnt, public CollisiveEnt
{
protected:
	bool _alive;
	int _hp;
	bool _facingRight;
	float _jumpHeight;

	Attack* attack;
public:
	Character(const sf::Vector2f& body_size, int damage, float atk_cd, int full_hp, float jump_height = 0.0f, const sf::Vector2f startPosition = { 0.0f, 0.0f }, sf::RectangleShape* atk_hitBox = NULL);
	~Character();

	//Executioner
	virtual void execute() = 0;

	//Initializers
	void initializeChar(float jump_height, int damage, float atk_cd, sf::RectangleShape* atk_hitBox, int full_hp);
	virtual void initializeTextures() = 0;
	virtual void initializeBody(const sf::Vector2f& body_size);
	virtual void initializeShape() = 0;

	//Sets & Gets
	void setHp(int hp) { _hp = hp; }
	int getHp() const { return _hp; }

	//Life managers
	int getDamage() const{ return attack->getDmg(); }
	virtual void takeDmg(int dmg);
	virtual void die();
	bool alive() { return _alive; }

	//Texture managers
	virtual void updateSprite();
	virtual void draw();

	//Body managers
	virtual void onCollision(sf::Vector2f direction);


};

