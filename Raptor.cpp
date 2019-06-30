//
// Created by Nickolay PIATIKOP on 2019-06-30.
//
#include "Colors.hpp"
#include "Raptor.hpp"
#include "Game.hpp"
#include "EnemyBullet.hpp"

Raptor::Raptor() :Marine(){
	this->color = COLOR_PAIR(RAPTOR);
	this->_char = ']';
	this->_hp = 35;
	this->_type = "pirate";
	this->dy = 1;
}

Raptor::~Raptor() {

}

Raptor::Raptor(const Raptor &obj) :Marine(obj){
	this->dy = obj.dy;
}

Raptor &Raptor::operator=(Raptor const &rhs) {
	this->color = rhs.color;
	this->_type = rhs._type;
	this->_hp = rhs._hp;
	this->_char = rhs._char;
	this->_x = rhs._x;
	this->_y = rhs._y;
	return *this;
}

void Raptor::drawmarine() {
	Marine::drawmarine();
}

Marine *Raptor::clone() const {
	return new Raptor(*this);
}

void Raptor::movemarine() {
	if (this->gettime() > 0.02) {
		this->_y = this->_y + this->dy;
		this->_clocks = clock();
	}
	if (this->_y == Y - 1){
		this->dy = -1;
	} else if (this->_y <= 1){
		this->dy = 1;
	}
}
void Raptor::attack() {
	Game::getSquad().pushMarine(new EnemyBullet(*this));
}
