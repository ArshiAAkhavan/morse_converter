#include "MultitapKeypad.h"

// arduino config
byte LED=13;


//default values of the keypad
const byte Rows= 4;
const byte Cols= 4;
const byte taps= 4;// number of the key variations

// yadet bashe bayad ino taghyir bedam
byte keymap[Rows][Cols][taps] = {{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
},
{
  {'a', 'd', 'g', 'A'},
  {'j', 'm', 'p', 'B'},
  {'s', 'v', 'y', 'C'},
  {'*', '0', '#', 'D'}
},
{
  {'b', 'e', 'h', 'A'},
  {'k', 'n', 'q', 'B'},
  {'t', 'w', 'z', 'C'},
  {'*', '0', '#', 'D'}
},
{
  {'c', 'f', 'i', 'A'},
  {'l', 'n', 'r', 'B'},
  {'u', 'x', '9', 'C'},
  {'*', '0', '#', 'D'}
},

};



const short shortGap=1250;
const short wordGap=2000;
const short dahGap=400;
const short ditGap=100;
short dGaps[2]={ditGap,dahGap};
byte morseCode[37]={235,189,192,225,240,165,228,162,234,175,226,171,238,237,229,174,199,219,216,241,217,163,220,190,193,198,121,40,13,4,1,0,81,108,117,120};


void bip(byte bipbip){
  digitalWrite(LED,HIGH);
  delay(dGaps[bipbip]);
  digitalWrite(LED,LOW);
  delay(shortGap);
  
}

void genMorse(byte code){
  Serial.print("daram ino mikonam: ");
  Serial.println(code);
  for(int i=0;i<5;i++){
    Serial.println("so it begins");
    Serial.println(code%3);
    if(code%3==2)return;
    bip(code%3);
    code/=3;
  }
}


MultitapKeypad kpd(22 , 24 , 26 , 28 ,
                   30 , 32 , 34 , 36 );


void setup()
{
     Serial.begin(9600);  // initializing serail monitor
//     prevKey = kpd.getKey();
     pinMode(LED,OUTPUT);
     
}
void loop()
{
     Key key = kpd.getKey();
//     handleKey(key);
      if(key.character!= NO_KEY)
      genMorse(morseCode[27]);
  delay(shortGap);
  
}

void genMorse(byte code){
  Serial.print("daram ino mikonam: ");
  Serial.println(code);
  for(int i=0;i<5;i++){
    Serial.println("so it begins");
    Serial.println(code%3);
    if(code%3==2)return;
    bip(code%3);
    code/=3;
  }
}


MultitapKeypad kpd(22 , 24 , 26 , 28 ,
                   30 , 32 , 34 , 36 );


void setup()
{
     Serial.begin(9600);  // initializing serail monitor
//     prevKey = kpd.getKey();
     pinMode(LED,OUTPUT);
     
}
void loop()
{
     Key key = kpd.getKey();
//     handleKey(key);
      if(key.character!= NO_KEY)
      genMorse(morseCode[27t]);
}

void genMorse(byte code){
  Serial.print("daram ino mikonam: ");
  Serial.println(code);
  for(int i=0;i<5;i++){
    Serial.println("so it begins");
    Serial.println(code%3);
    if(code%3==2)return;
    bip(code%3);
    code/=3;
  }
}


MultitapKeypad kpd(22 , 24 , 26 , 28 ,
                   30 , 32 , 34 , 36 );


void setup()
{
     Serial.begin(9600);  // initializing serail monitor
//     prevKey = kpd.getKey();
     pinMode(LED,OUTPUT);
     
}
void loop()
{
     Key key = kpd.getKey();
//     handleKey(key);
      if(key.character!= NO_KEY)
      genMorse(morseCode[27t]);
}
