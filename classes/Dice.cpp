/* class Dice */

#include "Die.h"
#include "Dice.h"
#define NUMDICE 5

using namespace std;

/* empty constructor */
Dice::Dice( ) 
{
  for( int i = 0; i < NUMDICE; i++ ) 
  {
    this->my_dice[i] = Die(1);     // or use "this->myDice[i].setValue(1)"
  } 
}

/* get die */
Die Dice::getDie( int die_number ) 
{
  return ( this->my_dice[ die_number ] );
}

/* put die */
void Dice::putDie( Die the_die, int index )
{
  this->my_dice[ index ] = the_die;
}

/* roll dice */   
void Dice::rollDice( int*& pindex ) 
{
  for( int i = 0; i < NUMDICE; i++ )    // iterate over all the dice
  {                                     
    if( pindex[i] == 1 ) 
    {                                   // if the array has a '1' -> roll the die
      this->my_dice[i].rollDie();       // in the same index
    }
  }
}

/* ask roll dice */
void Dice::askRollDice( )
{
  int roll[5] = {0,0,0,0,0};  // 1 -> roll die in that index
  int *proll = &roll[0];
  string user_input = string();
  string* puser_input = &user_input;
  
  cout << endl;
  cout << "(a) - Roll All Dice" << endl;
  cout << "(s) - Select Die To Roll" << endl;
  cout << "(n) - Do Not Roll" << endl;
  cout << "Selection: ";
  getline( cin, user_input ); 
  cout << endl;

  /* check user input and truncate */
  if( (*puser_input).size() > 0 )
  {
    (*puser_input) = (*puser_input).at(0);
  }
  else
  {
    (*puser_input) = "n";
  }

  /* perform operation */
  if( (*puser_input) == "a" || (*puser_input) == "A" )
  {
    /* set all die to rolling */
    for( int i = 0; i < NUMDICE; i++ )
    {
      proll[i] = 1;
    }
    /* roll dice */
    rollDice( proll );
  }
  else if( (*puser_input) == "s" || (*puser_input) == "S" )
  {
    /* ask which die to roll */
    for( int i = 0; i < NUMDICE; i++ )
    {
      cout << "Roll die #" << i+1 << " ? (y/n): ";
      getline( cin, user_input );
      if( (*puser_input).size() > 0 )
      {
        (*puser_input) = (*puser_input).at(0);
      }
      else
      {
        (*puser_input) = "n";
      }
      
      if( (*puser_input) == "y" || (*puser_input) == "Y" )
      {
        proll[i] = 1;
      }
      else
      {
        proll[i] = 0;
      }
    }
    /* roll selected dice */
    rollDice( proll );
  }

  else
  {
    /* do not roll dice */
  }
     
}

/* reset dice */
void Dice::resetDice( )
{
  for( int i = 0; i < NUMDICE; i++ ) 
  {
    this->my_dice[i].setValue(0);
  }
} 

/* count die values */
int Dice::countDieValues( int value )
{
  
  int count = 0;
  for( int i = 0; i < NUMDICE; i++ )    // iterate over all the die values
  {
    if( (this->my_dice[i]).getValue() == value ) // check if a match
    {
      count++;
    }
  }
  return count;
}

/* sum die values */
int Dice::sumDieValues( )
{
  int sum = 0;
  for( int i = 0; i < NUMDICE; i++ )
  {
    sum += ( this->my_dice[i].getValue() );
  }
  return sum;
}

/* check full house */
bool Dice::checkFullHouse( )
{
  /* full house -> three of one value, two of another value [xxxyy] */
  int die_values [6] = { 0,0,0,0,0,0 }; // represents the number of times
                                        // each value is in our current array
                                        // index 0 -> #1's, index 1 -> # 2's, etc.
  bool three = false;                   // if we have three of one value in Dice
  bool two = false;                     // if we have two of one value in Dice

  /* iterate over dice, filling in die_values */
  for( int i = 0; i < NUMDICE; i++ ) 
  {
    die_values[ (this->my_dice[i]).getValue() - 1 ]++;
  }

  /* check for three and two of one value in die_value */
  /* default size of die_value is 6 */
  for( int i = 0; i < 6; i++ ) 
  {
    if( die_values[i] == 3 )
    {
      three = !three;
    }
    else if ( die_values[i] == 2 )
    {
      /* flip two value -> if found twice will still be false */
      two = !two;
    }
  }
  return three && two;
}
  
/* count straight */
int Dice::countStraight( )
{
  /* create array of bool determining if a die value is present */
  /* default size of 6 -> d6 */
  int die_values[6] = { 0, 0, 0, 0, 0, 0 };
  int count = 0;    
  int max = 0;

  /* find the values currently in the Dice object */
  for( int i = 0; i < NUMDICE; i++)
  {
    die_values[ (this->my_dice[i]).getValue() - 1 ] = 1;    
  }

  /* count the number of consecutive values */
  for( int i = 0; i < NUMDICE; i++ )
  {
    if( die_values[i] == 1 )
    {
      /* consecutive value found -> increase count */
      count++;
    }
    else
    {
      /* a number skipped (not consecutive) */
      /* update max if count is greater than max */
      max = ( ( count > max ) ? count:max );
      /* reset count */
      count = 0;
    }
  }
  /* return count if count is greater than max, else return max */
  /* this returns the largest string of consecutive numbers in the Dice object */
  return ( ( count > max ) ? count:max );
}

/* set value */
void Dice::setValue( int die_number, int value )
{
  /* grab the die from Dice, set the value with Die method */
  ( this->my_dice[ die_number ] ).setValue( value );  
}

/* check yahtzee */
int Dice::checkYahtzee( )
{
  int test = this->my_dice[0].getValue();
  for( int i = 1; i < NUMDICE; i++ )
  {
    if( test == this->my_dice[i].getValue() )
    {
      /* keep looping */
    }
    else
    {
      return 0;
    }
  }
  return 1;
}

/* print dice */
void Dice::printDice( )
{
  for( int i = 0; i < NUMDICE; i++ ) 
  {
    cout << "[" << (this->my_dice[i]).getValue() << "]";
  } 
}
