/* class YahtzeePlay */

#include "YahtzeePlay.h"

using namespace std;

/* empty constructor */
YahtzeePlay::YahtzeePlay( )
{
  /* initialize components */
  this->name = string();
  this->score = 0;
}

/* constructor */
YahtzeePlay::YahtzeePlay( string name, int score )
{
  /* set peramiters with passed in values */
  this->name = name;
  this->score = score;
}

/* get name */
string YahtzeePlay::getName( )
{
  return this->name;
}

/* get score */
int YahtzeePlay::getScore( )
{
  return this->score;
}

/* set name */
void YahtzeePlay::setName( string name )
{
  this->name = name;
}

/* set score */
void YahtzeePlay::setScore( int score )
{
  this->score = score;
}




