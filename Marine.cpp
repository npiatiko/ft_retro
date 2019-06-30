//
// Created by Nickolay PIATIKOP on 2019-06-29.
//

#include <ncurses.h>
#include "Marine.hpp"
#include "Colors.hpp"

Marine::Marine(const Marine &obj) {
	this->_x = rand() % (X / 10) + 315;
	this->_y = rand() % Y;
	this->color = obj.color;
	this->_char = obj._char;
	this->_hp = obj._hp;
	this->_type = obj._type;
	this->_clocks = clock();
	this->_lastAttack = clock();
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
void Marine::movemarine() {
	this->_x--;
	this->_x = this->_x < 0 ? 0 : this->_x;
	this->_clocks = clock();
}
long double Marine::gettime() {
	clock_t		tmp = clock();
	long double	delay = (long double)(tmp - this->_clocks)/CLOCKS_PER_SEC;

	return delay;
}
int Marine::getX() const {
	return _x;
}
int Marine::getY() const {
	return _y;
}

int Marine::getHP ( void ) const
{
	return (this->_hp);
}

void Marine::attack() {
	this->_lastAttack = clock();
}
std::string const &Marine::getType() const {
	return _type;
}
long double Marine::gettimeAttack() {
	clock_t		tmp = clock();
	long double	delay = (long double)(tmp - this->_lastAttack)/CLOCKS_PER_SEC;

	return delay;
}
void Marine::decrement() {
	(this->_hp)--;
//	mvprintw(73,40, "DECREMENT!!!!");
//	refresh();
}
