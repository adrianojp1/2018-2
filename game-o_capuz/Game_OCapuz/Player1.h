#pragma once
#include "Player.h"

class Player1 : public Player
{
	/*
	std::string _name;
	sf::Text _nameTxt;
	sf::Font _nameFnt;*/
public:
	Player1();
	~Player1();

	//Executioners
	void execute();
	void exeMove();
	void exeAttack();

	//Initializers
	void initializeTextures();

	//Controls
	bool left_pressed()	  { return sf::Keyboard::isKeyPressed(sf::Keyboard::A);	 }
	bool right_pressed()  { return sf::Keyboard::isKeyPressed(sf::Keyboard::D);	 }
	bool jump_pressed()	  { return sf::Keyboard::isKeyPressed(sf::Keyboard::W);	 }
	bool atk_pressed()	  { return sf::Keyboard::isKeyPressed(sf::Keyboard::Space); }

	//virtual void draw();

/*Static const*/private:
	static const std::string  IDLE_TEXTUREPATH;
	static const std::string  WALK_TEXTUREPATH;
	static const std::string  ATK_TEXTUREPATH;
};

