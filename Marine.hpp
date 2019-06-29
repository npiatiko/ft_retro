//
// Created by Nickolay PIATIKOP on 2019-06-29.
//

#ifndef MARINE_HPP
#define MARINE_HPP

#include <iostream>

class Marine {
protected:
	char		_char;
	int 		color;
	int 		_hp;
	int			_x;
	int			_y;
	std::string	_type;
	Marine();

public:
	~Marine();
	Marine(const Marine &obj);
	Marine &operator=(Marine const &rhs);
	virtual void drawmarine();
};


#endif //MARINE_HPP
