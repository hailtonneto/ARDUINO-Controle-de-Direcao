#define EN1 2
#define IN1 3
#define IN2 4

#define EN2 5
#define IN3 6
#define IN4 7

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  
  pinMode(EN1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  
  pinMode(EN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  digitalWrite(EN1, LOW);
  digitalWrite(EN2, LOW);
    
  /*
  	IN1 | IN2  | MOTOR1
    HIGH  LOW    HORARIO
    LOW   HIGH   ANTI-HORARIO
    LOW   LOW    IRRELEVANTE
    HIGH  HIGH   IRRELEVANTE
    
  	IN3 | IN4  | MOTOR2
    HIGH  LOW    ANTI-HORARIO
    LOW   HIGH   HORARIO
    LOW   LOW    IRRELEVANTE
    HIGH  HIGH   IRRELEVANTE
  */
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void loop() {
  int pot1 = analogRead(A0);
  int pot2 = analogRead(A1);
  
  int vel1 = map(pot1, 0, 1023, 0, 255);
  int vel2 = map(pot2, 0, 1023, 0, 255);
  
  analogWrite(EN1, vel1);
  analogWrite(EN2, vel2);
}