//
// Created by Nickolay PIATIKOP on 2019-06-29.
//
#include <ncurses.h>
#include "Colors.hpp"
#include "Pirates.hpp"

Pirates::Pirates() {
	this->_x = rand() % (X - 100) + 100;
	this->_y = rand() % Y;
	this->color = COLOR_PAIR(YELLOW) | A_BOLD;
	this->_char = '#';
	this->_hp = 20;
	this->_type = "pirate";

}
Pirates::~Pirates() {

}
Pirates::Pirates(const Pirates &) {
	Marine::drawmarine();
}
Pirates &Pirates::operator=(Pirates const &) {
	return *this;
}
void Pirates::drawmarine() {
	Marine::drawmarine();

}
