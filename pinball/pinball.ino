int score;
int Lflipper;
int Rflipper;
int Lbumper;
int Rbumper;
int Tbumper;
int hole;
int ballsAmount = 3;
bool addPoints = false;
bool removeBalls = false;

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  score += 1;
  Serial.println(score);
  pinMode(2, INPUT_PULLUP);   //linker knop 5
  pinMode(3, INPUT_PULLUP);   //rechter knop 5
  pinMode(4, INPUT);  //linker flipper 1
  pinMode(5, INPUT);  //rechter flipper 1
  pinMode(6, INPUT);  //linker bumper 2
  pinMode(7, INPUT);  //rechter bumper 2
  pinMode(8, INPUT);  //top bumper 4
  pinMode(9, INPUT);  //hole 4
}

void loop() {
  Serial.println(score);
  // put your main code here, to run repeatedly:
  
  int k1 = digitalRead(2);
  int k2 = digitalRead(3);

  if((k1 || k2) > 0){
    digitalRead(2);
    Serial.println("&");
    digitalRead(3);
    //score++;
  }
  else if((k1 || k2) <= 0)

  Lbumper = digitalRead(6);
  Rbumper = digitalRead(7);
  Tbumper = digitalRead(8);
  hole = digitalRead(9);
  //ballsLight = analogRead(11);

  if (Lbumper > 0 || Rbumper > 0) {
    addPoints = true;
    if (addPoints) {
      score += 100;
      addPoints = false;
    }
  }
  if (Tbumper > 0) {
    addPoints = true;
    if (addPoints) {
      score += 500;
      addPoints = false;
    }
  }
  if (hole > 0) {
    removeBalls = true;
    if (removeBalls) {
      ballsAmount--;
      removeBalls = false;
    }
  }
  switch (ballsAmount) {
    case 3:
      pinMode(11, OUTPUT);
      analogWrite(11, 255);
      break;
    case 2:
      pinMode(11, OUTPUT);
      analogWrite(11, 170);
      break;
    case 1:
      pinMode(11, OUTPUT);
      analogWrite(11, 85);
      break;
    case 0:
      pinMode(11, OUTPUT);
      analogWrite(11, 0);
      break;
  }
}
