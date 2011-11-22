/* class Dice */

#include "Die.h"
#include "Dice.h"
#define NUMDICE 5

using namespace std;

/* empty constructor */
Dice::Dice( ) 
{
  for( int i = 0; i < NUMDICE; i++ ) {
    this->myDice[i] = Die(0);     // or use "this->myDice[i].setValue(0)"
  } 
}

/* get die */
Die Dice::getDie( int die_number ) 
{
  return ( this->myDice[ die_number ] );
}

/* put die */
void Dice::putDie( Die the_die, int index )
{
  this->myDice[ index ] = the_die;
}

/* roll dice */   
void Dice::rollDice( int*& pindex ) 
{
  for( int i = 0; i < NUMDICE; i++ ) {  // iterate over all the dice
    if( pindex[i] == 1 ) {              // if the array has a '1' -> roll the die
      this->myDice[i].rollDie();        // in the same index
    }
  }
}

