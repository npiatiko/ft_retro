//
// Created by Nickolay PIATIKOP on 2019-06-30.
//
#include "Colors.hpp"
#include "Bomber.hpp"

Bomber::Bomber() : Marine(){
	this->color = COLOR_PAIR(CYAN) | A_BOLD;
	this->_char = '0';
	this->_hp = 30;
	this->_type = "pirate";
	this->_dy = 1;
}

Bomber::~Bomber() {

}

Bomber::Bomber(const Bomber &obj)  :Marine(obj){
	this->_dy = obj._dy;
}

Bomber &Bomber::operator=(Bomber const &rhs) {
	this->color = rhs.color;
	this->_type = rhs._type;
	this->_hp = rhs._hp;
	this->_char = rhs._char;
	this->_x = rhs._x;
	this->_y = rhs._y;
	return *this;
}

void Bomber::drawmarine() {
	Marine::drawmarine();
}

Marine *Bomber::clone() const {
	return new Bomber(*this);
}
void Bomber::movemarine() {

	if (this->gettime() > 0.01) {
		Marine::movemarine();
		this->_y = this->_y + this->_dy;
		if (this->_y == Y - 1) {
			this->_dy = -1;
		} else if (this->_y <= 1) {
			this->_dy = 1;
		}
	}
}
