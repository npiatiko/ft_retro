//
// Created by Nickolay PIATIKOP on 2019-06-29.
//

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Marine.hpp"

class Character : public Marine{
private:
	Marine *clone()const;

public:
	Character();
	~Character();
	Character(const Character &obj);
	Character &operator=(Character const &rhs);
	void drawmarine();
	void setX(int x);
	void setY(int y);
};


#endif //CHARACTER_HPP
