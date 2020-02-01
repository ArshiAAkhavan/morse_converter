
const short shortGap=500;// between each dit &dah
const short letterGap=1000;// between to letter
const short dahGap=500;
const short ditGap=100;
short dGaps[2]={ditGap,dahGap};
byte morseCodes[37]={237,163,172,217,240,171,220,162,234,201,226,165,238,235,229,174,193,219,216,241,225,189,228,190,199,166,121,120,117,108,81,0,1,4,13,40};
short morseDecodes[37]={19,189,192,63,6,165,66,162,18,175,64,171,22,21,67,174,199,57,54,7,55,163,58,190,193,198,607,526,499,490,487,486,567,594,603,606,201};

void morseDecode(int input){
  Serial.print("output: ");
  Serial.println(input);
  for(int i=0;i<36;i++){
    if(morseDecodes[i]==input){
      Serial.println((i<26)?(i+'a'):(i-26+'0')); 
      showLCD((i<26)?(i+'a'):(i-26+'0'));
      return;
    }
    
  }   
  
  if(input==morseDecodes[36])clearLCD();
  else showLCD(' ');
}

void morseCode(byte input){
  genMorse(morseCodes[input]);
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


void bip(byte bipbip){
  digitalWrite(LED,HIGH);
  delay(dGaps[bipbip]);
  digitalWrite(LED,LOW);
  delay(shortGap);
  
}
