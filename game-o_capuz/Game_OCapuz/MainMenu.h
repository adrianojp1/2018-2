#pragma once
#include "Entity.h"

class MainMenu : Entity
{
private:
	enum MenuOP {PLAY, NPLAYERS, RANK, QUIT};
	MenuOP _op;
	int* _nPlayers;
	Game* _pGame;

	std::vector<sf::Text*> _options;
	sf::Font* _menuFont;

public:
	MainMenu(Game* pGame, sf::Font* menuFont, int* nPlayers);
	~MainMenu();

	void initialize(Game* pGame, sf::Font* menuFont, int* nPlayers);
	void reset();

	void draw();
	void execute();

private:
	void change_opDown();
	void change_opUp();

	void switch_nPlayers();

	void executeOP();

	void updateTexts();

	void saveOption();
/*Static const*/private:
	//Cooldown between option changing
	static const float			CHANGEOP_CD;

	//Font props
	static const int			CHAR_SIZE;
	static const sf::Color		FILL_COLOR;
	static const sf::Color		OUTLINE_COLOR;
	static const int			OUTLINE_THICKNESS;

	//Options strings
	static const std::string	PLAY_OPSTR;
	//
	static const std::string	RANK_OPSTR;
	//
	static const std::string	NPLAYER_OPSTR;
	//
	static const std::string	QUIT_OPSTR;
	
	//Positions
	static const sf::Vector2f	MENU_POSITION;
	//
	static const sf::Vector2f	FIRST_TXTPOS;
	static const sf::Vector2f	SEC_TXTPOS;
	static const sf::Vector2f	THIRD_TXTPOS;
	static const sf::Vector2f	FORTH_TXTPOS;
};

