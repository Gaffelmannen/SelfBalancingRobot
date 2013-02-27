// Robot Control System
// K-F Johansson, H. Sandström
// 2013-02-26

void motor_control_withPID(int acc_value)
{
  if(acc_value > Y_start_value)
  {
    // Set motor directions for motor A
    digitalWrite(motor_A_backwards, HIGH);
    digitalWrite(motor_A_forwards, LOW);
    
    // Set motor directions for motor B 
    digitalWrite(motor_B_backwards, HIGH);
    digitalWrite(motor_B_forwards, LOW); 
     
    // Calculate PID speed
    backwards_PID.Compute();
    Serial.print("PID Back Output ");
    Serial.println(output_back);
    
    // Motor speed set to calculated pid value
    analogWrite(motor_A_speed, output_back);
    analogWrite(motor_B_speed, output_back);
  }
  else if(acc_value < Y_start_value)
  {
    // Set motor directions for motor A
    digitalWrite(motor_A_backwards, LOW);
    digitalWrite(motor_A_forwards, HIGH);
    
    // Set motor directions for motor B
    digitalWrite(motor_B_backwards, LOW);
    digitalWrite(motor_B_forwards, HIGH);
    
    // Calculate PID speed
    forwards_PID.Compute();
    Serial.print("PID Fwd Output ");
    Serial.println(output_fwd);

    // Motor speed set to calculated pid value
    analogWrite(motor_A_speed, output_fwd);
    analogWrite(motor_B_speed, output_fwd);
  }
  else
  {
    // Motors off
    digitalWrite(motor_A_backwards, HIGH);
    digitalWrite(motor_A_forwards, HIGH);
     
    digitalWrite(motor_B_backwards, HIGH);
    digitalWrite(motor_B_forwards, HIGH);
     
    // Motor speed set to calculated pid value
    analogWrite(motor_A_speed, 0);
    analogWrite(motor_B_speed, 0);
  }
}

void motor_control(int acc_value)
{
  if(acc_value > Y_start_value)
  {
       // Backwards
       digitalWrite(motor_A_backwards, HIGH);
       digitalWrite(motor_A_forwards, LOW);
       
       digitalWrite(motor_B_backwards, HIGH);
       digitalWrite(motor_B_forwards, LOW);
       
       // Ta nu reda på hur mycket större den är
       if(acc_value < (Y_start_value + STEP_LENGTH))
       {
         // Mindre än steg lägnden i differens
         analogWrite(motor_A_speed, SPEED_LOW);
         analogWrite(motor_B_speed, SPEED_LOW);
       }
       else if( (acc_value > (Y_start_value + STEP_LENGTH)) && (acc_value < (Y_start_value + 2 * STEP_LENGTH)))
       {
         // Mellan steg längd och dubbla steglängden
         analogWrite(motor_A_speed, SPEED_MID);
         analogWrite(motor_B_speed, SPEED_MID);
       }
       else// if( (acc_value > (Y_start_value + 2 * STEP_LENGTH)))
       {
         // Större än dubbla steglängden
         analogWrite(motor_A_speed, SPEED_HIGH);
         analogWrite(motor_B_speed, SPEED_HIGH);
       }
     }
     else if(acc_value < Y_start_value)
     {
       // Farwards
       digitalWrite(motor_A_backwards, LOW);
       digitalWrite(motor_A_forwards, HIGH);
       
       digitalWrite(motor_B_backwards, LOW);
       digitalWrite(motor_B_forwards, HIGH);
       
       // Ta nu reda på hur mycket mindre den är
       if(acc_value > (Y_start_value - STEP_LENGTH))
       {
         analogWrite(motor_A_speed, SPEED_LOW);
         analogWrite(motor_B_speed, SPEED_LOW);
       }
       else if( (acc_value < (Y_start_value - STEP_LENGTH)) && (acc_value > (Y_start_value - 2 * STEP_LENGTH)))
       {
         analogWrite(motor_A_speed, SPEED_MID);
         analogWrite(motor_B_speed, SPEED_MID);
       }
       else
       {
         analogWrite(motor_A_speed, SPEED_HIGH);
         analogWrite(motor_B_speed, SPEED_HIGH);
       }
     }
     else
     {
       // Motors off
       digitalWrite(motor_A_backwards, HIGH);
       digitalWrite(motor_A_forwards, HIGH);
       
       digitalWrite(motor_B_backwards, HIGH);
       digitalWrite(motor_B_forwards, HIGH);
     }
}
