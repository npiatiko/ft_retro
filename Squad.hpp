//
// Created by Nickolay PIATIKOP on 2019-06-29.
//

#ifndef SQUAD_HPP
#define SQUAD_HPP
#include "Marine.hpp"


class Squad {
private:
	Marine	**_squad;
	Marine	*_source[4];
	int		_count;
	void	learnMarines();

public:
	Squad();
	~Squad();
	Squad(const Squad &obj);
	Squad &operator=(Squad const &rhs);
	void drawSquad();
	void action();
	void popMarine(Marine *);
	void pushMarine(Marine *);
	void searchInterseption();
	void dellDeadMarines();

};


#endif //SQUAD_HPP
