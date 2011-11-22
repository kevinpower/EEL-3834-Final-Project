#include <iostream> // TEST: for cout, endl
#include <ctime>    // TEST: for time(0)
#include <cstdlib>  // TEST: for srand(), rand()
#include "Die.cpp"  // TEST: for class Die function calls
#include "Dice.cpp" // TEST: for class Dice function calls
#define NUMDICE 5

using namespace std;


/* TESTING CLASSES v0.2 - 21 November 2011 */

/* MAIN */
int main() 
{

  /* Test Die class */

  //Die mydie = Die(0);
  //cout << endl << "Die value: " << mydie.getValue() << endl;
  /* set seed */
  //srand( time( NULL ) );
  /* try rolling */
  //mydie.rollDie();
  //cout << endl << "Die roll: " << mydie.getValue() << endl;
  //mydie.rollDie();
  //cout << endl << "Die roll: " << mydie.getValue() << endl;


  

  /* test Dice class */

  /* set random seed */
  srand( time( NULL ) );

  /* create new instance of dice class */
  Dice new_dice;
  Dice* pnew_dice = &new_dice;

  /* print array contents */
  cout << endl << "die values: ";
  for( int i = 0; i < NUMDICE; i++ ) {
    cout << (new_dice.getDie(i)).getValue() << " ";
  }
  
  /* create array to tell method which die to roll */
  int roll[5] = {1,0,1,0,1};  // 1 -> roll die in that index
  int *proll = &roll[0];      // 0 -> do not roll die in that index
  
  /* roll dice */
  new_dice.rollDice( proll );
  
  /* print array contents */
  cout << endl << "die values: ";
  for( int i = 0; i < NUMDICE; i++ ) {
    cout << (new_dice.getDie(i)).getValue() << " ";
  }

  /* set roll to all '1' */
  proll[1] = 1;
  proll[3] = 1;
  
  /* roll dice */
  new_dice.rollDice( proll );
  
  /* print array contents */
  cout << endl << "die values: ";
  for( int i = 0; i < NUMDICE; i++ ) {
    cout << (new_dice.getDie(i)).getValue() << " ";
  }


  cout << endl;

  return 0;
}

