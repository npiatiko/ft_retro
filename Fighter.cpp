//
// Created by Nickolay PIATIKOP on 2019-06-29.
//
#include "Fighter.hpp"
#include "Colors.hpp"
#include "Game.hpp"
#include "EnemyBullet.hpp"

Fighter::Fighter() : Marine(){
	this->color = COLOR_PAIR(YELLOW) | A_BOLD;
	this->_char = '#';
	this->_hp = 1;
	this->_type = "pirate";
}

Fighter::~Fighter() {

}

Fighter::Fighter(const Fighter &obj) :Marine(obj){

}

Fighter &Fighter::operator=(Fighter const &rhs) {
	this->color = rhs.color;
	this->_type = rhs._type;
	this->_hp = rhs._hp;
	this->_char = rhs._char;
	this->_x = rhs._x;
	this->_y = rhs._y;
	return *this;
}

void Fighter::drawmarine() {
	Marine::drawmarine();

}

Marine *Fighter::clone() const {
	return new Fighter(*this);
}
void Fighter::movemarine() {

	if (this->gettime() > 0.01) {

		Marine::movemarine();
		this->_y = this->_y + ((rand() % 3) - 1);
		if (this->_y >= Y - 1) {
			this->_y = Y - 1;
		} else if (this->_y <= 1) {
			this->_y = 1;
		}
	}
}
void Fighter::attack() {
	if (this->gettimeAttack() > 0.1) {
		Game::getSquad().pushMarine(new EnemyBullet(*this));
		Marine::attack();
	}
}
