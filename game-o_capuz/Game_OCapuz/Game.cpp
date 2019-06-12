#include "Game.h"
#include "MainMenu.h"
#include "Stage1.h"

const std::string  Game::MENUFONT_FILEPATH("Fonts/alagard.ttf");

const unsigned int Game::WINDOW_WIDTH	(1280);
const unsigned int Game::WINDOW_HEIGH	(720);
const std::string  Game::WINDOW_NAME	("O Capuz");


Game::Game() : 
	_window(sf::VideoMode{ WINDOW_WIDTH, WINDOW_HEIGH }, WINDOW_NAME), 
	viewCenter(sf::Vector2f(0.0f, 0.0f)),
	_view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGH / 2))
{
	initialize();
	execute();
}


Game::~Game()
{
}

void Game::initialize()
{
	_state = MENU_ST;
	_menuFont.loadFromFile(MENUFONT_FILEPATH);
	_mainMenu = new MainMenu(this, &_menuFont, &_nPlayers);
	_stage1 = NULL;

	Entity::setpGame(this);
}

void Game::setState(GameState state)
{
	_state = state;
}

void Game::execute()
{
	//Game loop
	while (_window.isOpen())
	{
		_window.clear();

		switch (_state)
		{
		case Game::MENU_ST:
			exeMenu();
			break;
		case Game::PLAY_STG1_ST:
			exePlaying();
			break;
		case Game::RANK_ST:
			exeRanking();
			break;
		default:
			break;
		}
		displayWindow(viewCenter);
	}
}

void Game::exeMenu()
{
	while (_window.pollEvent(_evnt))
	{
		switch (_evnt.type)
		{
		case sf::Event::Closed:
			_window.close();
			break;
		case sf::Event::KeyPressed:
			_mainMenu->execute();
		default:
			break;
		}
	}

	_mainMenu->draw();

	viewCenter = { 0.0f, 0.0f };
}

void Game::exePlaying()
{
	while (_window.pollEvent(_evnt))
	{
		switch (_evnt.type)
		{
		case sf::Event::Closed:
			_window.close();
			break;
		case sf::Event::KeyPressed:
			if (_evnt.key.code == sf::Keyboard::Escape)
			{
				if (_stage1->running())
					_stage1->pause();
				else
					_stage1->unpause();
			}
			break;
		default:
			break;
		}
	}
	_stage1->execute();
	viewCenter = _stage1->getViewCenter();
	_stage1->draw();
}

void Game::exeRanking()
{
	while (_window.pollEvent(_evnt))
	{
		switch (_evnt.type)
		{
		case sf::Event::Closed:
			_window.close();
			break;
		case sf::Event::KeyPressed:
			if (_evnt.key.code == sf::Keyboard::Escape)
				Game::setState(MENU_ST);
			break;
		default:
			break;
		}

	}
}

void Game::displayWindow(sf::Vector2f& viewCenter)
{
	_view.setCenter(viewCenter);
	_window.setView(_view);
	_window.display();
}

void Game::draw(const sf::Drawable &drawable)
{ 
	_window.draw(drawable);
}

void Game::closeWindow()
{
	_window.close();
}

sf::Event* Game::getEvent()
{
	return &_evnt;
}

sf::Font* Game::getMenuFont()
{
	return &_menuFont;
}

sf::View* Game::getView()
{
	return &_view;
}

void Game::instanceStage1()
{
	_stage1 = new Stage1(&_nPlayers);
}