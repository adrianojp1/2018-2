#include "Player2.h"
#include "Stage.h"

const std::string  Player2::IDLE_TEXTUREPATH("Media/GreenHood_3_idle.png");
const std::string  Player2::WALK_TEXTUREPATH("Media/GreenHood_3_walking.png");
const std::string  Player2::ATK_TEXTUREPATH("Media/GreenHood_3_mlatk.png");

Player2::Player2()
{
	initializeTextures();
}

Player2::~Player2()
{
}

void Player2::initializeTextures()
{
	_Idle_anime = new Animator(IDLE_TEXTUREPATH, IDLE_SPTCOUNT, IDLE_SWCTIME, &_sprite);

	_Walk_anime = new Animator(WALK_TEXTUREPATH, WALK_SPTCOUNT, WALK_SWCTIME, &_sprite);

	_Atk_anime = new Animator(ATK_TEXTUREPATH, ATK_SPTCOUNT, ATK_SWCTIME, &_sprite);
}

void Player2::execute()
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

	//std::cout << "Player2 HP: " << this->getHp() << " | ";
}

void Player2::exeMove()
{
	float deltaTime = Stage::getClock();
	_velocity.x *= 0.4f;

	//X axe movement
	if (left_pressed())
		_velocity.x -= _speed;
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

void Player2::exeAttack()
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