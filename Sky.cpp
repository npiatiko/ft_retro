//
// Created by Nickolay PIATIKOP on 2019-06-29.
//

#include <cstdlib>
#include <ncurses.h>
#include "Sky.hpp"
#include "Colors.hpp"

Sky &Sky::operator=(Sky const &) {
	return *this;
}
Sky::~Sky() {

}
Sky::Sky() {
	for (int i = 0; i < Y; ++i) {
		for (int j = 0; j < X; ++j) {
			if (rand() % 10 == 1){
				this->_sky[i][j] = '.';
			} else{
				this->_sky[i][j] = ' ';
			}
		}

	}
}
Sky::Sky(const Sky &) {

}
void Sky::drawSky() {
	static int starty = 0;
	static int speed = 3;

	for (int i = 0; i < Y; ++i) {
		for (int j = 0; j < X; ++j) {
			attrset(GRAY);
			mvaddch(i, j, this->_sky[i][(j + starty) % 361]);
		}
	}
	speed = speed ? speed - 1 : 3;
	if (speed == 3) {
		starty = starty == 361 ? 0 : starty + 1;
	}
}
