  int in1 = 5;
  int in2 = 6;
  void motGo(int speed){
  // speed between -100 and 100
  // with map function
  // absolute value
  if(speed < -100 || speed > 100){
  speed = constrain(speed, -100, 100);
  }
    if(speed == 0){
      analogWrite(in1, 0);
      analogWrite(in2, 0);
    }
    else if(speed < 0){
      speed = map(speed, 0, 100, 0, 255);
      analogWrite(in1, speed);
      analogWrite(in2, 0);
    }
    else{
      speed = abs(speed);
      speed = map(speed, 0, 100, 0, 255);
      analogWrite(in1, 0);
      analogWrite(in2, speed);
    }
    Serial.println(speed);
  }

void setup() {
  // put your setup code here, to run once:
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 motGo(50);
 delay(1000);
 motGo(150);
 delay(1000);
 motGo(-50);
 delay(1000);
 motGo(-150);
 delay(1000);
}
