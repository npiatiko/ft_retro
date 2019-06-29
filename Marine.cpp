//
// Created by Nickolay PIATIKOP on 2019-06-29.
//

#include <ncurses.h>
#include "Marine.hpp"

Marine::Marine(const Marine &) {

}
Marine::Marine() {

}
Marine::~Marine() {

}
Marine &Marine::operator=(Marine const &) {
	return *this;
}
void Marine::drawmarine() {
	attrset(this->color);
	mvaddch(this->_y, this->_x, this->_char);
}
