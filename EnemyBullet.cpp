//
// Created by Nickolay PIATIKOP on 2019-06-30.
//
#include "Colors.hpp"
#include "EnemyBullet.hpp"

EnemyBullet::EnemyBullet() :Marine(){
	this->color = COLOR_PAIR(RED) | A_BOLD;
	this->_char = '-';
	this->_hp = 1;
	this->_type = "enemybullet";

}

EnemyBullet::~EnemyBullet() {
}

EnemyBullet::EnemyBullet(const EnemyBullet &obj) {
	this->_x = obj._x;
	this->_y = obj._y;
	this->color = COLOR_PAIR(RED) | A_BOLD;
	this->_char = '-';
	this->_hp = 20;
	this->_type = "enemybullet";
	this->_clocks = clock();

}

EnemyBullet::EnemyBullet(const Marine &obj) {
	this->_x = obj.getX() - 1;
	this->_y = obj.getY();
	this->color = COLOR_PAIR(RED) | A_BOLD;
	this->_char = '<';
	this->_hp = 20;
	this->_type = "enemybullet";
	this->_clocks = clock();
}

EnemyBullet &EnemyBullet::operator=(EnemyBullet const &rhs) {
	this->color = rhs.color;
	this->_type = rhs._type;
	this->_hp = rhs._hp;
	this->_char = rhs._char;
	this->_x = rhs._x;
	this->_y = rhs._y;
	return *this;
}

void EnemyBullet::movemarine() {
	this->_x--;
}
Marine *EnemyBullet::clone() const {
	return nullptr;
}
