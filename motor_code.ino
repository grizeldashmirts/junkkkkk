class GMot {
private:
  int pwm1;
  int pwm2;

public:
  GMot(int pin1, int pin2) {
    pwm1 = pin1;
    pwm2 = pin2;
  }

  void begin() {
    pinMode(pwm1, OUTPUT);
    pinMode(pwm2, OUTPUT);
    stop();
  }

  void setSpeed(int speed) {
    speed = constrain(speed, -255, 255);

    if (speed > 0) {
      analogWrite(pwm1, speed);
      analogWrite(pwm2, 0);
    } else if (speed < 0) {
      analogWrite(pwm1, 0);
      analogWrite(pwm2, abs(speed));
    } else {
      stop();
    }
  }

  void stop() {
    analogWrite(pwm1, 0);
    analogWrite(pwm2, 0);
  }
  void brake() {
    analogWrite(pwm1, 255);
    analogWrite(pwm2, 255);
  }
};

// -------- Pin definitions --------
// Motor A
const int PWM_1 = 2;
const int PWM_2 = 3;
// Create objects
GMot motor(PWM_1, PWM_2);

void setup() {
  motor.begin();
  Serial.begin(115200);
}

void loop() {
  motor.setSpeed(100);
  delay(1000);
}
