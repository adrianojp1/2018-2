#pragma once
#include "Entity.h"
#include "Player1.h"

class Background : public Entity
{
private:
	Player1* _pPlayer;
	sf::RectangleShape* layer1;
	//std::vector<sf::RectangleShape*> _layers;

public:
	Background(Player1* pPlayer);
	~Background();

	void add_layer(std::string layer_filepath);

	void draw();
	void execute();
};

