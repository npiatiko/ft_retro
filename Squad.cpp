//
// Created by Nickolay PIATIKOP on 2019-06-29.
//

#include "Squad.hpp"
#include "Fighter.hpp"
#include "Interceptor.hpp"
#include "Bomber.hpp"
#include "Raptor.hpp"

Squad::Squad() :_count(10){
	srand(time(NULL));
	this->_squad = new Marine *[this->_count];
	this->learnMarines();
	for (int i = 0; i < this->_count; ++i) {
		this->_squad[i] = this->_source[rand() % 4]->clone();
	}
}

Squad::~Squad() {
	for (int i = 0; i < 4; ++i) {
		delete (this->_source[i]);
	}
	for (int j = 0; j < this->_count; ++j) {
		delete this->_squad[j];
	}
	delete[](this->_squad);
}

Squad::Squad(const Squad &) {

}

Squad &Squad::operator=(Squad const &) {
	return *this;
}
void Squad::drawSquad() {
	for (int i = 0; i < this->_count; ++i) {
		this->_squad[i]->drawmarine();
	}

}
void Squad::learnMarines() {
	this->_source[0] = new Fighter();
	this->_source[1] = new Interceptor();
	this->_source[2] = new Bomber();
	this->_source[3] = new Raptor();
}
void Squad::action() {
	for (int i = 0; i < this->_count; ++i) {
		this->_squad[i]->movemarine();
	}

}
