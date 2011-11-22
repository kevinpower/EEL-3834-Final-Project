/* Header file for Dice class */

#ifndef DICE_H
#define DICE_H
#define NUMDICE 5

/* define class Dice */
class Dice : public Die 
{
  private:
    Die myDice[ NUMDICE ]; // array of Die
  public:
    Dice( );    // empty constructor
    Die getDie( int die_number );
    void putDie( Die the_die, int index );
    void rollDice( int*& pindex );
};
#endif
