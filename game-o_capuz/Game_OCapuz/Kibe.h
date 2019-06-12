#pragma once
#include "Character.h"

class Kibe : public Character
{
private:
	Animator* _Walk_anime;

	Animator* _Tkdmg_anime;

	Animator* _Die_anime;
public:
	Kibe(sf::Vector2f startPosition);
	~Kibe();

	void initializeTextures();
	void initializeShape();

	void execute();

	void onCollision(sf::Vector2f direction);

/*Static const*/private:
	//Walking animation
	static const std::string  WALK_TEXTUREPATH;
	static const unsigned int WALK_SPTCOUNT;
	static const float        WALK_SWCTIME;

	//Taking damage animation
	static const std::string  TKDMG_TEXTUREPATH;
	static const unsigned int TKDMG_SPTCOUNT;
	static const float        TKDMG_SWCTIME;

	//Dying animation
	static const std::string  DIE_TEXTUREPATH;
	static const unsigned int DIE_SPTCOUNT;
	static const float        DIE_SWCTIME;

	static const float		  ATK_COOLDOWN;
	static const int		  ATK_DAMAGE;

	static const float        SPEED;

	static const sf::Vector2f SHAPE_SIZE;
	static const sf::Vector2f BODY_SIZE;

	static const int		  FULL_HP;
	static const int		  BASE_DAMAGE;
};

