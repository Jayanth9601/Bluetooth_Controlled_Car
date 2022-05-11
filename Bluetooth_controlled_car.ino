/**
 Aurthor : Jayanth.s
 Date : 4/7/2020
 **/
#include <AFMotor.h>

char letter;           //variable to store the input given by the user from bluetooth

int del = 500;      //time period for forward, left, right and backward  motion on single click

//initializeing the 4 wheels of car
AF_DCMotor wheel1(1, MOTOR12_1KHZ);       
AF_DCMotor wheel2(2, MOTOR12_1KHZ);          
AF_DCMotor wheel3(3, MOTOR12_1KHZ);    
AF_DCMotor wheel4(4, MOTOR12_1KHZ); 

void setup() {
  Serial.begin(9600);
  Serial.println("The direction of car: ");

  //Asking the motor to stop by taking its time
  wheel1.run(RELEASE);
  wheel2.run(RELEASE);
  wheel3.run(RELEASE);
  wheel4.run(RELEASE);
}

void loop() {
   
  //enter the if statement if ther is a input from bluetooth
  if(Serial.available() > 0){
    letter = Serial.read();        //reading the input from user's bluetooth
    Stop();
      switch (letter){
        case '1': 
                  forward();     //calling forward function
                  break;
        case '2':
                  backward();    //calling backward function
                  break;
        case '3':
                  Right();       //calling right function
                  break;
        case '4':
                  left();        //calling left function
                  break;            
      }
  }
}

//forward function: to make the car move forward
void forward(){
  wheel1.setSpeed(225);  //THE maxium velocity
  wheel1.run(FORWARD);   //setting the direction of motion
  wheel2.setSpeed(225);  //THE maxium velocity
  wheel2.run(FORWARD);   //setting the direction of motion
  wheel3.setSpeed(225);  //THE maxium velocity
  wheel3.run(FORWARD);   //setting the direction of motion
  wheel4.setSpeed(220);  //THE maxium velocity
  wheel4.run(FORWARD);   //setting the direction of motion
}

//backward function: to make the car move backward
void backward(){
  wheel1.setSpeed(225);  //THE maxium velocity
  wheel1.run(BACKWARD);   //setting the direction of motion
  wheel2.setSpeed(225);  //THE maxium velocity
  wheel2.run(BACKWARD);   //setting the direction of motion
  wheel3.setSpeed(225);  //THE maxium velocity
  wheel3.run(BACKWARD);   //setting the direction of motion
  wheel4.setSpeed(225);  //THE maxium velocity
  wheel4.run(BACKWARD);   //setting the direction of motion
}

//Right function: to make the car move right
void Right(){
  wheel1.setSpeed(225);  //THE maxium velocity
  wheel1.run(BACKWARD);   //setting the direction of motion
  wheel2.setSpeed(225);  //THE maxium velocity
  wheel2.run(FORWARD);   //setting the direction of motion
  wheel3.setSpeed(225);  //THE maxium velocity
  wheel3.run(FORWARD);   //setting the direction of motion
  wheel4.setSpeed(225);  //THE maxium velocity
  wheel4.run(BACKWARD);   //setting the direction of motion
}

//left function: to make the move left
void left(){
  wheel1.setSpeed(225);  //THE maxium velocity
  wheel1.run(FORWARD);   //setting the direction of motion
  wheel2.setSpeed(225);  //THE maxium velocity
  wheel2.run(BACKWARD);   //setting the direction of motion
  wheel3.setSpeed(225);  //THE maxium velocity
  wheel3.run(BACKWARD);   //setting the direction of motion
  wheel4.setSpeed(225);  //THE maxium velocity
  wheel4.run(FORWARD);   //setting the direction of motion
}


void Stop(){
  wheel1.run(RELEASE);
  wheel2.run(RELEASE);
  wheel3.run(RELEASE);
  wheel4.run(RELEASE);
  delay(del);
}

//void Stop()
//{
//  wheel1.setSpeed(0); //Define minimum velocity
  //wheel1.run(RELEASE); //stop the motor when release the button
//  wheel2.setSpeed(0); //Define minimum velocity
//  wheel2.run(RELEASE); //rotate the motor clockwise
//  wheel3.setSpeed(0); //Define minimum velocity
//  wheel3.run(RELEASE); //stop the motor when release the button
//  wheel4.setSpeed(0); //Define minimum velocity
//  wheel4.run(RELEASE); //stop the motor when release the button
 // delay(del);
//}
