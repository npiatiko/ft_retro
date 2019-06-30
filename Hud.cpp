#include "Hud.hpp"

Hud::Hud ( void )
{
	this->_start = time(NULL);
	for (int i = 0; i < Y; ++i)
		for (int j = 0; j < X; ++j)
			if (rand() % 100 == 1)
				this->_sky[i][j] = '.';
			else
				this->_sky[i][j] = ' ';
}

Hud::Hud ( Hud const &cpy )
{
	*this = cpy;
}

Hud::~Hud ( void )
{

}

Hud& Hud::operator= ( Hud const &assig )
{
	if (this == &assig)
		return (*this);
	this->_start = assig.getStart();
	for (int i = 0; i < Y; ++i)
	{
		for (int j = 0; j < X; ++j)
		{
			this->_sky[i][j] = assig.getSkyXY(j, i);
		}

	}
	return (*this);
}

time_t Hud::getStart ( void ) const
{
	return (this->_start);
}

float Hud::getTime ( void ) const
{
	return ( time(NULL) - this->_start );
}

std::string Hud::getTimeString ( void ) const
{
	long time = Hud::getTime();
	std::stringstream strStream;

	strStream << std::setfill('0') << std::setw(2) << (time / 60) <<
	" : " << std::setfill('0') << std::setw(2) << (time % 60);
	return (strStream.str());
}

char Hud::getSkyXY ( int const &x, int const &y ) const 
{
	return (this->_sky[y][x]);
}

void Hud::drawHud ( int const &score, int const &lives ) const
{
	std::stringstream tmpStream;
	std::string tmpString;

	attrset(COLOR_PAIR(YELLOW));

	tmpStream << std::setfill('*') << std::setw(X) << "";
	tmpString = tmpStream.str();
	mvprintw(Y, 0, "%s", &tmpString[0]);
	mvprintw(Y + 9, 0, "%s", &tmpString[0]);

	tmpStream.str("");
	tmpStream << " *" << std::setfill(' ') << std::setw(X / 3 - 2) << "*"
	<< " *" << std::setfill(' ') << std::setw(X / 3 - 1) << "*"
	<< " *" << std::setfill(' ') << std::setw(X / 3 - 2) << "*"<< std::endl;
	tmpString = tmpStream.str();
	for (int i = Y + 1; i < (Y + 9); i++)
		mvprintw(i, 0, "%s", &tmpString[0]);

	attrset(COLOR_PAIR(RED));

	tmpStream.str("");
	tmpStream << "Score: " << score;
	tmpString = tmpStream.str();
	mvprintw(Y + 5, X / 6 - tmpString.length() / 2, "%s", &tmpString[0]);

	tmpString = this->getTimeString();
	mvprintw(Y + 5, X / 3 + X / 6 - tmpString.length() / 2, "%s", &tmpString[0]);

	tmpStream.str("");
	tmpStream << "Lives: " << lives << " / 5";
	tmpString = tmpStream.str();
	mvprintw(Y + 5, X / 3 * 2 + X / 6 - tmpString.length() / 2, "%s", &tmpString[0]);
	Hud::drawSky();
}



void Hud::drawSky ( void ) const
{
	static int starty = 0;
	static int speed = 3;

	for (int i = 0; i < Y; ++i)
		for (int j = 0; j < X; ++j)
		{
			attrset(GRAY);
			mvaddch(i, j, this->_sky[i][(j + starty) % X]);
		}
	speed = speed ? speed - 1 : 3;
	if (speed == 3)
		starty = starty == X ? 0 : starty + 1;
}

void Hud::startPause ( void )
{
	this->_pauseTime = time(NULL);

	std::stringstream tmpStream;
	std::string tmpString;

	attrset(COLOR_PAIR(YELLOW));
	tmpStream << std::setfill(' ') << std::setw(23) << "";
	tmpString = tmpStream.str();
	for (int i = Y / 2 - 3; i < (Y / 2 + 3); i++)
		mvprintw(i, X / 2 - tmpString.length(), "%s", &tmpString[0]);
	mvprintw(Y / 2 - 3, X / 2 - tmpString.length() / 2, "%s", "***********************");
	for (int i = -2; i < 4; i++)
		mvprintw(Y / 2 + i, X / 2 - tmpString.length() / 2, "%s", "*                     *");
	mvprintw(Y / 2 + 3, X / 2 - tmpString.length() / 2, "%s", "***********************");
	attrset(COLOR_PAIR(RED));
	tmpString = "Game Paused";
	mvprintw(Y / 2, X / 2 - tmpString.length() / 2, "%s", &tmpString[0]);

	refresh();
}

void Hud::endPause ( void )
{
	this->_pauseTime = time(NULL) - this->_pauseTime;
	this->_start += this->_pauseTime;
}

void Hud::drawEndGame ( int const &score ) const
{
	std::stringstream tmpStream;
	std::string tmpString;

	attrset(COLOR_PAIR(YELLOW));
	tmpStream << std::setfill(' ') << std::setw(41) << "";
	tmpString = tmpStream.str();
	for (int i = Y / 2 - 6; i < (Y / 2 + 6); i++)
		mvprintw(i, X / 2 - tmpString.length(), "%s", &tmpString[0]);
	mvprintw(Y / 2 - 6, X / 2 - tmpString.length() / 2, "%s", "*****************************************");
	mvprintw(Y / 2 + 6, X / 2 - tmpString.length() / 2, "%s", "*****************************************");
	for (int i = -5; i < 6; i++)
		mvprintw(Y / 2 + i, X / 2 - tmpString.length() / 2, "%s", "*                                       *");
	
	attrset(COLOR_PAIR(RED));
	mvprintw(Y / 2 - 3, X / 2 - std::string("Game Over").length() / 2, "%s", "Game Over");
	mvprintw(Y / 2, X / 2 - tmpString.length() / 2 + 7, "%s", "Time spend: XX : XX (m:s)");
	mvprintw(Y / 2 + 3, X / 2 - tmpString.length() / 2 + 7, "%s", "Your score:");

	attrset(COLOR_PAIR(CYAN));
	mvprintw(Y / 2, X / 2 - tmpString.length() / 2 + 19, "%s", &(this->getTimeString())[0]);
	tmpStream.str("");
	tmpStream << score;
	mvprintw(Y / 2 + 3, X / 2 - tmpString.length() / 2 + 19, "%s", &(tmpStream.str())[0]);
}


/*

*****************************************
*                                       *
*                                       *
*               Game Over               *
*                                       *
*                                       *
*       Time spend: XX : XX (m:s)       *
*                                       *
*       Your score:                     *
*                                       *
*                                       *
*****************************************

 */

/*

***********************
*                     *
*                     *
*     Game paused     *
*                     *
*                     *
***********************

 */
