//
// Created by Nickolay PIATIKOP on 2019-06-29.
//

#include <curses.h>
#include <cstdlib>
#include <ctime>
#include "Game.hpp"

int main (){

	system("afplay -v 0.8 8bit.mp3 &");

	Game game;
	srand(time(NULL));
	game.play();
	
	system("killall afplay");
	return 0;
}