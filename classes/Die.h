/* Header file for die class */

#ifndef DIE_H
#define DIE_H

/* define class die */
class Die {
  private:
    int value;  // private die value
   
  public:
    Die( );     // constructor
    Die( int ); 
    void setRandSeed( int seed );    
    void dieRoll( int mod );   
    void setValue( int value );
    int getValue() { return value; };
};
#endif
