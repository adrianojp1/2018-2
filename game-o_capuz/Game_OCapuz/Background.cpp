#include "Background.h"

Background::Background(Player1* pPlayer)
{
	_pPlayer = pPlayer;
}
Background::~Background()
{
}

void Background::add_layer(std::string layer_filepath)
{
	sf::Texture* tlayer = new sf::Texture;
	tlayer->loadFromFile(layer_filepath);

	layer1 = new sf::RectangleShape;

	layer1->setSize(sf::Vector2f{ 928.0f, 1000.0f });
	layer1->setOrigin(layer1->getSize().x / 2.0f, 700.0f);

	layer1->setTexture(tlayer);
	
	//_layers.push_back(layer);
	
	/*//Initialize background
	sf::Texture background;
	sf::RectangleShape bg;
	bg.setSize(sf::Vector2f{ 928.0f, 1000.0f });
	bg.setOrigin(bg.getSize().x / 2.0f, 700);
	background.loadFromFile("Media/Background.png");
	bg.setTexture(&background);
	//bg.setFillColor(sf::Color::Magenta);*/
}

void Background::draw()
{
	pGame->draw(*layer1);
	/*for (unsigned int i = 0; i < _layers.size(); i++)
		window.draw(*(_layers[i]));*/
}

void Background::execute()
{
	layer1->setPosition(_pPlayer->getPosition().x, 0.0f);
	//_layers[0]->setPosition(_pPlayer->getPosition());
}