//
// Created by Nickolay PIATIKOP on 2019-06-30.
//

#ifndef ASTEROID_HPP
#define ASTEROID_HPP
#include "Marine.hpp"

class Asteroid : public Marine{
private:

public:
	Asteroid();
	~Asteroid();
	Asteroid(const Asteroid &obj);
	Asteroid &operator=(Asteroid const &rhs);
	void drawmarine();
	Marine *clone()const;
	void movemarine();
	void attack();

};


#endif //ASTEROID_HPP
