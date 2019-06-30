//
// Created by Nickolay PIATIKOP on 2019-06-29.
//

#include <ncurses.h>
#include "Marine.hpp"
#include "Colors.hpp"

Marine::Marine(const Marine &obj) {
	this->_x = rand() % (X - 100) + 100;
	this->_y = rand() % Y;
	this->color = obj.color;
	this->_char = obj._char;
	this->_hp = obj._hp;
	this->_type = obj._type;
}
Marine::Marine() {
	this->_x = rand() % (X - 100) + 100;
	this->_y = rand() % Y;
}

Marine &Marine::operator=(Marine const &) {
	return *this;
}
void Marine::drawmarine() {
	attrset(this->color);
	mvaddch(this->_y, this->_x, this->_char);
}
