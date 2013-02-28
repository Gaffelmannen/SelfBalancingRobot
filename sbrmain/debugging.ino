

void print_current_accvalue()
{
  while(1)
  {
    acc_y_value = analogRead(acc_y_pin);
      
    Serial.print("Y acc=");
    Serial.println(acc_y_value);  
  }
}


void print_e()
{
  while(1)
  {
     int acc_value = analogRead(acc_y_pin);
     
     if(acc_value > Y_start_value)
     {
       // Forwards
       Serial.print("Forwards ");
       
       // Ta nu reda på hur mycket större den är
       if(acc_value < (Y_start_value + STEP_LENGTH))
       {
         // Mindre än steg lägnden i differens
         Serial.println("min");
       }
       else if( (acc_value > (Y_start_value + STEP_LENGTH)) && (acc_value < (Y_start_value + 2 * STEP_LENGTH)))
       {
         // Mellan steg längd och dubbla steglängden
         Serial.println("mid");
       }
       else// if( (acc_value > (Y_start_value + 2 * STEP_LENGTH)))
       {
         // Större än dubbla steglängden
         Serial.println("high");
       }
     }
     else if(acc_value < Y_start_value)
     {
       // Backwards
       Serial.print("Backwards");
       
       // Ta nu reda på hur mycket mindre den är
       if(acc_value > (Y_start_value - STEP_LENGTH))
       {
         Serial.println("min");
       }
       else if( (acc_value < (Y_start_value - STEP_LENGTH)) && (acc_value > (Y_start_value - 2 * STEP_LENGTH)))
       {
         Serial.println("mid");
       }
       else
       {
         Serial.println("high");
       }
     }
     else
     {
       // Motors off
       Serial.println("Motors Off!");
     }
  }
}

void print_d()
{
  while(1)
  {
     int acc_value = analogRead(acc_y_pin);
    
     if ((acc_value < (Y_start_value + STEP_LENGTH)) && ((acc_value > Y_start_value))) 
     {
       //set speed low forwards
       Serial.println("Set speed low forwards");
       
     }
     else if((acc_value < (Y_start_value + 2 * STEP_LENGTH)) && ((acc_value > (Y_start_value + STEP_LENGTH)))) 
     {
       //set speed mid forwards
       Serial.println("Set speed mid forwards");
       
     }
     else if((acc_value < (Y_start_value + 3 * STEP_LENGTH))) //&& ((acc_value > (Y_start_value + 2 * STEP_LENGTH)))) 
     {
       //set speed high forwards
       Serial.println("Set speed high forwards");
       
     }
     if((acc_value > (Y_start_value - STEP_LENGTH)) && ((acc_value < Y_start_value)))
     {
       //set speed low backwards
       Serial.println("Set speed low backwards");
       
     }
     else if((acc_value > (Y_start_value - 2 * STEP_LENGTH)) && ((acc_value < (Y_start_value - STEP_LENGTH)))) 
     {
       //set speed mid backwards
       Serial.println("Set speed mid backwards");
       
     }
     else if((acc_value > (Y_start_value - 3 * STEP_LENGTH))) //&& ((acc_value < (Y_start_value - 2 * STEP_LENGTH)))) 
     {
       //set speed high backwards
       Serial.println("Set speed high backwards");
       
     }
     else
     {
       //Motors off
       Serial.println("Motors off");
     }
  }
}

void step_response_analysis(void)
{
  // send data only when you receive data:
  
  // read the incoming byte:
  int incommingByte = 0;
  int acc_value = analogRead(acc_y_pin);

  while(incommingByte != 'G')
  {
    acc_value = analogRead(acc_y_pin);
    incommingByte = Serial.read();
    motor_control(acc_value);
  }
  
  //Give a step
  digitalWrite(motor_A_backwards, HIGH);
  digitalWrite(motor_A_forwards, LOW);
  digitalWrite(motor_B_backwards, HIGH);
  digitalWrite(motor_B_forwards, LOW);
  analogWrite(motor_A_speed, STEP_HIGHT);
  analogWrite(motor_B_speed, STEP_HIGHT);
  
  //Starta timer
  
  
  delay(STEP_RESPONSE_TIME);
  analogWrite(motor_A_speed, 0);
  analogWrite(motor_B_speed, 0);
  
  
  int cnt = 0;
  
  while(cnt < SAMPLES)
  {
    acc_value = analogRead(acc_y_pin);
    Serial.println(acc_value);
    motor_control(acc_value);
    cnt++;
  }
  
  //Stoppa timer
  
  
  analogWrite(motor_A_speed, 0);
  analogWrite(motor_B_speed, 0);
  Serial.println("Step response done!");
  
}

