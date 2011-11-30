/* Header file for ScorePad class */
/* This class defines instances of class YahtzeePlay for a player */

#ifndef SCOREPAD_H
#define SCOREPAD_H
#define NUMPLAYS 13 // default number of moves in Yahtzee is 13 plays

/* define class ScorePad */
class ScorePad : public YahtzeePlay
{
  private:
    YahtzeePlay my_yahtzee_play[ NUMPLAYS ];  // array of yahtzee moves for the player 
    int played[ NUMPLAYS ]; // array of ints determining if the index
                            // correspinding to that yahtzee move was played
  public:
    ScorePad( );  // empty constructor
    YahtzeePlay getYahtzeePlay( int index );
    void setDefaultNames( );
    void setPlayed( int index );
    int getPlayed( int index );
    int checkIfPlayed( int index );
    string getName( int index );
    void setName( int index, string name );
    int getScore( int index );
    void setScore( int index, int score );
    void resetScores( );
    void playRoll( Dice*& pmy_dice ); // ---- WRITE THIS USING isdigit (cctype)
    int calculateTotalScore( );
    
};
#endif
