#pragma once
#include "stdfx.h"

class MainMenu;
class Stage1;

class Game
{
public:
	enum GameState { MENU_ST, PLAY_STG1_ST, PLAY_STG2_ST, RANK_ST };
private:
	GameState _state;

	MainMenu* _mainMenu;

	int _nPlayers;
	Stage1* _stage1;

	sf::Font _menuFont;
	//Window atributes
	sf::RenderWindow _window;
	sf::View _view;
	sf::Event _evnt;
	sf::Vector2f viewCenter;
public:
	Game();
	~Game();

	void initialize();
	void execute();

	void setState(GameState state);

	void exeMenu();
	void exePlaying();
	void exeRanking();
	
	void instanceStage1();

	void draw(const sf::Drawable &drawable);
	void closeWindow();
	sf::Event* getEvent();
	void displayWindow(sf::Vector2f& viewCenter);

	sf::Font* getMenuFont();
	sf::View* getView();

private:
	static const unsigned int WINDOW_WIDTH;
	static const unsigned int WINDOW_HEIGH;
	static const std::string  WINDOW_NAME;

	static const std::string  MENUFONT_FILEPATH;
};

