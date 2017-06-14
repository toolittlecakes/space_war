
#include <iostream>
#include <fstream>
#include <ctime>
#include "game.h"
#include "output.h"
#include "input.h"

#include "planet.h"
#include "player.h"
#include "shoot.h"



GameObject* Game::create_object(std::string & type_object, Parameters& p)
{

	if (type_object == "player") {
		Player* player = new Player();
		player->setup(p);
		return player;
	}
	else if (type_object == "planet") {
		Planet* planet = new Planet();
		planet->setup(p);
		return planet;
	}
	else if (type_object == "shoot") {
		Shoot* shoot = new Shoot();
		shoot->setup(p);
		return shoot;
	}
	else {
		return nullptr; //TODO сделать нормально
	}
}



void Game::players_actions(std::map<SDL_Keycode, bool>& key_state)
{
	for (auto it : game_objects) {
		it->players_actions(key_state);
	}
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

	while (1) {
		auto it = game_objects.begin();
		bool was_deleted = false;
		while (it != game_objects.end()) {
			if ((*it)->get_parameters().must_be_deleted) {
				std::cout << (*it)->get_parameters().name << " was deleted" << std::endl;
				game_objects.erase(it);
				was_deleted = true;
				break;
			}
			++it;
		}
		if (was_deleted == false) {
			break;
		}
	}

	return true;
}

void Game::game_events()
{
	int pos = 0;
	while (1) {
		
		auto it = game_objects.begin() + pos;
		
		bool was_created = false;
		
		while (it != game_objects.end() - 1) {
			
			if ((*it)->get_parameters().make_shoot) {
				
				Parameters obj_par = (*it)->get_parameters();
				Parameters parameters;

				std::string type_object = "shoot";
				parameters.name = type_object;
				parameters.angle = obj_par.angle;
				parameters.coordinates.x = obj_par.coordinates.x + obj_par.size.y * sin(obj_par.angle);
				parameters.coordinates.y = obj_par.coordinates.y - obj_par.size.y * cos(obj_par.angle);
				parameters.speed.x = obj_par.speed.x + obj_par.size.y * sin(obj_par.angle);
				parameters.speed.y = obj_par.speed.y - obj_par.size.y * cos(obj_par.angle);
				pos = 1 + it - game_objects.begin();
				game_objects.push_back(create_object(type_object, parameters));
				was_created = true;
				
				break;
			}
			++it;
		}
		if (was_created == false) {
			
			break;
		}
	}
}

bool Game::setup(std::istream & input_data)
{
	
	if (input_data) {
		
		std::string filename, type_object;
		while (!input_data.eof()) {
			input_data >> filename >> type_object;
			std::ifstream object_data;
			object_data.open(filename);
			while (!object_data.eof()) {
				Parameters parameters(object_data);
				GameObject * new_object = create_object(type_object, parameters);
				game_objects.push_back(new_object);
			}
			object_data.close();
		}
		
	}

	//TODO ELSE
	return true;
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
			input.refresh();
			players_actions(input.get_key_state());
			calculate_game();
			collide_game();
			game_events();
			
			next_game_tick += SKIP_TICKS;
			loops++;
		}
		interpolation = static_cast<double>(GetTickCount() + SKIP_TICKS - next_game_tick)
			/ static_cast<double>(SKIP_TICKS);
		display_game(interpolation);


		
		if (input.get_exit()) {
			break;
		}
	}
}

unsigned long Game::GetTickCount()
{
	return clock();
}
