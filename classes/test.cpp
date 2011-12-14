#include <iostream> // TEST: for cout, endl
#include <ctime>    // TEST: for time(0)
#include <cstdlib>  // TEST: for srand(), rand()
#include <string>   // TEST: for YahtzeePlay strings (names)
#include "Die.cpp"  // TEST: for class Die function calls
#include "Dice.cpp" // TEST: for class Dice function calls
#include "YahtzeePlay.cpp" // TEST: for class YahtzeePlay
#include "ScorePad.cpp" // TEST: for class ScorePad
#define NUMDICE 5
#define NUMPLAYS 13

using namespace std;


/* TESTING CLASSES v0.3 - 28 November 2011 */

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
  cout << endl << "-- TESTING -- "  << endl;
  cout<< endl << "TEST: Classes Die and Dice";

  /* set random seed */
  srand( time( NULL ) );

  /* create new instance of dice class */ 
  Dice* new_dice = new Dice();

  /* print array contents */
  cout << endl << "die values: ";
  for( int i = 0; i < NUMDICE; i++ ) 
  {
    cout << ( (*new_dice).getDie(i) ).getValue() << " ";
  }
 
  /* create array to tell method which die to roll */
  int roll[5] = {1,0,1,0,1};  // 1 -> roll die in that index
  int *proll = &roll[0];      // 0 -> do not roll die in that index
  
  /* roll dice */
  cout << endl << "Rolling dice..";
  (*new_dice).rollDice( proll );
  
  /* print array contents */
  cout << endl << "die values: ";
  for( int i = 0; i < NUMDICE; i++ ) 
  {
    cout << ( (*new_dice).getDie(i) ).getValue() << " ";
  }

  /* set roll to all '1' */
  proll[1] = 1;
  proll[3] = 1;
  
  /* roll dice */
  cout << endl << "Rolling dice..";
  (*new_dice).rollDice( proll );
  
  /* print array contents */
  cout << endl << "die values: ";
  for( int i = 0; i < NUMDICE; i++ ) 
  {
    cout << ( (*new_dice).getDie(i) ).getValue() << " ";
  }

  /* sum die values */
  cout << endl << "Die values summed: " << (*new_dice).sumDieValues();

  /* check full house */
  cout << endl << "Full house: " << (*new_dice).checkFullHouse( );

  /* count straight */
  cout << endl << "Number of consecutive die values: " << (*new_dice).countStraight();
  
  /* count number of a particular value */
  cout << endl << "Number of '3's in our dice currently: " 
  << (*new_dice).countDieValues( 3 );

  /* set values to check full house */
  cout << endl << "Setting dice for full house..";
  (*new_dice).setValue( 0, 3 );
  (*new_dice).setValue( 1, 3 );
  (*new_dice).setValue( 2, 3 );
  (*new_dice).setValue( 3, 6 );
  (*new_dice).setValue( 4, 6 );

  /* print array contents */
  cout << endl << "die values: ";
  for( int i = 0; i < NUMDICE; i++ ) 
  {
    cout << ( (*new_dice).getDie(i) ).getValue() << " ";
  }
  
  /* check full house */
  cout << endl << "Full house: " << (*new_dice).checkFullHouse( );

  /* reset dice */
  cout << endl << "Resetting dice..";
  (*new_dice).resetDice();

  /* print array contents */
  cout << endl << "die values: ";
  for( int i = 0; i < NUMDICE; i++ ) 
  {
    cout << ( (*new_dice).getDie(i) ).getValue() << " ";
  }

  /* sum die values */
  cout << endl << "Die values summed: " << (*new_dice).sumDieValues();

  /* set values to check straight */
  cout << endl << "Setting dice for straight..";
  (*new_dice).setValue( 0, 1 );
  (*new_dice).setValue( 1, 2 );
  (*new_dice).setValue( 2, 3 );
  (*new_dice).setValue( 3, 4 );
  (*new_dice).setValue( 4, 5 );

  /* print array contents */
  cout << endl << "die values: ";
  for( int i = 0; i < NUMDICE; i++ ) 
  {
    cout << ( (*new_dice).getDie(i) ).getValue() << " ";
  }

  /* count straight */
  cout << endl << "Number of consecutive die values: " << (*new_dice).countStraight();

  cout << endl;


  /* Test Class YahtzeePlay */
  cout << endl << "TEST: Class YahtzeePlay";
  
  /* create new instance(s) of yahtzeeplay class */ 
  YahtzeePlay* play1 = new YahtzeePlay();
  YahtzeePlay* play2 = new YahtzeePlay( "play2", 42 );

  /* print constructed contents (showing instance creation) */
  cout << endl << "Play1 name: " << (*play1).getName();
  cout << endl << "Play1 score: " << (*play1).getScore();
  cout << endl << "Play2 name: " << (*play2).getName();
  cout << endl << "Play2 score: " << (*play2).getScore();

  /* change data */
  cout << endl << "Changing data...";
  (*play1).setName( "play1");
  (*play1).setScore( 111 );
  (*play2).setScore( 43 );

  /* re-print contents*/
  cout << endl << "Play1 name: " << (*play1).getName();
  cout << endl << "Play1 score: " << (*play1).getScore();
  cout << endl << "Play2 name: " << (*play2).getName();
  cout << endl << "Play2 score: " << (*play2).getScore();
 
  cout << endl;

  
  /* Test Class ScorePad */
  cout << endl << "TETS: Class ScorePad";

  /* create new instance of scorepad */
  ScorePad* my_scorepad = new ScorePad();

  /* set scores */
  cout << endl << "Setting scores..";
  (*my_scorepad).setScore( 0, 50 );
  (*my_scorepad).setScore( 4, 51 );

  (*my_scorepad).setName( 0, "ones" );
  (*my_scorepad).setName( 12, "Yahtzee" );

  cout << endl << "Score0: " << (*my_scorepad).getScore( 0 );
  cout << endl << "Score4: " << (*my_scorepad).getScore( 4 );
  cout << endl << "Score12: " << (*my_scorepad).getScore( 12 );

  /* print total score */
  cout << endl << "Total Score: " << (*my_scorepad).calculateTotalScore();

  cout << endl << "Name0: " << (*my_scorepad).getName(0);
  cout << endl << "Name12: " << (*my_scorepad).getName(12);

  /* check played */
  cout << endl << "Play7 played: " << (*my_scorepad).checkIfPlayed( 7 );
  /* set play0 to played */
  cout << endl << "Play7 now played..";
  (*my_scorepad).setPlayed( 7 );
  /* check played */
  cout << endl << "Play7 played: " << (*my_scorepad).checkIfPlayed( 7 );  

  /* check default names */
  cout << endl << "Setting default names..";
  (*my_scorepad).setDefaultNames( );
  cout << endl << "Play11: " << (*my_scorepad).getName( 11 );
  cout << endl << "Play6: " << (*my_scorepad).getName( 6 );


  cout << endl;

  return 0;
}

