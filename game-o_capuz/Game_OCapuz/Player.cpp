#include "Player.h"
#include "Stage1.h"

const unsigned int Player::IDLE_SPTCOUNT	(4);
const float        Player::IDLE_SWCTIME		(0.200f);

const unsigned int Player::WALK_SPTCOUNT	(6);
const float        Player::WALK_SWCTIME		(0.150f);

const unsigned int Player::ATK_SPTCOUNT		(3);
const float        Player::ATK_SWCTIME		(0.100f);

const float		   Player::ATK_COOLDOWN		(0.500f);
const int		   Player::ATK_DAMAGE		(2);

const float        Player::SPEED			(150.0f);
const float        Player::JUMP_HEIGHT		(80.0f);

const sf::Vector2f Player::SHAPE_SIZE		(111.0f, 90.0f);
const sf::Vector2f Player::BODY_SIZE		(21.0f, 63.0f);

const int		   Player::FULL_HP			(6);

Player::Player() : 
	Character(BODY_SIZE, ATK_DAMAGE, ATK_COOLDOWN, FULL_HP, JUMP_HEIGHT)
{	
	_points = 0;
	_state = MOVE;
	initializeShape();
}//sf::Vector2f(0.0f, 35.0f)

Player::~Player()
{
};

/*void Player::draw()
{
	window.draw(_sprite);
	window.draw(_body);
}*/

void Player::initializeShape()
{
	_sprite.setSize(SHAPE_SIZE);
	_sprite.setOrigin(_sprite.getSize() / 2.0f);
	_sprite.setOutlineColor(sf::Color::White);
	_sprite.setOutlineThickness(0.5f);
}

void Player::execute()
{
	//Reset position
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
		_body.setPosition(0.0f, 66.0f / 2.0f);

	switch (_state)
	{
	case Player::MOVE:
		exeMove();
		break;
	case Player::ATTACK:
		exeAttack();
		break;
	default:
		break;
	}

	std::cout << "Player HP: " << this->getHp() << " | ";
}

void Player::exeMove()
{
	float deltaTime = Stage::getClock();
	_velocity.x *= 0.4f;

	//X axe movement
	if (left_pressed())
	{
		_velocity.x -= _speed;
		std::cout << "Apertando A";
	}
	if (right_pressed())
		_velocity.x += _speed;

	//Jump
	if (jump_pressed() && _canJump)
	{
		_canJump = false;

		//Jump impulse //square root ( 2.0f * gravity * jumpHeight);
		_velocity.y = -sqrtf(2.0f * Stage::getGravity() * _jumpHeight); //100 pixel = 1m
	}

	_velocity.y += Stage::getGravity() * deltaTime;

	if (_velocity.x >= -0.5f && _velocity.x <= 0.5f)
	{
		_Idle_anime->updateSprite(deltaTime, _facingRight);
	}
	else
	{
		if (_velocity.x > 0.0f)
			_facingRight = true;
		else
			_facingRight = false;
		_Walk_anime->updateSprite(deltaTime, _facingRight);
	}
	_body.move(_velocity * deltaTime);

	attack->reduceCooldown();
	if (atk_pressed() && !(attack->onCooldown()))
		_state = ATTACK;
}

void Player::exeAttack()
{
	float deltaTime = Stage::getClock();

	_Atk_anime->updateSprite(deltaTime, _facingRight);
	if (_Atk_anime->getSpriteCounter() == 2) //Anime ends
	{
		_state = MOVE;
		_Atk_anime->setSpriteCounter(0);
		this->attack->reset_cdTimer();
	}
}

void Player::onCollision(sf::Vector2f direction)
{
	//Colliding on left
	if (direction.x < 0.0f)
	{
		_velocity.x = 0.0f;
	}
	//Colliding on right
	else if (direction.x > 0.0f)
	{
		_velocity.x = 0.0f;
	}
	//Colliding on bottom
	if (direction.y < 0.0f)
	{
		_velocity.y = 0.0f;
		if (!jump_pressed())
			_canJump = true;
	}
	//Colliding on top
	else if (direction.y > 0.0f)
	{
		_velocity.y = 0.0f;
	}
}

void Player::updateSprite()
{
	sf::Vector2f shift = sf::Vector2f(0.0f, -13.0f);

	if (!_facingRight) { shift.x = -shift.x; }
	_sprite.setPosition( _body.getPosition() + shift);
}


void Player::takeDmg(int dmg)
{
	if (this->_alive)
	{
		_hp -= dmg;
		_invulnerable = true;


		if (_hp <= 0)
			this->die();
	}
}