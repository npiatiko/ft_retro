//
// Created by Nickolay PIATIKOP on 2019-06-29.
//
#include <ncurses.h>
#include "Character.hpp"
#include "Colors.hpp"

Character::Character() {
	this->_type = "character";
	this->_hp = 100;
	this->_char = '}';
	this->_x = 5;
	this->_y = 37;
	this->color = COLOR_PAIR(GREEN) | A_BOLD;

}

Character::~Character() {

}

Character::Character(const Character &) {

}

Character &Character::operator=(Character const &) {
	return *this;
}

void Character::drawmarine() {
	Marine::drawmarine();

}

void Character::setX(int x) {
	if (this->_x + x > 0 && this->_x + x < X) {
		_x = _x + x;
	}
}

void Character::setY(int y) {
	if (this->_y + y > 0 && this->_y + y < Y) {
		_y = _y + y;
	}
}
