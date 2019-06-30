//
// Created by Nickolay PIATIKOP on 2019-06-29.
//

#include "Game.hpp"
#include <ncurses.h>
#include <zconf.h>
#include "Colors.hpp"

Game::Game() {
	initscr();
	noecho();
	curs_set(0);
	start_color();
	this->initColor();
}
Game::~Game() {
	mvprintw(50, 50, "press any key");
	refresh();
	getch();
	endwin();
	system("leaks -q ft_retro");
}
Game::Game(const Game &) {

}
Game &Game::operator=(Game const &) {
	return *this;
}
void Game::play() {
	int key;

	nodelay(stdscr, true);
	while (true) {
		usleep(6000);
		clear();
		this->_sky.drawSky();
		ranger.drawmarine();
		_squad.drawSquad();
		_squad.action();
		refresh();
		if ((key = getch()) == ' '){
			break;
		} else{
			this->keyControl(key);
		}
	}
}
void Game::initColor() {

	init_pair(GRAY, 8, 0);
	init_pair(GREEN, COLOR_GREEN, 0);
	init_pair(YELLOW, COLOR_YELLOW, 0);
	init_pair(BLUE, COLOR_BLUE, 0);
	init_pair(RED, COLOR_RED, 0);
	init_pair(CYAN, COLOR_CYAN, 0);
	init_pair(RAPTOR, COLOR_RED, COLOR_YELLOW);
}
void Game::keyControl(int key) {
	switch (key){
		case 'w':{
			this->ranger.setY(-1);
			break;
		}
		case 's':{
			this->ranger.setY(1);
			break;
		}
		case 'a':{
			this->ranger.setX(-1);
			break;
		}
		case 'd':{
			this->ranger.setX(1);
			break;
		}
		default:
			break;
	}

}
