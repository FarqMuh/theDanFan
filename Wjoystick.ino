#include <Servo.h>

int yPin = A0;
int xPin = A1; //Pin for reading horizontal
int fanPin = 9;

int swPin = 6;

int y;
int x;
int state;

int posY;
int posX;

int limiter = 0;
int toggle = 0;

Servo servoY;
Servo servoX;

void setup() {
  // put your setup code here, to run once:

  servoX.attach(10);
  servoY.attach(7);
  Serial.begin(9600);

  pinMode(swPin, INPUT_PULLUP);
  pinMode(fanPin, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

y = analogRead(yPin);
x = analogRead(xPin);
state = digitalRead(swPin);

servoY.write(posY);
servoX.write(posX);


if(y > 600){

    posY++;

  if(posY > 180){

    posY = 180;

  }
  delay(10);

} else if(y < 450){

  posY --;

  if(posY < 0){

    posY = 0;

  }

  delay(10);

}

if(x > 600){

  posX++;

  if(posX > 180){

    posX = 180;

  }
  delay(10);

} else if(x < 450){

  posX--;

  if(posX < 0){

    posX = 0;

  }
  delay(10);
}
if(state == LOW && limiter == 0){

  limiter = 1;
  toggle++;
  Serial.println("on");

} else if(state == HIGH && limiter == 1){

  limiter = 0;
  toggle++;
  Serial.println("off");

}

if(toggle > 4){

  toggle = 1;

}

if(toggle == 1 || toggle == 2){

  digitalWrite(fanPin,HIGH);

} else {

  digitalWrite(fanPin,LOW);

}


}
