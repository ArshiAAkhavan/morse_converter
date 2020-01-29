#include <LiquidCrystal.h> 
#include "MultitapKeypad.h"

#define MODE_SELECT 53 

void setup(){
     pinMode(MODE_SELECT, INPUT);
     keypadSetup();
     LCDsetup();
}

void loop()
{
       if(digitalRead(MODE_SELECT)) decodeLoop();
       else encodeLoop();

}
