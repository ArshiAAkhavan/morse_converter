#include "MultitapKeypad.h"

#define KEY_HASHTAG 35

// arduino config
byte LED=5;


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



const short shortGap=500;// between each dit &dah
const short letterGap=1000;// between to letter
const short dahGap=500;
const short ditGap=100;
short dGaps[2]={ditGap,dahGap};
byte morseCode[37]={235,189,192,225,240,165,228,162,234,175,226,171,238,237,229,174,199,219,216,241,217,163,220,190,193,198,121,40,13,4,1,0,81,108,117,120};
byte inputBuffer[1000];
int pointer=0;

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
    if(code%3==2)break;
    Serial.print(code%3);
    bip(code%3);
    code/=3;
  }
  delay(letterGap);
  Serial.println();
}



MultitapKeypad kpd(22 , 24 , 26 , 28 ,
                   30 , 32 , 34 , 36 );
Key prevKey;

byte getKeyPressed(Key key){
     if(key.character>=48+1 && key.character<=48+9){
        byte temp=key.character-49;
        byte row=temp/3;
        byte col=temp%3;
        return keymap[key.tapCounter%4][row][col];  
     }
     return key.character;
}


void handleKey(Key key){
  

  if(key.tapCounter==0){
          byte inputChar=getKeyPressed(prevKey);
          if(inputChar>='a' && inputChar<='z')inputChar-='a';
          else if(inputChar>='0' && inputChar<='9')inputChar+=26-'0';
          inputBuffer[pointer++]=inputChar;    
          Serial.print(getKeyPressed(prevKey));
          Serial.print(" ");
          Serial.println(prevKey.tapCounter);
  }
  if(key.character==KEY_HASHTAG){
          Serial.println("\nmorse:");
          for(int i=1;i<pointer;i++,Serial.print(" "))Serial.print(inputBuffer[i]);Serial.println();
          for(int i=1;i<pointer;i++)genMorse(morseCode[inputBuffer[i]]);
          pointer=0;  
  }
  
  prevKey=key;
}


void setup()
{
     Serial.begin(9600);  // initializing serail monitor
     prevKey = kpd.getKey();
     pinMode(LED,OUTPUT);
     
}
void loop()
{
     Key key = kpd.getKey();
     if (key.code != NO_KEY)
     { 
        handleKey(key);
     }
}
