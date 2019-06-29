//
// Created by Nickolay PIATIKOP on 2019-06-29.
//

#include "Squad.hpp"

Squad::Squad() {

}

Squad::~Squad() {

}

Squad::Squad(const Squad &) {

}

Squad &Squad::operator=(Squad const &) {
	return *this;
}
void Squad::drawSquad() {
	for (int i = 0; i < 10; ++i) {
		this->_squad[i].drawmarine();
	}

}
