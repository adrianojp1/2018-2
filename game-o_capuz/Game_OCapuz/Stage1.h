#pragma once
#include "Stage.h"
class Stage1 : public Stage
{
private:
	Kibe* kibe1;
	
	std::vector<Platform> Platforms;

	static const std::string BG1_L1_FILEPATH;
public:
	Stage1(int* nPlayers);
	~Stage1();

	void initialize();

	void start();

	void draw();
	void execute();
};

