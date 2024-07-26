#define leftSensor 3
#define rightSensor 2
#define leftMotorForward 4
#define leftMotorBackward 5
#define rightMotorForward 6
#define rightMotorBackward 7
void setup() {
  Serial.begin(9600);
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
  pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorBackward, OUTPUT);
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorBackward, OUTPUT);
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, LOW);
}
// 1  walk
// 0 do not walk

void loop() {
  int leftSensorValue = digitalRead(leftSensor); 
  int rightSensorValue = digitalRead(rightSensor);
  // forward
  if(leftSensorValue==0&&rightSensorValue==0){
    digitalWrite(leftMotorForward, HIGH);
    digitalWrite(rightMotorForward, HIGH);
    digitalWrite(rightMotorBackward, LOW);
    digitalWrite(leftMotorBackward, LOW);
  }
  // left
  else if(leftSensorValue==1&&rightSensorValue==0){
    digitalWrite(leftMotorForward, LOW);
    digitalWrite(rightMotorForward, HIGH);
    digitalWrite(rightMotorBackward, LOW);
    digitalWrite(leftMotorBackward, HIGH);
  }
  //right
  else if(leftSensorValue==0&&rightSensorValue==1){
    digitalWrite(leftMotorForward, HIGH);
    digitalWrite(rightMotorForward, LOW);
    digitalWrite(rightMotorBackward, HIGH);
    digitalWrite(leftMotorBackward, LOW);
  }
  //stop
  else if(leftSensorValue==1&&rightSensorValue==1){
    digitalWrite(leftMotorForward, LOW);
    digitalWrite(rightMotorForward, LOW);
    digitalWrite(rightMotorBackward, LOW);
    digitalWrite(leftMotorBackward, LOW);
  }
}
