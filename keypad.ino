
//keypad setup and functions
#define KEY_HASHTAG 35

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


void handleKey(Key key){
  

  if(key.tapCounter==0){
          byte inputChar=getKeyPressed(prevKey);
          if(inputChar>='a' && inputChar<='z')inputChar-='a';
          else if(inputChar>='0' && inputChar<='9')inputChar+=26-'0';
          inputBuffer[bufferSize++]=inputChar;    
          Serial.print(getKeyPressed(prevKey));
          Serial.print(" ");
          Serial.println(prevKey.tapCounter);
  }
  if(key.character==KEY_HASHTAG){
          Serial.println("\nmorse:");
          for(int i=1;i<bufferSize;i++,Serial.print(" "))Serial.print(inputBuffer[i]);Serial.println();
          for(int i=1;i<bufferSize;i++)morseCode(inputBuffer[i]);
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
