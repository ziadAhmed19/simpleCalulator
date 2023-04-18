#include <LiquidCrystal.h> 
#include <Keypad.h> 

const byte ROWS = 4; // Four rows
const byte COLS = 4; // Three columns

// Define the Keymap
char keys[ROWS][COLS] = {

  {'7','8','9','D'},

  {'4','5','6','C'},

  {'1','2','3','B'},

  {'c','0','=','A'}

};

byte rowPins[ROWS] = { 0, 1, 2, 3 };// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = { 4, 5, 6, 7 }; // Connect keypad COL0, COL1 and COL2 to these Arduino pins.

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //  Create the Keypad

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
//               rs en  d4  d5  d6  d7
 long Num1,Num2,Number;
 char key,op;
 boolean result = false;
 
void setup() {
  lcd.begin(16, 2); //We are using a 16*2 LCD display
  lcd.print("Hello, World!"); //Display a intro message
  lcd.setCursor(0, 1);   // set the cursor to column 0, line 1
  lcd.print("Getting Ready.."); //Display a intro message 

   delay(1500); //Wait for display to show info
    lcd.clear(); //Then clean it
}

void loop() {
  
key = kpd.getKey(); //storing pressed key value in a char

if (key!=NO_KEY)
DetectButtons();

if (result==true)
CalculateResult();

DisplayResult();   
}

void DetectButtons()
{ 
    lcd.clear(); //Then clean it
    
    if (key=='c') //If cancel Button is pressed
    {Number=Num1=Num2=0; result=false;}
    
    
    if (key == '0')
    {//Button 0 is Pressed
    if (Number==0)
    Number=0;
    else
    Number = (Number*10) + 0; //Pressed twice
    }      


    if (key == '1') 
    {//If Button 1 is pressed 
    if (Number==0)
    Number=1;
    else
    Number = (Number*10) + 1; //Pressed twice
    }
    

    if (key == '2') 
    {//Button 2 is Pressed 
     if (Number==0)
    Number=2;
    else
    Number = (Number*10) + 2; //Pressed twice
    }
   
   
    if (key == '3')
    {//Button 3 is Pressed 
     if (Number==0)
    Number=3;
    else
    Number = (Number*10) + 3; //Pressed twice
    }   
    
    
     if (key == '4') 
    {//If Button 4 is pressed 
    if (Number==0)
    Number=4;
    else
    Number = (Number*10) + 4; //Pressed twice
    }

    if (key == '5')
    {//Button 5 is Pressed 
     if (Number==0)
    Number=5;
    else
    Number = (Number*10) + 5; //Pressed twice
    }


    if (key == '6')
    {//Button 6 is Pressed 
    if (Number==0)
    Number=6;
    else
    Number = (Number*10) + 6; //Pressed twice
    }
    
    
    if (key == '7')
    {//If Button 7 is pressed
    if (Number==0)
    Number=7;
    else
    Number = (Number*10) + 7; //Pressed twice
    } 
    

    if (key == '8')
    {//Button 8 is Pressed 
     if (Number==0)
    Number=8;
    else
    Number = (Number*10) + 8; //Pressed twice
    }   
  
  
    if (key == '9')
    {//Button 9 is Pressed
    if (Number==0)
    Number=9;
    else
    Number = (Number*10) + 9; //Pressed twice
    }  


    if (key == '=')
    {//'=' Button is Pressed 
    Num2=Number;
    result = true;
    }
    
    
    if (key == 'A' || key == 'B' || key == 'C' || key == 'D') //Detecting Buttons on Column 4
    {
    Num1 = Number;    
    Number =0;
    if (key == 'A')
    {op = '+';}
    
    if (key == 'B')
    {op = '-';}
    
    if (key == 'C')
    {op = '*';}
    
    if (key == 'D')
    {op = '/';}  

    delay(100);
    }
  
}

void CalculateResult()
{
  if (op=='+')
    Number = Num1+Num2;

  if (op=='-')
    Number = Num1-Num2;

  if (op=='*')
    Number = Num1*Num2;

  if (op=='/')
    Number = Num1/Num2; 
}

void DisplayResult()
{
  lcd.setCursor(0, 0);   // set the cursor to column 0, line 0
  lcd.print(Num1); lcd.print(op); lcd.print(Num2); 
  
  if (result==true)
  {lcd.print(" = "); lcd.print(Number);} //Display the result
  
  lcd.setCursor(0, 1);   // set the cursor to column 0, line 1
  lcd.print(Number); //Display the result
}



