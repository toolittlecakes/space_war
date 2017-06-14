#include <iostream>
#include <istream>
#include <fstream>
#include "game.h"
#include "output.h"

int main(int argc, char *argv[])
{
	std::cout << "привет" << std::endl;
	std::ifstream input_data;
	input_data.open("setup.txt");

	OutputSingleton::instance()->setup();

	Game game;
	game.setup(input_data);
	input_data.close();
	

	game.run();

	return 0;
}