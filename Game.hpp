//
// Created by Nickolay PIATIKOP on 2019-06-29.
//

#ifndef GAME_HPP
#define GAME_HPP
#include "Sky.hpp"
#include "Character.hpp"
#include "Squad.hpp"

class Game {
private:
	Squad _squad;
	Sky _sky;
	Character ranger;
	void initColor();
	void keyControl(int key);


public:
	Game();
	~Game();
	Game(const Game &obj);
	Game &operator=(Game const &rhs);
	void play();
//	static Squad const &getSquad();
};


#endif //GAME_HPP
