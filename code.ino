/*
  Project Name    : Automatic Medication Dispenser
  Revision Date   : 02.01.2022
  Author          : Damla Buse Çifçi
  // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------
  Purpose         : To implement time data and control servo motor and buzzer accordinly. 
  // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------
  System Input    : Data processed by user
  System Output   : 
                    1)Servo Motor : To release pill
                    2)Buzzer: To alert with a beep sound
  // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------
  System Work     :  Usage information is processed by user. When medication taking time has come, servo motor works and release pill from tube. Buzzer notifies about this 
                     process. Because taking medicines at the right time is crucial for elderly people and people with aliments.              
 */
#include <Servo.h>  // In order to add servo library to project


Servo servo;  // Servo motor is initialized as servo
int pos = 0;    // used integer pos for angle values in degree. initialized it with 0(zero). 
int buzzer = 8; //To indicate that buzzer is attached to pin 8.
 
void setup() {
pinMode(buzzer,OUTPUT);
servo.attach(9);  // To indicate that servo motor is attached to pin 9.
}
 
void loop() {

 tone(buzzer,500,1000); // tone() is the main function to use with a buzzer, it takes 2 or 3 parameteres (buzzer pin, sound frequency, duration)
 delay(100);
  

 for (pos = 0; pos <= 90; pos += 1) { // The rotation angle of the motor is between 0 and 90 degrees
                                        // It is set to be increased by 1 degree with each step.
    servo.write(pos);              // The pos variable is printed, which is the servo angle value, to the servo.
    delay(100);                       // The time required to reach the targeted angle is 100 ms
   
    
  }
  for (pos = 90; pos >= 0; pos -= 1) { // Servo is made to go between 0 and 90 degrees.
    servo.write(pos); // The pos variable is printed, which is the servo angle value, to the servo.
    delay(15);                       // The time required to reach the targeted angle is 150 ms
 
}
 
}
