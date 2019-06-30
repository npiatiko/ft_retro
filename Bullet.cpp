//
// Created by Nickolay PIATIKOP on 2019-06-30.
//

#include "Bullet.hpp"
#include "Colors.hpp"

Bullet::Bullet() : Marine(){
	this->color = COLOR_PAIR(YELLOW) | A_BOLD;
	this->_char = '-';
	this->_hp = 20;
	this->_type = "bullet";
}
Bullet::~Bullet() {

}
Bullet::Bullet(const Bullet &obj) {
	this->_x = obj._x;
	this->_y = obj._y;
	this->color = COLOR_PAIR(YELLOW) | A_BOLD;
	this->_char = '-';
	this->_hp = 20;
	this->_type = "bullet";
	this->_clocks = clock();

}
Bullet &Bullet::operator=(Bullet const &rhs) {
	this->color = rhs.color;
	this->_type = rhs._type;
	this->_hp = rhs._hp;
	this->_char = rhs._char;
	this->_x = rhs._x;
	this->_y = rhs._y;
	return *this;
}
void Bullet::movemarine() {
	this->_x++;
}
Marine *Bullet::clone() const {
	return nullptr;
}
Bullet::Bullet(const Marine &obj) : Marine(obj) {
	this->_x = obj.getX() + 1;
	this->_y = obj.getY();
	this->color = COLOR_PAIR(YELLOW) | A_BOLD;
	this->_char = '-';
	this->_hp = 20;
	this->_type = "bullet";
	this->_clocks = clock();

}
