//#include "Keypad.h"
#include "MultitapKeypad.h"

const byte Rows= 4;
const byte Cols= 4;

byte keymap[Rows][Cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

//  a char array is defined as it can be seen on the above


//keypad connections to the arduino terminals is given as:

byte rPins[Rows]= {22,24,26,28}; //Rows 0 to 3
byte cPins[Cols]= {30,32,34,36}; //Columns 0 to 2

MultitapKeypad kpd(22 , 24 , 26 , 28 ,
                    30 , 32 , 34 , 36 );
                 

// command for library forkeypad
//initializes an instance of the Keypad class
//Keypad kpd= Keypad(makeKeymap(keymap), rPins, cPins, Rows, Cols);

void setup()
{
     Serial.begin(9600);  // initializing serail monitor
}

//If key is pressed, this key is stored in 'keypressed' variable
//If key is not equal to 'NO_KEY', then this key is printed out
void loop()
{
     Key key = kpd.getKey();
     if (key.code != NO_KEY)
     { 
          Serial.print(key.character);
          Serial.print(" ");
          Serial.println(key.tapCounter);
     }
}
