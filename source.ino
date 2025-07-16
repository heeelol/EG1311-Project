#include <Servo.h>

Servo servo;

int TRIG_PIN = 12;
int ECHO_PIN = 11;
int MOTOR_PIN_FORWARD = 5;
int MOTOR_PIN_BACKWARD = 7;
int SERVO_PIN = 2;
float SPEED_OF_SOUND = 0.0345;
int throws = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR_PIN_FORWARD, OUTPUT);
  pinMode(MOTOR_PIN_BACKWARD, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);
  pinMode(ECHO_PIN, INPUT);
  servo.attach(SERVO_PIN, 500, 2500);
  Serial.begin(9600);
  servo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  int microsecs = pulseIn(ECHO_PIN, HIGH);
  float cms = microsecs * SPEED_OF_SOUND / 2;
  Serial.println(cms);
  if (cms <= 11 && throws <= 0) {
  digitalWrite(MOTOR_PIN_FORWARD, LOW);
  digitalWrite(MOTOR_PIN_BACKWARD, LOW);
  delay(50);
  if (throws == 0) {
    servo.write(85);
    delay(500);
    servo.write(30);
    delay(500);
    throws = 1;
  }
  delay(50);
  } else {
    if (throws > 0) {
      digitalWrite(MOTOR_PIN_FORWARD, LOW);
      digitalWrite(MOTOR_PIN_BACKWARD, HIGH);
    } else {
        digitalWrite(MOTOR_PIN_FORWARD, HIGH);
        digitalWrite(MOTOR_PIN_BACKWARD, LOW);
    }
  }
  delay(10);
}
