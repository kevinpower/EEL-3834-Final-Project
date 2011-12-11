/* class GameMenu */
/* requires: #include <iostream> in calling */

#include "GameMenu.h"

using namespace std;

/* empty constructor */
GameMenu::GameMenu( )
{

}

/* print yahtzee splash */
void GameMenu::printSplash( )
{
	cout << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << endl << "\\----------------------------------------\\";
  cout << endl << "-  __    __    _     _                   *";
  cout << endl << "-  \\ \\  / /   | |   | |                  *";
  cout << endl << "-   \\ \\V /__ _| |__ | |_ _______  ___    *";
  cout << endl << "-    \\  /   ` | '_ \\| __|_  / _ \\/ _ \\   *";
  cout << endl << "-    | | (_|  | | | | |_ / /  __/  __/   *";
  cout << endl << "-    \\_/\\__,_ |_| |_|\\__/___\\___|\\___|   *";
  cout << endl << "-                                        *";
  cout << endl << "-                  v 0.6                 *";   
  cout << endl << "\\----------------------------------------\\"; 
  cout << endl << endl;
}

/* print main menu */
void GameMenu::printMainMenu( )
{
  cout << endl;
  cout << "(n) - New Game" << endl;
  cout << "(l) - Load Game" << endl;
  cout << "(x) - Exit" << endl;
}

/* print sub menu */
void GameMenu::printSubMenu( )
{
  cout << endl;
  cout << "(r) - Roll Dice" << endl;
  cout << "(p) - Play Dice" << endl;
  cout << "(c) - Current Score and Score Card" << endl;
	cout << "(s) - save game" << endl;
}

/* truncate user input */
void GameMenu::truncateUserInput( string*& puser_input )
{
  if( (*puser_input).size() > 0 )
  {
    (*puser_input) = (*puser_input).at(0);
  }
  else
  {
    (*puser_input) = "x";
  }
}

/* print dashed line */
void GameMenu::printDashedLine( )
{
	cout << "------------------------------------------" << endl;
}
