#include <SPI.h>
#include <LiquidCrystal.h>

#define  LDR    A0
#define ledLDR	A1

#define	WCRelay 9
#define WCButton 8

int flag = 0;
void setup() {
  
  Serial.begin(9600); // Starts the serial communication
  // Initialize SPI
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  digitalWrite(SS, LOW);  // Enable slave
  // Pins configration
  // Master
  pinMode(SS, OUTPUT);
  pinMode(MOSI, OUTPUT);
  pinMode(SCK, OUTPUT);
  pinMode(MISO, INPUT);
  pinMode(ledLDR,OUTPUT);
  pinMode(WCRelay,OUTPUT);
  pinMode(WCButton,INPUT_PULLUP);
  pinMode(LDR,INPUT);
  // Initialize the library with the numbers of the interface pins
  LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // RS,E,D4,D5,D6,D7 --> RW to GND ,VSS to GND,VDD to 5V, V0 (Contrast) to the middle pin of the potentiometer
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);
   // Print a message to the LCD
  lcd.setCursor(0, 1);
  lcd.print("Welcome!");
  lcd.clear();
  lcd.setCursor(0, 4);
  lcd.print("Parking System");
  }

void loop() {
  
  // Check if data is available to read
  if (Serial.available() > 0) {
    // Read the incoming byte
    char incomingdata = Serial.read();
    digitalWrite(SS, LOW);  // Enable slave
    // Send data via SPI
    SPI.transfer(incomingdata);
    digitalWrite(SS, HIGH); // Disable slave
  }
  // sensors 
  int LDRValue = analogRead(LDR);
  if(LDRValue > 0){
    digitalWrite(ledLDR, HIGH);
  }
  else{
    digitalWrite(ledLDR, LOW);
  }
  // wirless charging 
  int WCBValue = digitalRead(WCButton);
  if(WCBValue == 0 && flag == 0){
    digitalWrite(WCRelay, HIGH);
    flag = 1;
  }
  else if(WCBValue == 0 && flag == 1)
  {
    digitalWrite(WCRelay, LOW);
    flag = 0;
  }
}
