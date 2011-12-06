/* class Die
  handles all function calls associated with die rolling
*/

//#include <iostream> // TEST: for cout, endl
//#include <ctime>    // TEST: for time(0)
//#include <cstdlib>  // TEST: for srand(), rand()
#include "Die.h"
#define DIEMOD 6

using namespace std;

/* cempty onstructor */
Die::Die(  ) 
{
  setValue( 0 );    // initialize to zero if no value specified
}

/* constructor */
Die::Die( int value ) 
{
  setValue( value );
}

/* die roll */
void Die::rollDie( )
{
  Die::rollDie( DIEMOD );
}

/* die roll */
void Die::rollDie( int mod ) 
{
  /* default mod 6 -> number between 0 and 5; add 1 -> number between 1 and 6 */
  this->value = ( ( rand() % mod ) + 1 );  
}

/* set value */
void Die::setValue( int value ) 
{
  this->value = value;
}

