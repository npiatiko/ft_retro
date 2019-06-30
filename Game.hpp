//
// Created by Nickolay PIATIKOP on 2019-06-29.
//

#ifndef GAME_HPP
# define GAME_HPP
# include "Character.hpp"
# include "Squad.hpp"
# include "Hud.hpp"

class Game {
private:
	Squad _squad;
	Character ranger;
	void initColor();
	void keyControl(int key);
	Hud _hud;
	int _score;
public:
	static Squad &getSquad();
	Game();
	~Game();
	Game(const Game &obj);
	Game &operator=(Game const &rhs);
	void play();
};


#endif //GAME_HPP
