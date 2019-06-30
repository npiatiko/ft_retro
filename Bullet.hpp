//
// Created by Nickolay PIATIKOP on 2019-06-30.
//

#ifndef BULLET_HPP
#define BULLET_HPP
#include "Character.hpp"
#include "Marine.hpp"

class Bullet :public Marine{
private:

public:
	Bullet();
	~Bullet();
	Bullet(const Bullet &obj);
	Bullet(const Marine &obj);
	Bullet &operator=(Bullet const &rhs);
	void movemarine();
	Marine *clone()const;
};


#endif //BULLET_HPP
