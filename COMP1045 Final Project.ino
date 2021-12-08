/* 
 * COMP 1045 Final Project
 * By Andrew Souvanlasy
 * Created on December 2, 2021
 * This Arduino project is a very simple calculator that uses
 * the IR sensor remote for button input and an LCD screen for display.
 * There are some limitations:
 * - Only two single digit integers can be inputted (0-9).
 * - If division results in decimal values,
     it will round down to nearest whole number
     (this occurred even with doubles).
*/

#include <LiquidCrystal.h> // Initialize LCD
#include <IRremote.h> // Initialize IR

int RECV_PIN = 9; // IR sensor is connected to pin 9
LiquidCrystal lcd(12,11,5,4,3,2); // Every pin connected to the LCD
IRrecv ir(RECV_PIN); // Variable name for the IR receiver
decode_results irValue; // Variable for incoming IR data
int value = 0; // This holds 'results' as an int
int flag = 0; // Flag to separate inputted stages of the calculator
int x = 0; // This holds the first input number
int y = 0; // This holds the second input number
int result = 0; // This holds either the sum, difference, product, or quotient



// Addition method
int addition(int x, int y) {
  result = x + y;
  return result;
}
// Subtraction method
int subtraction(int x, int y) {
  result = x - y;
  return result;
}
// Multiplication method
int multiplication(int x, int y) {
  result = x * y;
  return result;
}
// Division method
int division(int x, int y) {
  result = x / y;
  return result;
}



void setup() {
  Serial.begin(9600); // Setup serial monitor
  lcd.begin(16,2); // LCD has 16 columns and 2 rows
  ir.enableIRIn(); // Setup IR receiver
  lcd.print("AS Instruments");
  lcd.setCursor(0,1);
  lcd.print("FX-1045");
}



void loop() {
	
  if(ir.decode(&irValue)) { // If IR sensor is activated
    value = irValue.value; // Decode IR value into an int
    ir.resume(); // Prepare to receive next value
    
    // Play is int x input button
    if(value == -24481) {
      flag = 1; // Allow int y input next
    }
    
    // Vol+ is addition button
    if (value == -32641) {
      result = addition(x, y); // Call method
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Sum:");
      lcd.setCursor(0,1);
      lcd.print(result);
    }
    
    // Vol- is subtraction button
    if (value == -28561) {
      result = subtraction(x, y); // Call method
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Difference:");
      lcd.setCursor(0,1);
      lcd.print(result);
    }
    
    // Seek forward is multiplication button
    if (value == 24735) {
      result = multiplication(x, y); // Call method
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Product:");
      lcd.setCursor(0,1);
      lcd.print(result);
    }
    
    // Seek backwards is division button
    if (value == 8415) {
      result = division(x, y); // Call method
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Quotient:");
      lcd.setCursor(0,1);
      lcd.print(result);
    }

    // FUNC/STOP is reset button
    if(value == 16575) {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Cleared");
      x = 0;
      y = 0;
      flag = 0;
    }
            
    // Selecting int x
    if(flag == 0) {
      if(value == 12495) {
        x = 0;
        lcd.clear();
      	lcd.print(x);
      }
      if(value == 2295) {
        x = 1;
        lcd.clear();
      	lcd.print(x);
      }
      if(value == -30601) {
        x = 2;
        lcd.clear();
        lcd.print(x);
      }
      if(value == 18615) {
        x = 3;
        lcd.clear();
        lcd.print(x);
      }
      if(value == 10455) {
        x = 4;
        lcd.clear();
        lcd.print(x);
      }
      if(value == -22441) {
        x = 5;
        lcd.clear();
        lcd.print(x);
      }
      if(value == 26775) {
        x = 6;
        lcd.clear();
        lcd.print(x);
      }
      if(value == 6375) {
        x = 7;
        lcd.clear();
        lcd.print(x);
      }
      if(value == -26521) {
        x = 8;
        lcd.clear();
        lcd.print(x);
      }
      if(value == 22695) {
        x = 9;
        lcd.clear();
        lcd.print(x);
      }
    }
    
    // Selecting int y
    if(flag == 1) {
      if(value == 12495) {
        y = 0;
        lcd.clear();
      	lcd.print(y);
      }
      if(value == 2295) {
        y = 1;
        lcd.clear();
      	lcd.print(y);
      }
      if(value == -30601) {
        y = 2;
        lcd.clear();
      	lcd.print(y);
      }
      if(value == 18615) {
        y = 3;
        lcd.clear();
      	lcd.print(y);
      }
      if(value == 10455) {
        y = 4;
        lcd.clear();
      	lcd.print(y);
      }
      if(value == -22441) {
        y = 5;
        lcd.clear();
      	lcd.print(y);
      }
      if(value == 26775) {
        y = 6;
        lcd.clear();
      	lcd.print(y);
      }
      if(value == 6375) {
        y = 7;
        lcd.clear();
      	lcd.print(y);
      }
      if(value == -26521) {
        y = 8;
        lcd.clear();
      	lcd.print(y);
      }
      if(value == 22695) {
        y = 9;
        lcd.clear();
      	lcd.print(y);
      }
    }
  }
}