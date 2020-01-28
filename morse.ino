
const short shortGap=500;// between each dit &dah
const short letterGap=1000;// between to letter
const short dahGap=500;
const short ditGap=100;
short dGaps[2]={ditGap,dahGap};
byte morseCodes[37]={237,163,172,217,240,171,220,162,234,201,226,165,238,235,229,174,193,219,216,241,225,189,228,190,199,166,121,120,117,108,81,0,1,4,13,40};


void bip(byte bipbip){
  digitalWrite(LED,HIGH);
  delay(dGaps[bipbip]);
  digitalWrite(LED,LOW);
  delay(shortGap);
  
}

void morseCode(byte input){
  genMorse(morseCodes[input]);
}
void morseDecode(int input){
  Serial.print("input: ");
  Serial.println(input);
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
