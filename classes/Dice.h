/* Header file for Dice class */

#ifndef DICE_H
#define DICE_H
#define NUMDICE 5

/* define class Dice */
class Dice : public Die 
{
  private:
    Die my_dice[ NUMDICE ]; // array of Die
  public:
    Dice( );    // empty constructor
    Die getDie( int die_number );
    void putDie( Die the_die, int index );
		void rollDice( );
    void rollDice( int*& pindex );
    void askRollDice( );
    void resetDice( );
    int countDieValues( int value );
    int sumDieValues( );
    bool checkFullHouse( );
    int countStraight( );
    void setValue( int die_number, int value );
    int checkYahtzee( );
    void printDice( );
};
#endif
