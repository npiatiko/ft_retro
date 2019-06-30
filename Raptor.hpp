//
// Created by Nickolay PIATIKOP on 2019-06-30.
//

#ifndef RAPTOR_HPP
#define RAPTOR_HPP
#include "Marine.hpp"

class Raptor : public Marine{
private:
	int 	dy;

public:
	Raptor();
	~Raptor();
	Raptor(const Raptor &obj);
	Raptor &operator=(Raptor const &rhs);
	void drawmarine();
	Marine *clone()const;
	void movemarine();
};


#endif //RAPTOR_HPP
