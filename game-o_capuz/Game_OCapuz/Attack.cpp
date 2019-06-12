#include "Attack.h"
#include "Stage.h"

Attack::Attack(int damage, float cooldown, sf::RectangleShape* hitBox) :
	_cooldownt(Stage::getClockPtr(), cooldown)
{
	_damage = damage;
	_hitBox = hitBox;
}

Attack::~Attack()
{

}

void Attack::reduceCooldown()
{
	_cooldownt.reduceTime();
}

void Attack::reset_cdTimer()
{
	_cooldownt.reset_n_trigger();
}