#ifndef HUD_HPP
# define HUD_HPP

# include <iostream>
# include <string>
# include <ctime>
# include <iomanip>
# include <sstream>
# include "Colors.hpp"

class Hud
{
private:
	unsigned int _score;
	unsigned int _lives;
	time_t _start;
	char _sky[X][Y];
	time_t _pauseTime;
	void drawSky( void ) const;
public:
	Hud ( void );
	Hud ( unsigned int const &, unsigned int & );
	Hud ( Hud const & );
	~Hud ( void );

	Hud& operator= ( Hud const & );

	unsigned int getScore ( void ) const;
	unsigned int getLives ( void ) const;
	time_t getStart ( void ) const;
	float getTime ( void ) const;
	std::string getTimeString ( void ) const;
	char getSkyXY ( int const &, int const & ) const;

	void drawHud ( void ) const;

	void startPause ( void );
	void endPause ( void );
};


#endif
