#include <LiquidCrystal.h>              //include the LiquidCrystal library
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);    //define LCD pins (RS, E, D4, D5, D6, D7)

int ACWATERPUMP = 12; //You can remove this line, it has no use in the program.
int sensor = 9; //You can remove this line, it has no use in the program.
int val; //This variable stores the value received from Soil moisture sensor.

#include <DHT.h>             //include the DHT library
#define DHTPIN 10               // thermokasia pin Connect the signal pin of DHT11 sensor to digital pin 5
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  pinMode(12,OUTPUT); //Set pin 13 as OUTPUT pin, to send signal to relay
  pinMode(9,INPUT);//Set pin 8 as input pin, to receive data from Soil moisture sensor.
 
  lcd.begin(16,2);                      //initializes the LCD and specifies the dimensions
  dht.begin(); 
}
void loop() {
  val = digitalRead(9);  //Read data from soil moisture sensor  
  if(val == LOW)
  {
   digitalWrite(12, LOW); //if soil moisture sensor provides LOW value send LOW value to relay
  }
  else
  {
    digitalWrite(12, HIGH); //if soil moisture sensor provides HIGH value send HIGH value to relay
  }
  delay(400); //Wait for few second and then continue the loop.

  float temp = dht.readTemperature();  //dht.readTemperature();
  float humi = dht.readHumidity();     // dht.readHumidity();
 
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("Humi: ");
  lcd.print(humi);
  lcd.print(" %");
  delay(2000);
}
