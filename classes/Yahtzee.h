/* Header file for Yahtzee class */
/* This class created instances of the Yahtzee game */

#ifndef YAHTZEE_H
#define YAHTZEE_H
#define NUMPLAYS 13

/* define class Yahtzee */
class Yahtzee
{
  public:
    Dice my_dice;
    ScorePad my_scorepad;
    GameMenu my_gamemenu;
    int my_played[ NUMPLAYS ];
    int my_numplays;
  
    Yahtzee( );   /* default constructor */
    void newYahtzeeGame( );
    void getUserInput( string*& puser_input );
    void getUserInputInt( string*& puser_input ); 
    int checkSelectionMainMenu( string *& puser_input );
    int tryPlay( string *& puser_input );
		int saveGame( );

};
#endif
