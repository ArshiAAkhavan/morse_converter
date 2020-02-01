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
       Serial.print("mode select: ");
       Serial.println(digitalRead(MODE_SELECT));
       if(digitalRead(MODE_SELECT)){
        decodeLoop();
       }
       else encodeLoop();

}
