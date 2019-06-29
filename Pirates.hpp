//
// Created by Nickolay PIATIKOP on 2019-06-29.
//

#ifndef PIRATES_HPP
#define PIRATES_HPP

#include "Marine.hpp"


class Pirates : public Marine{
private:

public:
	Pirates();
	~Pirates();
	Pirates(const Pirates &obj);
	Pirates &operator=(Pirates const &rhs);
	void drawmarine();
};


#endif //PIRATES_HPP
