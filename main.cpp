//
// Created by Nickolay PIATIKOP on 2019-06-29.
//

#include <curses.h>
#include <cstdlib>
#include <ctime>
#include "Game.hpp"

int main (){

	Game game;
	srand(time(NULL));
	game.play();
	return 0;
}