//CodeSpace Template
//***DO NOT EDIT includes and declarations***
//include libraries
#include <Servo.h>
#include <IRremote.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 

//IR initiate
const int RECV_PIN = 7; IRrecv irrecv(RECV_PIN); decode_results results; 
//Declare servos
Servo rightWheel; Servo leftWheel;
//declare PING input/output
const int trigPin = 5; const int echoPin = 6;
//End of template includes


void setup() 
{
  //Assign servo digital pins
  rightWheel.attach(2);
  leftWheel.attach(3);
  lcd.begin(16,2);  lcd.setCursor(1,0);
  irrecv.enableIRIn();
  //end of template setup

      //LIGHT VERIFICATION SETUP:
      pinMode(11, OUTPUT);//Left Light
  
      pinMode(12, OUTPUT);//Right Light

      pinMode(13, OUTPUT);//Used to indicate that drive is over

 
}
void loop() 
{
 // put your main code below here, to run repeatedly:
    if (irrecv.decode(&results)) //Searches for remote signal. Any button pressed is then recorded and relayed into loop.
      {
        
  if (results.value == 0xFF18E7)// Hexadecimal for Up Button. Code checks for presence of "Up" button.
   {
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("Driving Forward"); // Verification of movement 
    leftWheel.writeMicroseconds(2000);
    rightWheel.writeMicroseconds(1000);
    delay(715); //Decreased speed from 1000 
    rightWheel.writeMicroseconds(1500);
    leftWheel.writeMicroseconds(1500);
   }
   
   irrecv.resume();
   
   if (results.value == 0xFF629D)// Press "2". Backup to move forward
   {
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("Driving Forward"); // Verification of movement
    leftWheel.writeMicroseconds(1000);
    rightWheel.writeMicroseconds(2000);
    delay(1000);
    rightWheel.writeMicroseconds(1500);
    leftWheel.writeMicroseconds(1500);
   }
      
   irrecv.resume();
    //Stopping Indicator
    if(results.value == 0xFF9867) //Press "0". Only used because we forgot to press the OK button during testing
   {
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("Stopped"); // Verification of halting movement
    leftWheel.writeMicroseconds(1500);
    rightWheel.writeMicroseconds(1500);
    //<---Lights--->
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);//Intended to switch on all lights simultaneously
    delay(1000);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);// Intended to switch off all lights simultaneously 
   }
  
   irrecv.resume();
   
   //Left Turn
  
  if(results.value == 0xFF22DD) //Press "4" Button  
   {
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("Moving Left"); //Used to move robot leftward
    leftWheel.writeMicroseconds(1000);
    rightWheel.writeMicroseconds(1000);
    digitalWrite(11, HIGH); // Turn on the LED light to indicate left turn
    delay(425);
    rightWheel.writeMicroseconds(1500);
    leftWheel.writeMicroseconds(1500);
    digitalWrite(11, LOW); // Switches off LED Light
        
   }
    
   irrecv.resume();
   
   /*Minor Left Turn
    * Button used for precautional methods as experiment revealed that tighter turns are existant within maze.
    * Press Number 1
    */
   if(results.value == 0xFFA25D)//Turns slightly left 
   {
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("Moving Slightly Left") //Moves Slightly Left
    leftWheel.writeMicroseconds(1000);
    rightWheel.writeMicroseconds(1000);
    digitalWrite(11, HIGH); // Turns on LED Light
    delay(225);
    rightWheel.writeMicroseconds(1500);
    leftWheel.writeMicroseconds(1500);
    digitalWrite(11, LOW);// Switches off LED Light
   }

   irrecv.resume();
   
   //Right Turn
   if(results.value == 0xFFC23D) //Press "6" Button  
   {
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("Moving Right"); //Used to move robot leftward
    leftWheel.writeMicroseconds(2000);
    rightWheel.writeMicroseconds(2000);
    digitalWrite(12, HIGH); // Turn on the LED light to indicate right turn
    delay(425);
    rightWheel.writeMicroseconds(1500);
    leftWheel.writeMicroseconds(1500);
    digitalWrite(12, LOW); // Switches off LED Light   
   }

   irrecv.resume();

   /* Minor Right Turn 
    * Press "3" Button
   */
   if (results.value == 0xFFE21D) 
   {
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("Moving Slightly Right"); //Used to move slightly right
    leftWheel.writeMicroseconds(2000);
    rightWheel.writeMicroseconds(2000);
    digitalWrite(12, HIGH); // Turn on the LED Light to indicate right turn or slightly so
    delay(225);
    rightWheel.writeMicroseconds(1500);
    leftWheel.writeMicroseconds(1500);
    digitalWrite(12, LOW); // Switches off LED Light
   }

   irrecv.resume();
      }
   delay(10);//Delay Timer for entire code process. After 10 milliseconds, robot will become responsive
}
