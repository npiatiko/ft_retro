#include "Hud.hpp"

Hud::Hud ( void ): _score(0),
					_lives(5)
{
	this->_start = time(NULL);
	for (int i = 0; i < Y; ++i)
		for (int j = 0; j < X; ++j)
			if (rand() % 100 == 1)
				this->_sky[i][j] = '.';
			else
				this->_sky[i][j] = ' ';
}

Hud::Hud ( unsigned int const &score, unsigned int &lives ): _score(score),
																_lives(lives)
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
	this->_score = assig.getScore();
	this->_lives = assig.getLives();
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

unsigned int Hud::getScore ( void ) const
{
	return (this->_score);
}

unsigned int Hud::getLives ( void ) const
{
	return (this->_lives);
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

void Hud::drawHud ( void ) const
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
	tmpStream << "Score: " << this->getScore();
	tmpString = tmpStream.str();
	mvprintw(Y + 5, X / 6 - tmpString.length() / 2, "%s", &tmpString[0]);

	tmpString = this->getTimeString();
	mvprintw(Y + 5, X / 3 + X / 6 - tmpString.length() / 2, "%s", &tmpString[0]);

	tmpStream.str("");
	tmpStream << "Lives: " << this->getLives() << " / 5";
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
	mvprintw(Y / 2 - 2, X / 2 - tmpString.length() / 2, "%s", "*                     *");
	mvprintw(Y / 2 - 1, X / 2 - tmpString.length() / 2, "%s", "*                     *");
	mvprintw(Y / 2, X / 2 - tmpString.length() / 2, "%s", "*                     *");
	mvprintw(Y / 2 + 1, X / 2 - tmpString.length() / 2, "%s", "*                     *");
	mvprintw(Y / 2 + 2, X / 2 - tmpString.length() / 2, "%s", "*                     *");
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

/*

***********************
*                     *
*                     *
*     Game paused     *
*                     *
*                     *
***********************

 */