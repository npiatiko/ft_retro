//
// Created by Nickolay PIATIKOP on 2019-06-30.
//
#include "Colors.hpp"
#include "Interceptor.hpp"
#include "EnemyBullet.hpp"
#include "Game.hpp"

Interceptor::Interceptor() :Marine(){
	this->color = COLOR_PAIR(BLUE) | A_BOLD;
	this->_char = '<';
	this->_hp = 1;
	this->_type = "pirate";
}

Interceptor::~Interceptor() {

}

Interceptor::Interceptor(const Interceptor &obj) :Marine(obj){

}

Interceptor &Interceptor::operator=(Interceptor const &rhs) {
	this->color = rhs.color;
	this->_type = rhs._type;
	this->_hp = rhs._hp;
	this->_char = rhs._char;
	this->_x = rhs._x;
	this->_y = rhs._y;
	return *this;
}

void Interceptor::drawmarine() {
	Marine::drawmarine();

}

Marine *Interceptor::clone() const {
	return new Interceptor(*this);
}
void Interceptor::movemarine() {
	if (this->gettime() > 0.01) {
		Marine::movemarine();
	}
}
void Interceptor::attack() {
	if (this->gettimeAttack() > 0.5) {
		Game::getSquad().pushMarine(new EnemyBullet(*this));
		Marine::attack();
	}
}
