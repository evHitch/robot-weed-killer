#include <SoftwareSerial.h> // module for arduino to use BT
SoftwareSerial bluetooth(12, 13);
#define BTpin 11
#define relay_Pin 46
#define LMOTOR_IN1 3
#define LMOTOR_IN2 4
#define LMOTOR_IN3 7 // define pins, changes might be needed
#define LMOTOR_IN4 8
#define RMOTOR_IN1 24
#define RMOTOR_IN2 25
#define RMOTOR_IN3 32
#define RMOTOR_IN4 33
long tick = 0;
bool is_connected = false;
void setup(){
	pinMode(relay_Pin, OUTPUT);
	pinMode (LMOTOR_IN1, OUTPUT);
	pinMode (LMOTOR_IN2, OUTPUT); // sets up motors with pins
	pinMode (LMOTOR_IN3, OUTPUT);
	pinMode (LMOTOR_IN4, OUTPUT);
	pinMode (RMOTOR_IN1, OUTPUT);
	pinMode (RMOTOR_IN2, OUTPUT);
	pinMode (RMOTOR_IN3, OUTPUT); 
	pinMode (RMOTOR_IN4, OUTPUT);
  pinMode(BTpin,INPUT);
	// initialize serial to debug 
	Serial.begin(9600);
	// initialize the bluetooth
	bluetooth.begin(9600);
	//bluetooth.println("Bluetooth ready");
	Brake();
}

void loop() {
		//char in_char = Serial.read();
    while(1){
      char in_char = bluetooth.read();
      
      if (in_char=='q' || in_char=='l' || in_char=='c'){ // inputs for left turns
        Left();
      }
      else if(in_char=='e' || in_char=='z' || in_char=='r'){ // inputs for right turns
        Right();
      }
      else if(in_char=='b'){ // backwards
        Backward();
      }
      else if(in_char=='f'){ // forwards
        Forward();
      }
      else if(in_char=='s'){ // stops
        Brake();
      }
      else if(in_char=='+'){ // laser toggle on
        LaserOn();
      }
      else if(in_char=='-'){ // laser toggle off
        LaserOff();
      }
      tick++;

      if(tick >= 50000){ // tick system to handle disconnect safety
        tick = 0;
        Brake();
        LaserOff();
        //Serial.println("ebrake");
      }
    }
}
void Forward(){
  digitalWrite(LMOTOR_IN1,HIGH); // HIGH,LOW sets the motor fowards
  digitalWrite(LMOTOR_IN2,LOW); // LIN1 and LIN2 is motor 1(Left side)
  digitalWrite(LMOTOR_IN3,HIGH);// LIN3 and LIN4 is motor 2(Left Side)
  digitalWrite(LMOTOR_IN4,LOW);
  
  digitalWrite(RMOTOR_IN1,HIGH); // Both left and right side go foward
  digitalWrite(RMOTOR_IN2,LOW);
  digitalWrite(RMOTOR_IN3,HIGH);// RIN1 and RIN2 is motor 3(Right side)
  digitalWrite(RMOTOR_IN4,LOW); // RIN3 and RIN4 is motor 4(Right side)
  
}

void ForwardLeft(){
 // digitalWrite(LMOTOR_IN1,LOW); // Left side goes backwards, 
  //digitalWrit(LMOTOR_IN2,LOW);// Right side goes forwards,
  //digitalWrite(LMOTOR_IN3,LOW); // this results in the robot turning0 counter-clockwise
  //digitalWrite(LMOTOR_IN4,LOW);

  digitalWrite(RMOTOR_IN1,HIGH); 
  digitalWrite(RMOTOR_IN2,LOW);
  digitalWrite(RMOTOR_IN3,HIGH);
  digitalWrite(RMOTOR_IN4,LOW);
}

void ForwardRight(){
  //-digitalWrite(RMOTOR_IN1,LOW); // Right side goes backwards,
  //-digitalWrite(RMOTOR_IN2,HIGH);// Left side goes forwards,
  //digitalWrite(RMOTOR_IN3,LOW);// this results in the robot turning clock-wise,
  //digitalWrite(RMOTOR_IN4,HIGH);

  digitalWrite(LMOTOR_IN1,HIGH); 
  digitalWrite(LMOTOR_IN2,LOW);
  digitalWrite(LMOTOR_IN3,HIGH);
  digitalWrite(LMOTOR_IN4,LOW);
}

void Backward(){
  digitalWrite(LMOTOR_IN1,LOW); // LOW,HIGH sets the motor backwards
  digitalWrite(LMOTOR_IN2,HIGH);
  digitalWrite(LMOTOR_IN3,LOW);
  digitalWrite(LMOTOR_IN4,HIGH);

  digitalWrite(RMOTOR_IN1,LOW); // Both left and right side go backwards
  digitalWrite(RMOTOR_IN2,HIGH);
  digitalWrite(RMOTOR_IN3,LOW);
  digitalWrite(RMOTOR_IN4,HIGH);
  
}
void Left(){
  digitalWrite(LMOTOR_IN1,LOW); // Left side goes backwards, 
  digitalWrite(LMOTOR_IN2,HIGH);// Right side goes forwards,
  digitalWrite(LMOTOR_IN3,LOW); // this results in the robot turning0 counter-clockwise
  digitalWrite(LMOTOR_IN4,HIGH);

  digitalWrite(RMOTOR_IN1,HIGH); 
  digitalWrite(RMOTOR_IN2,LOW);
  digitalWrite(RMOTOR_IN3,HIGH);
  digitalWrite(RMOTOR_IN4,LOW);
}

void Right(){
  digitalWrite(RMOTOR_IN1,LOW); // Right side goes backwards,
  digitalWrite(RMOTOR_IN2,HIGH);// Left side goes forwards,
  digitalWrite(RMOTOR_IN3,LOW);// this results in the robot turning clock-wise,
  digitalWrite(RMOTOR_IN4,HIGH);

  digitalWrite(LMOTOR_IN1,HIGH); 
  digitalWrite(LMOTOR_IN2,LOW);
  digitalWrite(LMOTOR_IN3,HIGH);
  digitalWrite(LMOTOR_IN4,LOW);
}

void Brake(){
  digitalWrite(LMOTOR_IN1,LOW);
  digitalWrite(LMOTOR_IN2,LOW);
  digitalWrite(LMOTOR_IN3,LOW);
  digitalWrite(LMOTOR_IN4,LOW);

  digitalWrite(RMOTOR_IN1,LOW);
  digitalWrite(RMOTOR_IN2,LOW);
  digitalWrite(RMOTOR_IN3,LOW);
  digitalWrite(RMOTOR_IN4,LOW); 
}

void LaserOn(){
	digitalWrite(relay_Pin,HIGH);
}

void LaserOff(){
	digitalWrite(relay_Pin,LOW);
}