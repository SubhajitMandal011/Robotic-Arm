#define BLYNK_TEMPLATE_ID "PASTE_BLYNK_TEMPLATE_ID_HERE"
#define BLYNK_TEMPLATE_NAME "WRITE_YOUR_TEMPLATE_NAME_HERE"
#define BLYNK_AUTH_TOKEN "PASTE_YOUR_NEW_AUTH_TOKEN_HERE"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>

char ssid[] = "YOUR_HOTSPOT_NAME";
char pass[] = "YOUR_HOTSPOT_PASSWORD";

Servo baseServo;
Servo shoulderServo;
Servo elbowServo;
Servo wristServo;
Servo gripperServo;

const int BASE_PIN = 13;
const int SHOULDER_PIN = 14;
const int ELBOW_PIN = 25;
const int WRIST_PIN = 26;
const int GRIPPER_PIN = 27;

void setup() {
  Serial.begin(115200);

  baseServo.setPeriodHertz(50);
  shoulderServo.setPeriodHertz(50);
  elbowServo.setPeriodHertz(50);
  wristServo.setPeriodHertz(50);
  gripperServo.setPeriodHertz(50);

  baseServo.attach(BASE_PIN, 500, 2500);
  shoulderServo.attach(SHOULDER_PIN, 500, 2500);
  elbowServo.attach(ELBOW_PIN, 500, 2500);
  wristServo.attach(WRIST_PIN, 500, 2500);
  gripperServo.attach(GRIPPER_PIN, 500, 2500);

  // Safe initial test positions; verify the arm's
  // mechanical limits before operating it.
  baseServo.write(90);
  shoulderServo.write(90);
  elbowServo.write(90);
  wristServo.write(90);
  gripperServo.write(90);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

BLYNK_WRITE(V1) {
  baseServo.write(constrain(param.asInt(), 0, 180));
}

BLYNK_WRITE(V2) {
  shoulderServo.write(constrain(param.asInt(), 0, 180));
}

BLYNK_WRITE(V3) {
  elbowServo.write(constrain(param.asInt(), 0, 180));
}

BLYNK_WRITE(V4) {
  wristServo.write(constrain(param.asInt(), 0, 180));
}

BLYNK_WRITE(V5) {
  gripperServo.write(constrain(param.asInt(), 0, 180));
}

void loop() {
  Blynk.run();
}