//
// Created by Nickolay PIATIKOP on 2019-06-29.
//

#ifndef FIGHTER_HPP
#define FIGHTER_HPP

#include "Marine.hpp"


class Fighter : public Marine{
private:

public:
	Fighter();
	~Fighter();
	Fighter(const Fighter &obj);
	Fighter &operator=(Fighter const &rhs);
	void drawmarine();
	Marine *clone()const;
	void movemarine();
};


#endif //FIGHTER_HPP
