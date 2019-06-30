//
// Created by Nickolay PIATIKOP on 2019-06-29.
//

#ifndef MARINE_HPP
#define MARINE_HPP

#include <iostream>

class Marine {
protected:
	clock_t 	_clocks;
	std::string	_type;
	char		_char;
	int 		color;
	int 		_hp;
	int			_x;
	int			_y;
	Marine();

public:
	virtual ~Marine() {}
	Marine(const Marine &obj);
	Marine &operator=(Marine const &rhs);
	virtual void drawmarine();
	virtual Marine *clone()const = 0;
	virtual void movemarine();
	virtual void attack();
	float gettime();
	int getX() const;
	int getY() const;
};


#endif //MARINE_HPP
