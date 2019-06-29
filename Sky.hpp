//
// Created by Nickolay PIATIKOP on 2019-06-29.
//

#ifndef SKY_HPP
#define SKY_HPP
#include "Colors.hpp"

class Sky {
private:
	char _sky[X][Y];

public:
	Sky();
	~Sky();
	Sky(const Sky &obj);
	Sky &operator=(Sky const &rhs);
	void drawSky();
};


#endif //SKY_HPP
