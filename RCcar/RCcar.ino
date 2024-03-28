int motor1pin1 = 2;
int motor1pin2 = 3;
int motor2pin1 = 4;
int motor2pin2 = 5;
int enA = 9;
int enB = 10;

void setup() {
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);  
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char direction = Serial.read();
    Serial.print("Received: ");
    Serial.println(direction); 
    switch (direction) {
      case 'f':
        go_forward();
        break;
      case 'b':
        go_backward();
        break;
      case 'l':
        go_left();
        break;
      case 'r':
        go_right();
        break;
      default:
        stop_moving();
        break;
    } 
  }
}

void go_forward() {  // Motor 1 and 2 forward
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  analogWrite(enA, 255);
  analogWrite(enB, 255);
}

void go_backward() {  // Motor 1 and 2 backward
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  analogWrite(enA, 255);
  analogWrite(enB, 255);
}

void go_right() { // Motor 2 forward
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  analogWrite(enB, 255);
}

void go_left() { // Motor 1 forward
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
  analogWrite(enA, 255);
}

void stop_moving() { // Motor 1 forward
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}
