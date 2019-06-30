//
// Created by Nickolay PIATIKOP on 2019-06-29.
//

#ifndef SQUAD_HPP
#define SQUAD_HPP
#include "Marine.hpp"
#include "Character.hpp"

class Squad {
private:
	Marine	**_squad;
	Marine	*_source[5];
	int		_count;
	void	learnMarines();
	clock_t _spawnClock;
	clock_t _spawnBOSS;


public:
	Squad();
	~Squad();
	Squad(const Squad &obj);
	Squad &operator=(Squad const &rhs);
	void drawSquad();
	void action();
	void popMarine(Marine *);
	void pushMarine(Marine *);
	int searchInterseption(Character &chr);
	void dellDeadMarines();
	void 	spawn();
};


#endif //SQUAD_HPP
