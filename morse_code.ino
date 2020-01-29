#include <LiquidCrystal.h> 
#include "MultitapKeypad.h"


void setup(){
     keypadSetup();
     LCDsetup();
}

void loop()
{
       decodeLoop();
//       encodeLoop();

}
