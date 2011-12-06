/* class ScorePad */

#include "ScorePad.h"
#include "YahtzeePlay.h"
#define NUMPLAYS 13 // default number of moves in Yahtzee is 13 plays

using namespace std;

/* empty constructor */
ScorePad::ScorePad( )
{
  for( int i = 0; i < NUMPLAYS; i++ )
  {
    this->my_yahtzee_play[i] = YahtzeePlay();
    this->played[i] = 0;
  }
}

/* get yahtzeeplay */
YahtzeePlay ScorePad::getYahtzeePlay( int index )
{
  return (this->my_yahtzee_play[ index ] );
}

/* set default names */
void ScorePad::setDefaultNames( )
{
  /* set default names for all valid moves in yahtzee (13 of them) */
  my_yahtzee_play[ 0 ].setName( "Ones" );
  my_yahtzee_play[ 1 ].setName( "Twos" );
  my_yahtzee_play[ 2 ].setName( "Threes" );
  my_yahtzee_play[ 3 ].setName( "Fours" );
  my_yahtzee_play[ 4 ].setName( "Fives" );
  my_yahtzee_play[ 5 ].setName( "Sixes" );
  my_yahtzee_play[ 6 ].setName( "Three of a Kind" );
  my_yahtzee_play[ 7 ].setName( "Four of a Kind" );
  my_yahtzee_play[ 8 ].setName( "Full House" );
  my_yahtzee_play[ 9 ].setName( "Small Straight" );
  my_yahtzee_play[ 10 ].setName( "Large Straight" );
  my_yahtzee_play[ 11 ].setName( "Chance" );
  my_yahtzee_play[ 12 ].setName( "Yahtzee" );
  
}

/* set played */
void ScorePad::setPlayed( int index )
{
  this->played[ index ] = 1;
}

/* get played */
int ScorePad::getPlayed( int index )
{
  return ( this->played[ index ] );
}

/* check if played */
int ScorePad::checkIfPlayed( int index )
{
  return ( (this->played[index])==1?1:0 );
}

/* get name */
string ScorePad::getName( int index )
{
  return ( (this->my_yahtzee_play[ index ]).getName() );
}

/* set name */
void ScorePad::setName( int index, string name )
{
  ( this->my_yahtzee_play[index] ).setName( name );
}

/* get score */
int ScorePad::getScore( int index )
{
  return ( (this->my_yahtzee_play[ index ]).getScore() );
}

/* set score */
void ScorePad::setScore( int index, int score )
{
  ( this->my_yahtzee_play[index] ).setScore( score );
}

/* reset scores */
void ScorePad::resetScores( )
{
  for( int i = 0; i < NUMPLAYS; i++ )
  {
    ( this->my_yahtzee_play[i] ).setScore( 0 );
  }
}

/* calculate total score */
int ScorePad::calculateTotalScore( )
{
  int total = 0;
  /* iterate over yahtzeeplay instances, grabbing their respective scores */
  for( int i = 0; i < NUMPLAYS; i++ )
  {
    total += (this->my_yahtzee_play[i]).getScore();
  }
  return total;
}

/* print score pad */
void ScorePad::printScorePad( )
{
  /* iterate over all YahtzeePlays, printing their name and current score */
  cout << endl << "---------- Score Pad ----------";
  cout << endl << "| Move - Score                 |";
  cout << endl << "-------------------------------";
  for( int i = 0; i < NUMPLAYS; i++ )
  {
    cout << endl << "| " << i+1 << ". " << (this->my_yahtzee_play[i].
    getName()) << " - " << (this->my_yahtzee_play[i].getScore());
  }
  cout << endl << "-------------------------------" << endl;
}
