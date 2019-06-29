//
// Created by Nickolay PIATIKOP on 2019-06-29.
//

#ifndef SQUAD_HPP
#define SQUAD_HPP
#include "Marine.hpp"
#include "Pirates.hpp"


class Squad {
private:
	Pirates _squad[10];

public:
	Squad();
	~Squad();
	Squad(const Squad &obj);
	Squad &operator=(Squad const &rhs);
	void drawSquad();

};


#endif //SQUAD_HPP
