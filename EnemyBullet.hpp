//
// Created by Nickolay PIATIKOP on 2019-06-30.
//

#ifndef ENEMYBULLET_HPP
#define ENEMYBULLET_HPP
#include "Marine.hpp"

class EnemyBullet : public Marine{
private:

public:
	EnemyBullet();
	~EnemyBullet();
	EnemyBullet(const EnemyBullet &obj);
	EnemyBullet(const Marine &obj);
	EnemyBullet &operator=(EnemyBullet const &rhs);
	void movemarine();
	Marine *clone()const;

};


#endif //ENEMYBULLET_HPP
