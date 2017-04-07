#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

int state=0;
int speed = 255;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
       motor1.setSpeed(speed);
       motor2.setSpeed(speed);
       motor3.setSpeed(speed);
       motor4.setSpeed(speed);

  
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
   
}

// the loop function runs over and over again forever
void loop() {
//
  if(Serial.available())
    {
       
      state = Serial.read() -'0';
      if(state != -1 && state > 0){
        light(state);
      }
     
    
//      Serial.print("\n");
   
                            // wait for a second

    
}
}

void light(int n){
  if (n == 1) // forward
    {      

    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    
    delay(1000);

    release();
    }
    else if (n == 2) // left
    {      
    release();
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    //motor4.run(FORWARD);
    
    delay(100);
    release();
    }
    else if (n == 3) // right
    {      
    release();
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    //motor3.run(FORWARD);
    motor4.run(FORWARD);
    
    delay(100);
    release();
    }
    else if (n == 4) // reverse
    {      
    //release();
    peechyAA();
    
    delay(1000);
    release();
    }
    else{
       
    release();
    }
  for(int i = 0 ; i < n; i++){
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100); 
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(100); 
  }
}

void release(){
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);  
}

void peechyAA(){
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

