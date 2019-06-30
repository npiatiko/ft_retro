//
// Created by Nickolay PIATIKOP on 2019-06-30.
//

#include "Asteroid.hpp"
#include "Colors.hpp"

Asteroid::Asteroid() : Marine(){
	this->setX(X - 1);
	this->setY(rand() % Y);
	this->color = COLOR_PAIR(BORDER);
	this->_char = '*';
	this->_hp = 1;
	this->_type = "pirate";

}
Asteroid::~Asteroid() {

}
Asteroid::Asteroid(const Asteroid &obj) :Marine(obj){
	this->setX(X - 1);
	this->setY(rand() % Y);
	this->color = COLOR_PAIR(BORDER);
	this->_char = '*';
	this->_hp = 1;
	this->_type = "pirate";
}
Asteroid &Asteroid::operator=(Asteroid const &rhs) {
	this->color = rhs.color;
	this->_type = rhs._type;
	this->_hp = rhs._hp;
	this->_char = rhs._char;
	this->_x = rhs._x;
	this->_y = rhs._y;
	return *this;
}
void Asteroid::drawmarine() {
	Marine::drawmarine();
}
Marine *Asteroid::clone() const {
	return new Asteroid(*this);
}
void Asteroid::movemarine() {
	if (this->gettime() > 0.15) {
		Marine::movemarine();
	}
}
void Asteroid::attack() {
//	Marine::attack();
}
