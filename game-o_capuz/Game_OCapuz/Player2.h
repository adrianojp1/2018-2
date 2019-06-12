#pragma once
#include "Player.h"
class Player2 :
	public Player
{
public:
	Player2();
	~Player2();

	//Executioners
	void execute();
	void exeMove();
	void exeAttack();

	//Initializers
	void initializeTextures();

	//Controls
	bool left_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4); }
	bool right_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6); }
	bool jump_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8); }
	bool atk_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Return); }

/*Static const*/private:
	static const std::string  IDLE_TEXTUREPATH;
	static const std::string  WALK_TEXTUREPATH;
	static const std::string  ATK_TEXTUREPATH;
};

