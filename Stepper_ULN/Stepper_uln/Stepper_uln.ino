/*
 * Source code for stepper engine. 
 * With Arduino library
 * Used component:
 *  + Arduino NANO
 *  + Step motor 28BYJ-48 5V DC (4 lines)
 *  + module board with ULN2003APG
 * Power (5V) from laptop output.
 */

#include <Stepper.h>

#define IN1  2
#define IN2  3
#define IN3  4
#define IN4  5

const int stepsPerRevol = 200;
int inByte = 0;
int iLoopLog = 0;
int motorSpeed = 0;
int motorStep = 1000;

Stepper motor(stepsPerRevol, IN1, IN2, IN3, IN4);
int stepCount = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("START");

}

void loop() {
  delay(100);
  iLoopLog = Serial.read();
  //Serial.print("Loop ");
  //Serial.println(iLoopLog, DEC);
  
  if (iLoopLog == '1')
  {
    Serial.println("1 (delay)");
    delay(1000);
  }
  else if ( iLoopLog == '2')
  {
    Serial.println("2 (motor forward)");
    motor.setSpeed(motorSpeed);
    motor.step(motorStep);
  }
  else if ( iLoopLog == '3')
  {
    Serial.println("3 (motor backward)");
    motor.setSpeed(motorSpeed);
    motor.step((-1)*motorStep);
  }
  else if ( iLoopLog == '4')
  {
    Serial.print("4 (speed -5 =");
    motorSpeed-=5;
    Serial.println(motorSpeed, DEC);
  }
  else if ( iLoopLog == '5')
  {
    Serial.print("4 (speed =");
    motorSpeed=50;
    Serial.println(motorSpeed, DEC);
  }
  else if ( iLoopLog == '6')
  {
    Serial.print("4 (speed +5 =");
    motorSpeed+=5;
    Serial.println(motorSpeed, DEC);
  }
  else if ( iLoopLog == '7')
  {
    Serial.print("8 (step -100 = ");
    motorStep-=10;
    Serial.println(motorStep, DEC);
  }
  else if ( iLoopLog == '8')
  {
    Serial.print("8 (step =");
    motorStep=2048;
    Serial.println(motorStep, DEC);
  }
  else if ( iLoopLog == '9')
  {
    Serial.print("8 (step +100 = ");
    motorStep+=10;
    Serial.println(motorStep, DEC);
  }
  else iLoopLog = -1;

  if (motorSpeed <= 0){
    Serial.println("-- speed too low --");
    motorSpeed =10;
  }
  else if (motorSpeed >= 200)
  {
    Serial.println("-- speed too high --");
    motorSpeed =90;
  }
    
  
  

}
