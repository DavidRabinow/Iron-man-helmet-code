
#include <Servo.h>
int button = 5; //button pin, connect to ground to move servo
int press = 0;
Servo servo;
Servo servo1;
boolean toggle = true;

void setup()
{
  pinMode(button, INPUT); //arduino monitor pin state
  servo.attach(6); //pin for servo control signal
  servo1.attach(9); //pin for servo control signal
  digitalWrite(5, HIGH); //enable pullups to make pin high
}

void loop()
{
  press = digitalRead(button);
  if (press == LOW)
  {
    if(toggle)
    {
      
      servo.write(150);
      servo1.write(10);
      toggle = !toggle;
    }
    else
    {
      servo.write(10);
      servo1.write(150);
      toggle = !toggle;
    }
  }
  delay(500);  //delay for debounce
}