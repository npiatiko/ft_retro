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
	time_t _start;
	char _sky[X][Y];
	time_t _pauseTime;
	void drawSky( void ) const;
public:
	Hud ( void );
	Hud ( Hud const & );
	~Hud ( void );

	Hud& operator= ( Hud const & );

	unsigned int getScore ( void ) const;
	unsigned int getLives ( void ) const;
	time_t getStart ( void ) const;
	float getTime ( void ) const;
	std::string getTimeString ( void ) const;
	char getSkyXY ( int const &, int const & ) const;

	void drawHud ( int const &, int const & ) const;

	void startPause ( void );
	void endPause ( void );
};


#endif
