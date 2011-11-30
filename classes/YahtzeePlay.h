/* Header file for YahtzeePlay class */
/* This class defines an instance of an acceptable Yahtzee move */

#ifndef YAHTZEEPLAY_H
#define YAHTZEEPLAY_H

/* define class YahtzeePlay */
class YahtzeePlay
{
  private:
    string name;
    int score;
  public:
    YahtzeePlay( );  // empty constructor
    YahtzeePlay( string name, int score );
    string getName( );
    int getScore( );
    void setName( string name );
    void setScore( int score );
};
#endif
