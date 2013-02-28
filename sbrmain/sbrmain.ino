
#include <PID_v1.h>

// Robot Control System
// K-F Johansson, H. Sandström
// 2013-02-26

//Constants
const int STEP_LENGTH = 32;
const int SPEED_LOW = 90;
const int SPEED_MID = 120;
const int SPEED_HIGH = 255;
const int STEP_RESPONSE_TIME = 200;
const int SAMPLES = 800;
const int STEP_HIGHT = 160;

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

// PID
const double Kp = 3;
const double Ki = 0.8;
const double Kd = 0.4;

double input_fwd;
double output_fwd;
double setpoint_fwd;
double input_back;
double output_back;
double setpoint_back;

PID forwards_PID (&input_fwd, &output_fwd, &setpoint_fwd, Kp, Ki, Kd, DIRECT);
PID backwards_PID (&input_back, &output_back, &setpoint_back, Kp, Ki, Kd, REVERSE);

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
  
  // and set it to the PID
  setpoint_fwd = Y_start_value;
  setpoint_back = Y_start_value;
  
  //Serial setup
  Serial.begin(9600);  //Used for debuggning
  
  // PID
  forwards_PID.SetMode(AUTOMATIC);
  backwards_PID.SetMode(AUTOMATIC);
}

void loop()
{
  //Read the accelerometer value
  acc_y_value = analogRead(acc_y_pin);
  
  // this is just for debugging
  step_response_analysis();
  //print_e();
  
  input_fwd = acc_y_value;
  input_back = acc_y_value;
  
  
  //Main program
  //motor_control_withPID(acc_y_value);
  //motor_control(acc_y_value);
}
