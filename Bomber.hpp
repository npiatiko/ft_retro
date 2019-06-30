//
// Created by Nickolay PIATIKOP on 2019-06-30.
//

#ifndef BOMBER_HPP
#define BOMBER_HPP
#include "Marine.hpp"

class Bomber : public Marine{
private:
	int 	_dy;

public:
	Bomber();
	~Bomber();
	Bomber(const Bomber &obj);
	Bomber &operator=(Bomber const &rhs);
	void drawmarine();
	Marine *clone()const;
	void movemarine();
	void attack();
};


#endif //BOMBER_HPP
