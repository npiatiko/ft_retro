//
// Created by Nickolay PIATIKOP on 2019-06-30.
//

#ifndef INTERCEPTOR_HPP
#define INTERCEPTOR_HPP
#include "Marine.hpp"


class Interceptor : public Marine{
private:

public:
	Interceptor();
	~Interceptor();
	Interceptor(const Interceptor &obj);
	Interceptor &operator=(Interceptor const &rhs);
	void drawmarine();
	Marine *clone()const;
	void movemarine();
};


#endif //INTERCEPTOR_HPP
