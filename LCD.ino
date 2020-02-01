
LiquidCrystal lcd(48, 50, 46, 44, 42, 40);  

int cursorX=0;
int cursorY=0;
void showLCD(char input){
     lcd.print(input);
     cursorX++;
     if(cursorX==16){
      cursorX=0;
      cursorY=(cursorY+1)%2;
      lcd.setCursor(cursorX,cursorY);
     }
}

void replaceLCD(char input){
     cursorX--;
     lcd.setCursor(cursorX,cursorY);
     showLCD(input);
}


void clearLCD(){
  lcd.clear();
  cursorX=0;
  cursorY=0;
}

void LCDsetup()
{
     lcd.begin(16, 2);
//     lcd.print("sara radan");
//     lcd.setCursor(5,0);
//     lcd.print("dabbe"); 
}
