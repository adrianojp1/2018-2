#include "MainMenu.h"
#include "Game.h"

const int			MainMenu::CHAR_SIZE			(60);
const sf::Color		MainMenu::FILL_COLOR		(sf::Color::Black);
const sf::Color		MainMenu::OUTLINE_COLOR		(sf::Color::Red);
const int			MainMenu::OUTLINE_THICKNESS	(1);

const std::string	MainMenu::PLAY_OPSTR		("Jogar");
const std::string	MainMenu::NPLAYER_OPSTR		("Jogadores: ");
const std::string	MainMenu::RANK_OPSTR		("Ranking");
const std::string	MainMenu::QUIT_OPSTR		("Sair");

const sf::Vector2f  MainMenu::MENU_POSITION		{ -300.0f, -130.0f };

const sf::Vector2f	MainMenu::FIRST_TXTPOS		(MainMenu::MENU_POSITION + sf::Vector2f{ 0.0f, (float)MainMenu::CHAR_SIZE } * 0.0f);
const sf::Vector2f	MainMenu::SEC_TXTPOS		(MainMenu::MENU_POSITION + sf::Vector2f{ 0.0f, (float)MainMenu::CHAR_SIZE } * 1.0f);
const sf::Vector2f	MainMenu::THIRD_TXTPOS		(MainMenu::MENU_POSITION + sf::Vector2f{ 0.0f, (float)MainMenu::CHAR_SIZE } * 2.0f);
const sf::Vector2f	MainMenu::FORTH_TXTPOS		(MainMenu::MENU_POSITION + sf::Vector2f{ 0.0f, (float)MainMenu::CHAR_SIZE } * 3.0f);

MainMenu::MainMenu(Game* pGame, sf::Font* menuFont, int* nPlayers) :
	Entity(true)
{
	initialize(pGame, menuFont, nPlayers);
}

MainMenu::~MainMenu()
{
}

void MainMenu::initialize(Game* pGame, sf::Font* menuFont, int* nPlayers)
{
	_pGame = pGame;
	_menuFont = menuFont;
	_nPlayers = nPlayers;

	reset();
	for (int i = 0; i != 4; i++)
	{
		_options.push_back(new sf::Text);

		_options[i]->setCharacterSize		(CHAR_SIZE);
		_options[i]->setFont				(*_menuFont);
		_options[i]->setFillColor			(FILL_COLOR);
		_options[i]->setOutlineColor		(OUTLINE_COLOR);
		_options[i]->setOutlineThickness	(OUTLINE_THICKNESS);
	}
	_options.shrink_to_fit();

	_options[PLAY]		->setString		(PLAY_OPSTR);
	_options[PLAY]		->setPosition	(FIRST_TXTPOS);

	_options[NPLAYERS]	->setString		(NPLAYER_OPSTR + std::to_string(*_nPlayers));
	_options[NPLAYERS]	->setPosition	(SEC_TXTPOS);

	_options[RANK]		->setString		(RANK_OPSTR);
	_options[RANK]		->setPosition	(THIRD_TXTPOS);

	_options[QUIT]		->setString		(QUIT_OPSTR);
	_options[QUIT]		->setPosition	(FORTH_TXTPOS);

	updateTexts();
}

void MainMenu::reset()
{
	_op = PLAY;
	*_nPlayers = 1;
}

void MainMenu::draw()
{
	for (int i = 0; i<4; i++)
		pGame->draw(*_options[i]);
}

void MainMenu::execute()
{
	std::cout << _op << std::endl;
	switch (pGame->getEvent()->key.code)
	{
	case sf::Keyboard::W:
		change_opUp();
		break;
	case sf::Keyboard::S:
		change_opDown();
		break;
	case sf::Keyboard::Space:
		executeOP();
		break;
	default:
		break;
	}
	updateTexts();
}

void MainMenu::executeOP()
{
	switch (_op)
	{
	case PLAY:
		_pGame->instanceStage1();
		saveOption();
		break;
	case NPLAYERS:
		switch_nPlayers();
		break;
	case RANK:
		_pGame->setState(Game::RANK_ST);
		break;
	case MainMenu::QUIT:
		pGame->closeWindow();
		break;
	default:
		break;
	}
}

void MainMenu::saveOption()
{

	//switch (Game::getEvent()->key.code)

	_pGame->setState(Game::PLAY_STG1_ST);
}

void MainMenu::switch_nPlayers()
{
	if (*_nPlayers == 1)
	{
		*_nPlayers = 2;
	}
 	else
	{
		*_nPlayers = 1;
	}
	_options[NPLAYERS]->setString(NPLAYER_OPSTR + std::to_string(*_nPlayers));
}

void MainMenu::change_opDown()
{
	switch (_op)
	{
	case MainMenu::PLAY:
		_op = NPLAYERS;
		break;
	case MainMenu::NPLAYERS:
		_op = RANK;
		break;
	case MainMenu::RANK:
		_op = QUIT;
		break;
	case MainMenu::QUIT:
		break;
	default:
		break;
	}
}

void MainMenu::change_opUp()
{
	switch (_op)
	{
	case MainMenu::PLAY:
		break;
	case MainMenu::NPLAYERS:
		_op = PLAY;
		break;
	case MainMenu::RANK:
		_op = NPLAYERS;
		break;
	case MainMenu::QUIT:
		_op = RANK;
		break;
	default:
		break;
	}
}

void MainMenu::updateTexts()
{
	for (int i = 0; i < 4; i++)
	{
		_options[i]->setStyle(sf::Text::Regular);
		_options[i]->setOutlineColor(sf::Color::Red);
	}
	_options[_op]->setStyle(sf::Text::Bold);
	_options[_op]->setOutlineColor(sf::Color::White);
}