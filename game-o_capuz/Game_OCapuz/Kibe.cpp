#include "Kibe.h"
#include "Stage1.h"

const std::string  Kibe::WALK_TEXTUREPATH("Media/enemy1_sheet_walking.png");
const unsigned int Kibe::WALK_SPTCOUNT(4);
const float        Kibe::WALK_SWCTIME(0.300f);

const std::string  Kibe::TKDMG_TEXTUREPATH("Media/enemy1_sheet_tkdmg.png");
const unsigned int Kibe::TKDMG_SPTCOUNT(4);
const float        Kibe::TKDMG_SWCTIME(0.100f);

const std::string  Kibe::DIE_TEXTUREPATH("Media/enemy1_sheet_die.png");
const unsigned int Kibe::DIE_SPTCOUNT(4);
const float        Kibe::DIE_SWCTIME(0.250f);

const float		   Kibe::ATK_COOLDOWN(0.000f);
const int		   Kibe::ATK_DAMAGE(2);

const float        Kibe::SPEED(30.0f);

const sf::Vector2f Kibe::SHAPE_SIZE(27.0f, 28.0f);
const sf::Vector2f Kibe::BODY_SIZE(24.0f, 27.0f);

const int		   Kibe::FULL_HP(2);
const int		   Kibe::BASE_DAMAGE(2);

Kibe::Kibe(sf::Vector2f startPosition) : 
	Character(BODY_SIZE, BASE_DAMAGE, ATK_COOLDOWN, FULL_HP, 0.0f, startPosition), 
	Entity(true, SPEED, -1)
{
	initializeTextures();
	initializeShape();
}
Kibe::~Kibe()
{
}

void Kibe::initializeTextures()
{
	_Walk_anime = new Animator(WALK_TEXTUREPATH, WALK_SPTCOUNT, WALK_SWCTIME, &_sprite);

	_Tkdmg_anime = new Animator(TKDMG_TEXTUREPATH, TKDMG_SPTCOUNT, TKDMG_SWCTIME, &_sprite);

	_Die_anime = new Animator(DIE_TEXTUREPATH, DIE_SPTCOUNT, DIE_SWCTIME, &_sprite);
}

void Kibe::initializeShape()
{
	_sprite.setSize(SHAPE_SIZE);
	_sprite.setOrigin(_sprite.getSize() / 2.0f);
	_sprite.setOutlineColor(sf::Color::White);
	_sprite.setOutlineThickness(0.5f);
}

void Kibe::execute()
{
	float deltaTime = Stage1::getClock();
	_velocity.x *= 0.3f;

	_velocity.x -= _speed;
	if (_velocity.x > 0.0f)
		_facingRight = true;
	else
		_facingRight = false;

	_velocity.y += Stage::getGravity() * deltaTime;
	_Walk_anime->updateSprite(deltaTime, _facingRight);
	_body.move(_velocity * deltaTime);

	//std::cout << "Kibe1 HP: " << this->getHp() << " | " << std::endl;
}

void Kibe::onCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		//Collision on the left
		_velocity.x = 0.0f;
		_speed = -_speed;
	}
	else if (direction.x > 0.0f)
	{
		//Collision on the right
		_velocity.x = 0.0f;
		_speed = -_speed;
	}
	if (direction.y < 0.0f)
	{
		//Collision on the bottom
		_velocity.y = 0.0f;
	}
	else if (direction.y > 0.0f)
	{
		//Collision on the top
		_velocity.y = 0.0f;
	}
}