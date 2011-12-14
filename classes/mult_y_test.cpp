/* testing calling multiple instances of Yahtzee class */

#include "Yahtzee.cpp"
#define NUMPLAYS 13
#define MAXROLLS 3

using namespace std;

void play( int index, Yahtzee*& pyahtzee_games );

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
	int num_players;	// number of players
  string user_input = string(); // user input
  string* puser_input = &user_input;  // user input pointer
  
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
	/* ask user how many players */
	cout << endl << "Enter the number of players: ";
	/* grab user input */
  (*my_yahtzee).getUserInputInt( puser_input );
	/* convert string to int */
	stringstream ss( *puser_input );
	ss >> num_players;
	/* create game instances */
	Yahtzee yahtzee_games[ num_players ];
	Yahtzee* pyahtzee_games[ num_players ];

	for( int i = 0; i < num_players; i++ )
	{
		cout << endl << "------creating game " << i+1 << "------" << endl;
		yahtzee_games[i].newYahtzeeGame();
		pyahtzee_games[i] = &yahtzee_games[i];
	}
    
  /* each player gets 13 plays with a maximum of 3 rolls per play 
   * only one play may be made for each category
   */

	/* outside for loop for looping through all 13 plays */
  for( int i = 0; i < NUMPLAYS; i++ )
  {
		/* inner for loop for looping through each player for each play */
		for( int j = 0; j < num_players; j++ )
		{
			cout << endl << endl << endl << endl << endl << endl;
			cout << endl << endl << endl << endl << endl << endl;
			cout << endl << "Player " << j+1 << "'s turn " << i+1 << "." << endl;
			(*pyahtzee_games[j]).my_dice.printDice();
			play( j, pyahtzee_games[j] );
		}
	}
  return 0;
}


/* play */
void play( int index, Yahtzee*& pyahtzee_games )
{
	int roll_count = 0;
  string user_input = string(); // user input
  string* puser_input = &user_input;  // user input pointer
  /* print options to user 
   * options:
   * (r) - Roll Dice
   * (p) - Play Dice
   * (c) - Current Score
   */

	while( roll_count < 3 )
	{
  	(*pyahtzee_games).my_gamemenu.printSubMenu( );  
    
  	/* grab user input */
  	(*pyahtzee_games).getUserInput( puser_input );

		/* print dashed line */
		(*pyahtzee_games).my_gamemenu.printDashedLine( );

  	/* check selection */ 
  	if( *puser_input == "r" || *puser_input == "R" )
  	{
			/* check if roll_count == 0; if so must roll all dice */
			if( roll_count == 0 )
			{
				cout << "Rolling all die for roll 1 of 3." << endl;
				/* force rolling of all dice */
				(*pyahtzee_games).my_dice.rollDice();
				(*pyahtzee_games).my_dice.printDice();
				cout << endl;
				(*pyahtzee_games).my_gamemenu.printDashedLine();
      	/* increment roll count */
      	roll_count++;
			}	
    	/* check if number of rolls is less than three */
    	else if( roll_count < MAXROLLS )
    	{
				cout << endl << "On Roll " << roll_count + 1 << " of 3" << endl;
      	(*pyahtzee_games).my_dice.printDice();
      	(*pyahtzee_games).my_dice.askRollDice();
      	(*pyahtzee_games).my_dice.printDice();
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
    		cout << endl << "You have not rolled this play." << endl;
    	}
    	else 
    	{
    		/* user wants to play his or her dice */
    	  int played = 0;
    	  /* print scorepad */
    	  (*pyahtzee_games).my_scorepad.printScorePad( );
    	  while( !played )
    	  {
					/* print current dice values */
					cout << endl << "Dice: ";
					(*pyahtzee_games).my_dice.printDice();
    	    cout << endl << "Which play (1-13) would you like "
    	         << "to make: ";
    	    /* grab user input */
    	    (*pyahtzee_games).getUserInputInt( puser_input );
    	    played = (*pyahtzee_games).tryPlay( puser_input );
					/* print dashed line */
					cout << endl;
					(*pyahtzee_games).my_gamemenu.printDashedLine( ); 
    	  }
    	  /* print updated score pad */
    	  (*pyahtzee_games).my_scorepad.printScorePad();
    	  /* print number of plays made */
    	  cout << "Number of plays made: " << (*pyahtzee_games).my_numplays
    	       << endl;
				/* print dashed line */
				(*pyahtzee_games).my_gamemenu.printDashedLine( );
    	}  
    	/* set max roll count to break from loop */
    	roll_count = 3;   
  	}
		else if ( *puser_input == "c" || *puser_input == "C" )  
  	{
  		/* user want his or her curent score and score card */
			/* print scorepad */
    	(*pyahtzee_games).my_scorepad.printScorePad( );
    	cout << "Total Score: " 
      	   << (*pyahtzee_games).my_scorepad.calculateTotalScore() << endl;
			/* print dashed line */
			cout << endl;
			(*pyahtzee_games).my_gamemenu.printDashedLine( );
  	}
		else if( *puser_input == "l" || *puser_input == "L" )
		{
			/* user wished to load a game for this player */
    	cout << endl << "Loading game for current player.." << endl;
		/* assume file to load is in same directory and named "yahtzee_save.txt"
		/* file should be in the format:
		 * [yahtzee_save.txt]
		 * playscore;if_played 
     * ...
		 * ...
		 * [repeated 13 times]
		 * ...
		 * total_number_of_plays_made
		 * [end file]
		 */

		/* open file */
		ifstream my_file;
		my_file.open("yahtzee_save.txt");
		if( my_file.fail() )
		{
			cout << endl << "Error opening save file.." << endl;
			break;
		}
		
		/* read in data elements and set the appropriately 
		 * first iterate over number of plays; eac line is the respective score 
		 * and if that score has been played 
		 */
		
		string s;
		int n;
		for( int i = 0; i < NUMPLAYS; i++ )
		{
			/* read in first data element */
			getline( my_file, s, ';');
			/* convert string to integer */
			stringstream ss( s );
			ss >> n;
			/* save value into score pad index */
			(*pyahtzee_games).my_scorepad.setScore( i, n);
			/* read in if_played */
			getline( my_file, s, '\n' );
			/* convert string to integer */
			stringstream sss( s );
			sss >> n;
			/* save in my_played */
			(*pyahtzee_games).my_played[ i ] = n;
			if( n == 1)
			{
				(*pyahtzee_games).my_scorepad.setPlayed( i );
			}
		}			
		/* grab last piece of data - number of plays made */
		getline( my_file, s );
		/* convert string to integer */
		stringstream ss( s );
		ss >> n;
		/* save number of plays made */
		(*pyahtzee_games).my_numplays = n;
		}	
		else if( *puser_input == "s" || *puser_input == "S" )
		{
			/* user wished to save the current game */
			/* grab current game state and send to file using vectors */
			/* print dashed line */
			cout << endl;
			(*pyahtzee_games).my_gamemenu.printDashedLine( );
			cout << "Saving game.." << endl;
			(*pyahtzee_games).saveGame( );
		}	
  	else 
  	{
  		/* not a valid selection */
  	}	
	}
}  
 

