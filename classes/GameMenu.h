/* Header file for GameMenu class */
/* This class prints the game menu and scorecard to the screen */

#ifndef GAMEMENU_H
#define GAMEMENU_H

/* define class GameMenu */
class GameMenu
{
  public:
    GameMenu( );
    void printSplash( );
    void printMainMenu( );
    void printSubMenu( );
    void truncateUserInput( string*& puser_input );
		void printDashedLine( );
};
#endif
