/* class die
  handles all function calls associated with die rolling
*/

#include <cstdlib>    // for srand(), rand()
#include <iostream>   // for cout, endl
#include <ctime>      // for time(0)
#include "Die.h"

using namespace std;

/* constructor */
Die::Die(  ) {
  setValue( 0 );
}

/* constructor */
Die::Die( int value ) {
  setValue( value );
}

/* set rand seed */
void Die::setRandSeed( int seed ) {
  srand( seed );
}

/* die roll */
void Die::dieRoll( int mod = 6 ) {
  /* default mod 6 -> number between 0 and 5; add 1 -> number between 1 and 6 */
  value = ( rand() % mod ) + 1;   
}

/* set value */
void Die::setValue( int value ) {
  this->value = value;
}




/* TESTING */

/* MAIN */
int main() {
  Die mydie;
  cout << endl << "Die value: " << mydie.getValue() << endl;
  // set seed
  mydie.setRandSeed( time(0) );
  mydie.dieRoll();
  cout << endl << "Die roll: " << mydie.getValue() << endl;
  mydie.dieRoll();
  cout << endl << "Die roll: " << mydie.getValue() << endl;


  return 0;
}

