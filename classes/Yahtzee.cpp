/* class Yahtzee */
/* requires: #include <iostream> in calling */

using namespace std;

#include <iostream> // for cout, endl, file io
#include <ctime>    // for time(0)
#include <cstdlib>  // for srand(), rand()
#include <string>   // for YahtzeePlay strings (names)
#include <sstream>  // for conversion from string types
#include <cctype>   // for isalpha
#include <vector> 	// for vector operations
#include <fstream>	// for file io
#include "Die.cpp"  // for class Die function calls
#include "Dice.cpp" // for class Dice function calls
#include "YahtzeePlay.cpp" // for class YahtzeePlay
#include "ScorePad.cpp" // for class ScorePad
#include "GameMenu.cpp" // for class GameMenu
#include "Yahtzee.h"  // for class Yahtzee

#define NUMDICE 5
#define NUMPLAYS 13

/* empty constructor */
Yahtzee::Yahtzee( )
{
  /* initialize game menu for user */
  this->my_gamemenu = GameMenu( );
}

/* new yahtzee game */
void Yahtzee::newYahtzeeGame( )
{
  /* initialize game components */
  this->my_dice = Dice( );
  this->my_scorepad = ScorePad( );
  this->my_scorepad.setDefaultNames( );
  /* set randum number generator seed */
  srand( time( NULL ) );
  /* set played array */
  for( int i = 0; i < NUMPLAYS; i++ )
  {
    this->my_played[i] = 0;
  } 
  this->my_numplays = 0;   
}

/* get user input */
void Yahtzee::getUserInput( string*& puser_input )
{
  int go = 1;
  cout << endl << "Selection: ";
  while( go )
  {
    /* get user input string */
    getline( cin, *puser_input );
    
    /* check size */
    if( (*puser_input).size() > 0 )
    {
      /* size is greater than zero; check for alphabetic character */
      if( isalpha( (*puser_input).at(0) ) )
      {
        /* user character in first position if valid */
        (*puser_input) = (*puser_input).at( 0 );
        go = 0;
      }
      else
      {
        /* invalid input */
        cout << endl << "Invalid choice, new selection: ";
      }
    }
    else
    {
      /* size less than or equal to zero; invalid input */
      cout << endl << "Invalid choice, new selection: ";
    }   
  } 
}

/* get user input int */
void Yahtzee::getUserInputInt( string*& puser_input )
{
  int go = 1;
  cout << endl << "Selection: ";
  while( go )
  {
    /* get user input string */
    getline( cin, *puser_input );
    
    /* check size */
    if( (*puser_input).size() > 0 )
    {
      /* size is greater than zero; check for numeric data */
      int value = atoi( (*puser_input).c_str() );
      if( value >= 1 && value <= 13 )
      {
        /* string is valid */
        go = 0;
      }
      else
      {
        /* invalid input */
        cout << endl << "Invalid choice, new selection: ";
      }
    }
    else
    {
      /* size less than or equal to zero; invalid input */
      cout << endl << "Invalid choice, new selection: ";
    }   
  } 
}

/* check selection main menu */
int Yahtzee::checkSelectionMainMenu( string *& puser_input )
{
  /* options are:
   * (n) - New Game
   * (l) - Load Game
   * (x) - Exit
   */

  /* check for (n) */
  if( *puser_input == "n" || *puser_input == "N" )
  {
    /* start new game */
    cout << endl << "Starting New Game.." << endl;
    newYahtzeeGame();
    return 1;
  }
  else if ( *puser_input == "l" || *puser_input == "L" )
  {
    /* load game */
    
    cout << endl << "Loading Game.." << endl;
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
    
		/* create game elements */
		newYahtzeeGame();
		/* open file */
		ifstream my_file;
		my_file.open("yahtzee_save.txt");
		if( my_file.fail() )
		{
			return 0;
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
			(this->my_scorepad).setScore( i, n);
			/* read in if_played */
			getline( my_file, s, '\n' );
			/* convert string to integer */
			stringstream sss( s );
			sss >> n;
			/* save in my_played */
			this->my_played[ i ] = n;
			if( n == 1)
			{
				(this->my_scorepad).setPlayed( i );
			}
		}			
		/* grab last piece of data - number of plays made */
		getline( my_file, s );
		/* convert string to integer */
		stringstream ss( s );
		ss >> n;
		/* save number of plays made */
		this->my_numplays = n;

    return 1;
  }
  else if ( *puser_input == "x" || *puser_input == "X" )
  {
    /* exit program - do nothing */
    cout << endl << "Exiting Program.." << endl;
    return 0;
  }
  else
  {
    /* not a valid selection, exit program  - do nothing */
    cout << endl << "Your selection was invalid..exiting" << endl;
    return 0;
  }
}

/* try play */
int Yahtzee::tryPlay( string *& puser_input )
{
  /* convert user input into integer */
  int input = atoi( (*puser_input).c_str() );
  /* need to make sure play was not already played */
  if( this->my_played[ input-1 ] == 1 )
  {
    /* play was already made */
    cout << endl << "Play already made. Please make a new selection.";
    return 0;
  }
  else
  {
    /* play is valid, ok to score */
    /* ones to sixes */
    if( input >= 1 && input <= 6 )
    {
      /* play "ones" through "sixes" */
      this->my_scorepad.setScore( (input)-1, (input)*
        (this->my_dice).countDieValues(input) );      
    }
    /* three of a kind*/
    else if( input == 7 )
    {
      /* make sure dice have three of a kind */
      for( int i = 0; i < NUMDICE; i++ )
      {
        if( (this->my_dice).countDieValues(i) >= 3 )
        {
          this->my_scorepad.setScore( (input)-1, 
            (this->my_dice).sumDieValues() );
        }
      }
    }
    /* four of a kind*/
    else if( input == 8 )
    {
      /* make sure dice have three of a kind */
      for( int i = 0; i < NUMDICE; i++ )
      {
        if( (this->my_dice).countDieValues(i) >= 4 )
        {
          this->my_scorepad.setScore( (input)-1, 
            (this->my_dice).sumDieValues() );
        }
      }
    }
    /* full house */
    else if( input == 9 )
    {
      /* check full house, only score if full house present */
      if( (this->my_dice).checkFullHouse() == 1 )
      {
        this->my_scorepad.setScore( (input)-1, 25 );
      }
    }
    /* small straight */
    else if( input == 10 )
    {
      if( (this->my_dice).countStraight() >= 4 )
      {
        this->my_scorepad.setScore( (input)-1, 30 );
      }
    }
    /* large straight */
    else if( input == 11 )
    {
      if( (this->my_dice).countStraight() >= 5 )
      {
        this->my_scorepad.setScore( (input)-1, 40 );
      }
    }
    /* chance */
    else if( input == 12 )
    {
      this->my_scorepad.setScore( (input)-1, 
        (this->my_dice).sumDieValues() );
    }
    /* yahtzee */
    else if( input == 13 )
    {
      if( (this->my_dice).checkYahtzee() == 1 )
      {
        this->my_scorepad.setScore( (input)-1, 50 );
      }
    }
    else
    {
      /* not a valid score */
    }
  }
  /* update played */
  this->my_played[ input-1 ] = 1;
  this->my_numplays++;
	(this->my_scorepad).setPlayed( input -1 );
}

/* save game */
int Yahtzee::saveGame( )
{
	/* create output file stream */
	ofstream my_file;
	/* try opening/creating the file */
	my_file.open("yahtzee_save.txt");
	/* check if file opened correctly */
	if( my_file.fail() )
	{
		return 1;
	}
	/* start writing the data into the file */
	/* need to save:
	 * 	- score pad values
   * 	- which playes have been made
	 *	- the number of plays made
	 */

	/* iterate through the score pad, saving the scores to the file 
	 * also grab if the play has been made 
	 * delimiter is ";"
	 */
	
	for( int i = 0; i < NUMPLAYS; i++ )
	{
		my_file << (this->my_scorepad).getScore( i );
		my_file << ";";
		my_file << this->my_played[ i ];
		my_file << "\n";
	}
	/* last thing to save is the total number of plays made */
	my_file << this->my_numplays;
	
	/* finished saving data to file */
	my_file.close();
	return 0;
}
