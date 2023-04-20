#include <NewPing.h>

unsigned int score;
int Lflipper;
int Rflipper;
int Lbumper;
int Rbumper;
int Tbumper;
int ballsAmount = 3;
bool getScore = false;
bool getBallAmount = false;
bool gameOver = false;
float duration, distance;
float durationBallS, distanceBallS;
NewPing sonar(9, 10, 5);
NewPing sonarBall(11, 12, 5);

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  //Serial.println(score);
  pinMode(2, INPUT_PULLUP);   //linker knop 5
  digitalWrite(2, LOW);
  pinMode(3, INPUT_PULLUP);
  digitalWrite(3, LOW);   //rechter knop 5
  pinMode(4, INPUT);  //linker flipper 1
  pinMode(5, INPUT);  //rechter flipper 1
  pinMode(6, OUTPUT);  //linker bumper 2
  pinMode(7, INPUT);  //rechter bumper 2
  pinMode(8, INPUT);  //top bumper 4
  pinMode(9, OUTPUT);  //score trigger
  pinMode(10, INPUT);  //score echo
  pinMode(11, OUTPUT); //ball counter trigger
  pinMode(12, INPUT); //ball counter echo
}
void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(2, LOW);
  int k1 = digitalRead(2);
  int k2 = digitalRead(3);
  Lbumper = digitalRead(6);
  Rbumper = digitalRead(7);
  Tbumper = digitalRead(8);

  //Serial.println("knop1 " + String(k1) + " knop2 " + String(k2));
  
  //get score
  duration = sonar.ping();                        
  distance = (duration/2)*0.0343;
  //Serial.println(score);
  if(distance < 3.00){
    getScore = true;
  }
  else if(distance > 3.00){
    getScore = false;
  }
  if(getScore){
    score += 10;
  }

//ball count
  durationBallS = sonarBall.ping();
  distanceBallS = (durationBallS/2)*0.0343;
  int previousBallAmount = ballsAmount;
  if(distanceBallS > 3.00){
    getBallAmount = true; 
  }
  if(getBallAmount){
    ballsAmount--;
    getBallAmount = false;
    delay(1000);
  }
  if(ballsAmount == 0){
    gameOver = true;
  }
  Serial.println(String(score)+" "+String(ballsAmount));

   if(k2 > 0){
    Serial.println(Lbumper);
    digitalWrite(6, HIGH);
  }
  else if(k2 <= 0)
    digitalWrite(6, LOW);
  if(k1 > 0){
    Serial.println(Lbumper);
    digitalWrite(7, HIGH);
  }
  else if(k1 <= 0)
    digitalWrite(7, LOW);
}


