/* Header file for Die class */

#ifndef DIE_H
#define DIE_H

/* define class Die */
class Die 
{
  private:
    int value;        // private die value
   
  public:
    Die( );           // empty constructor
    Die( int value ); // constructor
    //void setRandSeed( int seed );
    void rollDie( );    
    void rollDie( int mod );   
    void setValue( int value );
    int getValue() { return value; };
};
#endif
