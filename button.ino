// button setup and functions
const byte BUTTON = 7;

const byte ditDelay=2;
const byte longDelay=5;
const byte timeInterval=100;


int prevButton=0;
int deltaTime[2]={0};
int allowCount[2]={0};
int outputChar=2;
bool output_is_generated=0;


void handleButton(){
     byte button=digitalRead(BUTTON);
     Serial.print(prevButton);
     Serial.print(" : ");
     Serial.println(button);
     
     if(prevButton!=button){
        output_is_generated=0;
        
        allowCount[button]=1;
        allowCount[prevButton]=0;
        if(button==0){
          outputChar*=3;
          if(deltaTime[1]>ditDelay)outputChar+=1; 
        }
        deltaTime[prevButton]=0;
        
     }
     for(int i=0;i<2;i++)deltaTime[i]+=allowCount[i];
     if(deltaTime[0]>longDelay && ! output_is_generated){
        output_is_generated=1;
        morseDecode(outputChar);
        outputChar=2;
     }
     prevButton=button;

}

void decodeLoop(){
       handleButton();
       delay(timeInterval);
}
