//
// Created by Nickolay PIATIKOP on 2019-06-29.
//

#include "Colors.hpp"
#include "Squad.hpp"
#include "Fighter.hpp"
#include "Interceptor.hpp"
#include "Bomber.hpp"
#include "Raptor.hpp"
#include "Asteroid.hpp"

Squad::Squad() :_count(10), _spawnClock(clock()), _spawnBOSS(clock()){
	srand(time(NULL));
	this->_squad = new Marine *[this->_count];
	this->learnMarines();
	for (int i = 0; i < this->_count; ++i) {
		this->_squad[i] = this->_source[rand() % 5]->clone();
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
	this->_source[4] = new Asteroid();

}

void Squad::action() {
	for (int i = 0; i < this->_count; ++i) {
		this->_squad[i]->movemarine();
		this->_squad[i]->attack();
	}
}

void Squad::popMarine(Marine *marine) {
	Marine **tmp = this->_squad;

	this->_squad = new Marine *[this->_count - 1];
	for (int j = 0, k = 0; j < this->_count; j++) {
		if (tmp[j] != marine){
			this->_squad[k] = tmp[j];
			++k;
		} else{
			delete tmp[j];
		}
	}
	delete[](tmp);
	this->_count--;
}

void Squad::dellDeadMarines() {
	for (int i = 0; i < this->_count; ++i) {
		if (this->_squad[i]->getX() == 0 || this->_squad[i]->getX() > X || this->_squad[i]->getHP() <= 0){

			popMarine(this->_squad[i]);
		}
	}
	mvprintw(72, 10, "count:[%d]", this->_count);
}
void Squad::pushMarine(Marine *newMarine) {

	Marine **tmp = this->_squad;

	this->_squad = new Marine *[this->_count + 1];
	for (int i = 0; i < this->_count; ++i) {
		this->_squad[i] = tmp[i];
	}
	this->_squad[this->_count] = newMarine;
	this->_count++;
	delete[](tmp);
}
int Squad::searchInterseption(Character &chr) {
	int tmp = 0;

	for (int i = 0; i < this->_count; ++i) {
		for (int j = i + 1; j < this->_count; ++j) {
			if (this->_squad[i]->getX() == this->_squad[j]->getX() &&
				this->_squad[i]->getY() == this->_squad[j]->getY()) {
				if ((!(this->_squad[i]->getType().compare("bullet")) &&
					 !(this->_squad[j]->getType().compare("pirate"))) ||
					(!(this->_squad[j]->getType().compare("bullet")) &&
					 !(this->_squad[i]->getType().compare("pirate")))) {
					this->_squad[i]->decrement();
					this->_squad[j]->decrement();
					tmp += 20;
				}
				if ((!(this->_squad[i]->getType().compare("bullet")) &&
					 !(this->_squad[j]->getType().compare("enemybullet"))) ||
					(!(this->_squad[j]->getType().compare("bullet")) &&
					 !(this->_squad[i]->getType().compare("enemybullet")))) {
					this->_squad[i]->decrement();
					this->_squad[j]->decrement();
					tmp += 5;
				}
			}
		}
		if(chr.getX()==this->_squad[i]->getX() && chr.getY()==this->_squad[i]->getY() && this->_squad[i]->getType().compare("bullet")){
			this->_squad[i]->decrement();
			chr.decrement();
		}
	}
	return tmp;
}
void Squad::spawn() {
	if (((long double)(clock() - this->_spawnClock) / CLOCKS_PER_SEC) > 0.5){
		this->pushMarine(this->_source[rand() % 5]->clone());
		this->_spawnClock = clock();
	}

}
void Squad::spawnBOSS() {

	Marine *boss = this->_source[rand() % 4];
	Marine *tmp;
	for (int i = 0; i < 4; ++i) {
		tmp = boss->clone();
		tmp->setX(300);
		tmp->setY(Y / 2 - 2 + i);
		this->pushMarine(tmp);
		tmp = boss->clone();
		tmp->setX(300 + 1);
		tmp->setY(Y / 2 - 2 + i);
		this->pushMarine(tmp);
	}
}
