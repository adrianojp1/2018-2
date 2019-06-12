#pragma once
#include "stdfx.h"
#include "Timer.h"

class Attack
{
private:
	Timer _cooldownt;
	int _damage;
	sf::RectangleShape* _hitBox;
public:
	Attack(int damage, float cooldown, sf::RectangleShape* hitBox);
	~Attack();
	
	sf::RectangleShape& getHitBox() const { return *_hitBox; }
	bool onCooldown() const { return _cooldownt.isActive(); }

	void setDmg(int damage) { _damage = damage; }
	int getDmg() const { return _damage; }

	void setCooldown(float cooldown) { _cooldownt.set_totalTime(cooldown); }
	float getTotalCooldown() const { return _cooldownt.get_totalTime(); }
	float getCurrCooldown() const { return _cooldownt.get_currentTime(); }

	void reset_cdTimer();
	void reduceCooldown();
};

