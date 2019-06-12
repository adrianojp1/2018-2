#pragma once

#include "Character.h"
#include "stdfx.h"

class Player : public Character
{
protected:
	enum state { MOVE, ATTACK };
	state _state;
	bool _canJump;
	bool _invulnerable;

	Animator* _Idle_anime;
	Animator* _Walk_anime;
	Animator* _Atk_anime;

	int _points;
public:
	Player();
	~Player();

	//virtual void draw();

	//Executioners
	virtual void execute();
	virtual void exeMove();
	virtual void exeAttack();

	//Initializers
	virtual void initializeTextures() = 0;
	void initializeShape();

	//Auxiliars
	sf::Vector2f getPosition() { return _body.getPosition(); }

	//Life managers
	void takeDmg(int dmg);
	//virtual void die();

	//Texture managers
	void updateSprite();

	//Body managers
	void onCollision(sf::Vector2f direction);

	//Controls
	virtual bool left_pressed() = 0;
	virtual bool right_pressed() = 0;
	virtual bool jump_pressed() = 0;
	virtual bool atk_pressed() = 0;

	/* P2
	#define PAD_8_PRESSED  sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8)
	#define PAD_4_PRESSED  sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4)
	#define	PAD_6_PRESSED  sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6)
	#define ENTER_PRESSED  sf::Keyboard::isKeyPressed(sf::Keyboard::Return)
	*/

/*Static const*/protected:
	//Idle animation
	static const unsigned int IDLE_SPTCOUNT;
	static const float        IDLE_SWCTIME;

	//Walking animation
	static const unsigned int WALK_SPTCOUNT;
	static const float        WALK_SWCTIME;

	//Attacking animation
	static const unsigned int ATK_SPTCOUNT;
	static const float        ATK_SWCTIME;

	//Attack props
	static const float		  ATK_COOLDOWN;
	static const int		  ATK_DAMAGE;

	static const float        SPEED;
	static const float        JUMP_HEIGHT;

	static const sf::Vector2f SHAPE_SIZE;
	static const sf::Vector2f BODY_SIZE;

	static const int		  FULL_HP;
};