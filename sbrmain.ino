// Robot Control System
// K-F Johansson, H. Sandström
// 2013-02-26

//Constants

//Pin configuration H-bridge
int motor_A_speed = 10;
int motor_B_speed = 11;
int motor_A_backwards = 5;
int motor_A_forwards = 6;
int motor_B_backwards = 7;
int motor_B_forwards = 8;

// Pin configuration accelerometer
int acc_x_pin = 0;
int acc_y_pin = 1;
int acc_x_value = 0;
int acc_y_value = 0;

//Global vars.
int Y_start_value = 0;

void setup()
{
  //I/O setup
  pinMode(motor_A_speed, OUTPUT);
  pinMode(motor_B_speed, OUTPUT);
  pinMode(motor_A_backwards, OUTPUT);
  pinMode(motor_A_forwards, OUTPUT);
  pinMode(motor_B_backwards, OUTPUT);
  pinMode(motor_B_forwards, OUTPUT);
  
  //Analog setup
  analogReference(EXTERNAL);  //Set the analog referens voltage on the hardware. Chosen via jumper 3.3V or 5V
  
  //Get start value
  Y_start_value = analogRead(acc_y_pin);
  
  //Serial setup
  Serial.begin(9600);  //Used for debuggning
  
}

void loop()
{
  //Read the accelerometer value
  acc_y_value = analogRead(acc_y_pin);
  
  if(acc_y_value > Y_start_value)
  {
    //Drive motors backwards
    //Motor A
    digitalWrite(motor_A_speed, 100);    //Speed set to 100
    digitalWrite(motor_A_backwards, HIGH);
    digitalWrite(motor_A_forwards, LOW);
    
    //Motor B
    digitalWrite(motor_B_speed, 100);    //Speed set to 100
    digitalWrite(motor_B_backwards, HIGH);
    digitalWrite(motor_B_forwards, LOW);
  }
  else if(acc_y_value < Y_start_value)
  {
    //Drive motors farwards
    //Motor A
    digitalWrite(motor_A_speed, 100);    //Speed set to 100
    digitalWrite(motor_A_backwards, LOW);
    digitalWrite(motor_A_forwards, HIGH);
    
    //Motor B
    digitalWrite(motor_B_speed, 100);    //Speed set to 100
    digitalWrite(motor_B_backwards, LOW);
    digitalWrite(motor_B_forwards, HIGH);
  }
  else
  {
    //Stop motors
    //Motor A
    digitalWrite(motor_A_speed, LOW);    //Speed set to 100
    digitalWrite(motor_A_backwards, LOW);
    digitalWrite(motor_A_forwards, LOW);
    
    //Motor B
    digitalWrite(motor_B_speed, LOW);    //Speed set to 100
    digitalWrite(motor_B_backwards, LOW);
    digitalWrite(motor_B_forwards, LOW);
  }
}

