/* testing calling an instance of Yahtzee class
 * which creates a new Yahtzee game
 */

#include "Yahtzee.cpp"
#define NUMPLAYS 13
#define MAXROLLS 3

using namespace std;

int main()
{
  Yahtzee* my_yahtzee = new Yahtzee( );
  /* public elements:
   * Dice my_dice
   * ScorePad my_scorepad
   * GameMenu my_gamemenu
   */

  
  /* -- start program -- */
  
  /* variables */
  int run = 1;  // run condition
  string user_input = string(); // user input
  string* puser_input = &user_input;  // user input pointer
  
  while( run )
  {
    /* print splash screen */
    (*my_yahtzee).my_gamemenu.printSplash( );
  
    /* print main menu */
    (*my_yahtzee).my_gamemenu.printMainMenu( );

    /* grab user input */
    (*my_yahtzee).getUserInput( puser_input );

    /* check selection */
    if( (*my_yahtzee).checkSelectionMainMenu( puser_input ) == 0 )
    {
      /* exit program */
      return 0;
    }

    /* start playing */
    
    /* each player gets 13 plays with a maximum of 3 rolls per play 
     * only one play may be made for each category
     */

    while( (*my_yahtzee).my_numplays < 13 )
    {
      static int roll_count = 0;
      /* print options to user 
       * options:
       * (r) - Roll Dice
       * (p) - Play Dice
       * (c) - Current Score
       */
      (*my_yahtzee).my_gamemenu.printSubMenu( );  
    
      /* grab user input */
      (*my_yahtzee).getUserInput( puser_input );

      /* check selection */ 
      if( *puser_input == "r" || *puser_input == "R" )
      {
        /* user wants to roll dice */
        /* check if number of rolls is less than three */
        if( roll_count < MAXROLLS )
        {
          (*my_yahtzee).my_dice.printDice();
          (*my_yahtzee).my_dice.askRollDice();
          (*my_yahtzee).my_dice.printDice();
          /* increment roll count */
          roll_count++;
        }
        else
        {
          /* number of rolls exceeds the max amount */
          cout << "You have already rolled 3 times, cannot roll again "
               <<  "before playing a move.";
        }
      }
      else if ( *puser_input == "p" || *puser_input == "P" )
      {
        /* make sure played rolled at least once before playing */
        if( roll_count == 0 )
        {
          cout << endl << "You have not rolled this play." << endl;;
        }
        else 
        {
          /* user wants to play his or her dice */
          int played = 0;
          /* print scorepad */
          (*my_yahtzee).my_scorepad.printScorePad( );
          while( !played )
          {
            cout << endl << "Which play (1-13) would you like "
                << "to make: ";
            /* grab user input */
            (*my_yahtzee).getUserInputInt( puser_input );
            played = (*my_yahtzee).tryPlay( puser_input ); 
          }
          /* print updated score pad */
          (*my_yahtzee).my_scorepad.printScorePad();
        }  
        /* reset roll count */
        roll_count = 0;   
      }
      else if ( *puser_input == "c" || *puser_input == "C" )  
      {
        /* user want his or her curent score */
        cout << endl << "Total Score: " 
            << (*my_yahtzee).my_scorepad.calculateTotalScore() << endl;
      }
      else 
      {
        /* not a valid selection */
      }
    }  
 
    /* finished playing */
    cout << endl << "Congrats, you have finished the game.";
    cout << "Your total score was: " << (*my_yahtzee).my_scorepad
      .calculateTotalScore() << endl;
    /* have a function that asks user to play again here (that sets run)*/
    run = 0;
  } 
  return 0;
}