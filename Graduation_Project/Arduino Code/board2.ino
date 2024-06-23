#include <SPI.h>
#include <Servo.h>

#define CW 0
#define CCW 1
#define V 0
#define H 1

#define  flameSensor   A3
#define  LimitSwitch1  A0
#define  LimitSwitch2  A1
#define  LimitSwitch3  A2
#define  IR1  A4
#define  IR2  A5

#define  trigPin      4
#define  echoPin      3
#define  Buzzer  5 
#define  startButton  7
#define  servoPin   6
#define  stepperDir  0
#define  stepperEn   1
#define  stepperPulse 2
#define  stepperRelay1 8 
#define  stepperRelay2 9 

int flag = 0;
// Create a Servo object
Servo myServo;
volatile boolean receivedFlag = false;
volatile byte receivedData = 0;
long duration;
int distance;

void Stepper_ON(int u8MotorDirection,int u8SensorPin,int u8MovementDirection)
{
	int u8SensorValue;
	
	switch(u8MotorDirection)
	{
		case 0:
		digitalWrite(stepperDir,HIGH);
		break;
		case 1:
		digitalWrite(stepperDir,LOW);
		break;
	}
	switch(u8MovementDirection)
	{
		case 0:
		digitalWrite(stepperRelay1,HIGH);  // relay pin 1  --> Horizontal motor
		digitalWrite(stepperRelay2,LOW);
		case 1:
		digitalWrite(stepperRelay2,HIGH);
		digitalWrite(stepperRelay1,LOW);	// relay pin 2 --> Vertical motor
	}
	digitalWrite(stepperEn,LOW);
	while(1)
	{
		digitalWrite(stepperPulse,HIGH);
		delayMicroseconds(150);
		digitalWrite(stepperPulse,LOW);
		delayMicroseconds(150);
		u8SensorValue = digitalRead(u8SensorPin);
		if (u8SensorValue==1)
		{
			digitalWrite(stepperEn,HIGH);
			break;
		}
		else if (u8SensorValue==5)
		{
			for (unsigned long int i=0; i<106666;i++)
			{
				digitalWrite(stepperPulse,HIGH);
				delayMicroseconds(150);
				digitalWrite(stepperPulse,LOW);
				delayMicroseconds(150);
			}
			break;	
		}
	}
}

	/*------------------------- Function Definition Of stepper motor to turn it off-----------------------------*/
void Stepper_off()
{
	digitalWrite(stepperEn,HIGH);
}

void Park(int u8Pos)
{
	switch(u8Pos)
	{
		case 1:
		Stepper_ON(CW,IR1,V);
			
		Stepper_ON(CW,5,H);
			
		Stepper_ON(CCW,LimitSwitch1,V); 
			
		Stepper_ON(CCW,LimitSwitch3,H);
			
		break;
		
		case 2:
		Stepper_ON(CW,IR2,V);
		
		Stepper_ON(CW,5,H);
		
		Stepper_ON(CCW,IR1,V);
		
		Stepper_ON(CCW,LimitSwitch3,H);
		
		Stepper_ON(CCW,LimitSwitch1,V);
		
		break;
		
		case 3:
		
		Stepper_ON(CW,LimitSwitch2,V);
		
		Stepper_ON(CW,5,H);
		
		Stepper_ON(CCW,IR2,V);
		
		Stepper_ON(CCW,LimitSwitch3,H);
		
		Stepper_ON(CCW,LimitSwitch1,V);
		
		break;
		
		default:
		break;
	}
}

void Take_out(int u8Pos)
{
	switch(u8Pos)
	{
		case 1:
		Stepper_ON(CW,5,H);
		
		Stepper_ON(CW,IR1,V);
		
		Stepper_ON(CCW,LimitSwitch3,H);
		
		Stepper_ON(CCW,LimitSwitch1,V);
		break;
		
		case 2:
		Stepper_ON(CW,IR1,V);
		
		Stepper_ON(CW,5,H);
		
		Stepper_ON(CW,IR2,V);
		
		Stepper_ON(CCW,LimitSwitch3,H);
		
		Stepper_ON(CCW,LimitSwitch1,V);
		break;
		
		case 3:
		Stepper_ON(CW,IR2,V);
		
		Stepper_ON(CW,5,H);
		
		Stepper_ON(CW,LimitSwitch2,V);
		
		Stepper_ON(CCW,LimitSwitch3,H);
		
		Stepper_ON(CCW,LimitSwitch1,V);
		break;
		
		default:
		break;
	}
}

int u8servo;
int u8Pos;
int u8Mode;
void process_recieved(int num)
{
	// num --> 123
  u8servo = num / 100;  // 1
  int n = num % 100; // 23
	u8Pos = n % 10;	// pos --> 3
	u8Mode = n / 10;   // Mode  --> 2 
}

void setup() {

  // Pins configration
  // SPI Slave
  pinMode(SS, OUTPUT);
  pinMode(MOSI, INPUT);
  pinMode(SCK, INPUT);
  pinMode(MISO, OUTPUT);
  pinMode(Buzzer,OUTPUT);
  pinMode(flameSensor,INPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(startButton, INPUT_PULLUP);

   Serial.begin(9600); // Starts the serial communication
  // Initialize SPI
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  // Initialize SPI as Slave
  SPCR |= bit (SPE);
  // Attach interrupt to SPI
  SPI.attachInterrupt();
  
  myServo.attach(servoPin);
  myServo.write(0);
}

// SPI interrupt routine
ISR(SPI_STC_vect) {
  receivedData = SPDR;  // Read data from SPI Data Register
  receivedFlag = true;  // Set flag to indicate data received
}

void loop() {

  if (receivedFlag) {
    receivedFlag = false;
    Serial.print("Received data: ");
    Serial.println(receivedData);
    process_recieved(receivedData);
  }
  if(u8servo == 1)
  {
    for(int i=0; i<=90; i++)
    {
        myServo.write(i);
    }
  }
  int startButtonValue = digitalRead(startButton);
  if(startButtonValue == 0)
  {
    for(int i=90; i>=0; i--)
    {
        myServo.write(i);
    }
    if (u8Mode == 1)
    {
      Park(u8Pos);
    }
    else if (u8Mode == 2)
    {
      Take_out(u8Pos);
    }
  
  }
  // UltraSonic sensor
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  if(distance <= 10 && flag == 0){
    digitalWrite(Buzzer, HIGH);
    flag = 1;
    delay(500);
  }
  else if(distance <= 10 && flag == 1)
  {
    digitalWrite(Buzzer, LOW);
    flag = 0;
    delay(500);
  }

  // flame sensor
  int flameValue = analogRead(flameSensor);
  if(flameValue > 0){
    digitalWrite(Buzzer, HIGH);
  }
  else{
    digitalWrite(Buzzer, LOW);
  }

}
