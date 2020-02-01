
//keypad setup and functions
#define KEY_HASHTAG 35
#define KEY_STAR 42
// arduino config
byte LED=5;

//default values of the keypad
const byte Rows= 4;
const byte Cols= 4;
const byte taps= 4;// number of the key variations

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

byte inputBuffer[1000];
int bufferSize=0;



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

void showKey(Key key){
    switch(key.character){
    case KEY_STAR:
      backspaceLCD();
      break;
    case KEY_HASHTAG:
      break;
    default:
     if (key.tapCounter!=0)replaceLCD(getKeyPressed(key));
     else  showLCD(getKeyPressed(key));    
  }
}

void handleKey(Key key){

  showKey(key);
  
  if(key.tapCounter==0){
    if(key.character!=KEY_STAR && prevKey.character!=KEY_STAR){
          byte inputChar=getKeyPressed(prevKey);
          inputBuffer[bufferSize++]=inputChar;
          Serial.print(getKeyPressed(prevKey));
          Serial.print(" ");
          Serial.println(prevKey.tapCounter);
    }else if(key.character==KEY_STAR){
      prevKey.character=inputBuffer[bufferSize-1];
      
    }
  }
  if(key.character==KEY_HASHTAG){
          Serial.println("\nmorse:");
          Serial.println("inputBuffers: ");
          for(int i=1;i<bufferSize;i++,Serial.print(" "))Serial.print(inputBuffer[i]+((inputBuffer[i]>=26)?'0'-26:'a'));Serial.println();
          for(int i=1;i<bufferSize;i++,Serial.print(" "))Serial.print(inputBuffer[i]);Serial.println();
          for(int i=1;i<bufferSize;i++){
            byte inputChar=inputBuffer[i];
            if(inputChar>='a' && inputChar<='z')inputChar-='a';
            else if(inputChar>='0' && inputChar<='9')inputChar+=26-'0';
            morseCode(inputChar);
          }
          bufferSize=0;  
  }
  prevKey=key;
}

void keypadSetup(){
     Serial.begin(9600);  // initializing serail monitor
     prevKey = kpd.getKey();
     pinMode(LED,OUTPUT);
     pinMode(BUTTON,INPUT);
}
void encodeLoop(){
     Key key = kpd.getKey();
     if (key.code != NO_KEY)
     { 
        handleKey(key);
     }
}
