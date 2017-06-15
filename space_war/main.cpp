#include <iostream>
#include <istream>
#include <fstream>
#include "game.h"
#include "output.h"

int main(int argc, char *argv[])
{
	std::ifstream help;
	help.open("help.txt");
	std::cout << help.rdbuf() << std::endl;
	system("pause");


	

	std::ifstream input_data;

	OutputSingleton::instance()->setup();

	size_t exit_code;
	do {
		input_data.open("setup.txt");
		Game game;
		if (game.setup(input_data)) {
			exit_code = game.run();
		}
		input_data.close();
	} while (exit_code == 2);
	
	
	OutputSingleton::instance()->free_inst();
	return 0;
}