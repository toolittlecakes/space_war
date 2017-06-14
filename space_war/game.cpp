
#include <iostream>
#include <fstream>
#include <ctime>
#include "game.h"
#include "output.h"
#include "input.h"

GameObject* Game::create_object(std::string & type_object, std::istream & data)
{
	
	if (type_object == "player")
	{
		Player* player = new Player();
		Parameters p(data);
		player->setup(p); 
		return player;
	}
	if (type_object == "planet")
	{
		Planet* planet = new Planet();
		Parameters p(data);
		planet->setup(p);
		return planet;
	}
	else {
		return nullptr; //TODO ������� ���������
	}
}

bool Game::accelerate(Input &input)
{
	for (auto it : game_objects) {
		size_t number_player = it->get_parameters().player_number;
		it->accelerate(input.get_axis(number_player));
	}
	return true;
}

bool Game::calculate_game()
{
	for (auto it : game_objects) {
		it->calculate(game_objects);
	}
	return true;
}

bool Game::display_game(const double interpolation)
{
	
	SDL_RenderClear(OutputSingleton::instance()->ren);
	
	OutputSingleton::instance()->refresh_background();

	for (auto it : game_objects) {
		it->draw(interpolation);
	}
	SDL_RenderPresent(OutputSingleton::instance()->ren);
	return true;
}

bool Game::collide_game()
{
	for (auto it : game_objects) {
		it->collide(game_objects);
	}
	return true;
}

void Game::setup(std::istream & input_data)
{
	
	if (input_data) {
		
		std::string filename, type_object;
		while (!input_data.eof()) {
			input_data >> filename >> type_object;
			std::ifstream object_data;
			object_data.open(filename);
			while (!object_data.eof()) {
				GameObject * new_object = create_object(type_object, object_data);
				game_objects.push_back(new_object);
			}
		}
		
	}
	//TODO ELSE
}

void Game::run()
{
	time_t next_game_tick = GetTickCount();
	int loops;
	double interpolation;

	game_is_running = true;
	while (game_is_running) {

		loops = 0;
		while (GetTickCount() > next_game_tick && loops < MAX_FRAMESKIP) {
			accelerate(input);
			calculate_game();
			
			next_game_tick += SKIP_TICKS;
			loops++;
		}
		interpolation = static_cast<double>(GetTickCount() + SKIP_TICKS - next_game_tick)
			/ static_cast<double>(SKIP_TICKS);
		display_game(interpolation);


		input.refresh();
		if (input.get_exit()) {
			break;
		}
	}
}

unsigned long Game::GetTickCount()
{
	return clock();
}
