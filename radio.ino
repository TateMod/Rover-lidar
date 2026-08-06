#include <SPI.h>
#include "RF24.h"

#define CE_PIN 7
#define CSN_PIN 6

int leftPWM;
int rightPWM;
double leftPower;
double rightPower;

int deadzone = 20; 
int center = 512;

const byte Analog_X_pin = A5;
const byte Analog_Y_pin = A4;
const byte Analog_Button_pin = 2;


int analog_x = 0;
int analog_y = 0;
bool aalog_but = false;


int32_t data;

RF24 radio(CE_PIN, CSN_PIN);
uint8_t address[6] = "1Node";






void tank(double x,double y){
  double drive = -y;
  double turn = x;

   leftPower = drive + turn;
   rightPower = drive - turn;
//fabs for decimals
  double largest = max(fabs(leftPower),(fabs(rightPower)));
if (largest > 1.0){

  leftPower = leftPower/largest;
  rightPower = rightPower/largest;
}



//Serial.print("Left: ");
 // Serial.print(leftPower);
 // Serial.print(" | Right: ");
 // Serial.println(rightPower);

}

















void setup() {
  Serial.begin(115200); 
  radio.begin();
  radio.setPALevel(RF24_PA_LOW);
  radio.openWritingPipe(address);
  radio.stopListening();

  int data = 0;
	


  pinMode(Analog_X_pin, INPUT);
  pinMode(Analog_Y_pin, INPUT);  
  pinMode(Analog_Button_pin, INPUT_PULLUP);

 


}

void loop() {
int raw_x = analogRead(Analog_X_pin);
  int raw_y = analogRead(Analog_Y_pin);

  // Map raw analog values (0 to 1023) to a -1.0 to 1.0 scale
  double x = (raw_x - 512.0) / 512.0;
  double y = (raw_y - 512.0) / 512.0;







tank(x,y);


int leftPWM  = (int8_t)(leftPower * 127.0);
int rightPWM = (int8_t)(rightPower * 127.0);


if (leftPWM < 20 && leftPWM > -20){
  leftPWM = 0;

}
if (rightPWM < 20 && rightPWM > - 20){
  rightPWM = 0;

}


Serial.println(leftPWM);
Serial.println(rightPWM);

uint8_t motorData[2];
  motorData[0] = (int8_t)leftPWM;
  motorData[1] = (int8_t)rightPWM;
// conver to 

 bool motor = radio.write(motorData, sizeof(motorData));



  //Serial.println(ok ? "sent" : "failed");


   

delay(10);




   }
