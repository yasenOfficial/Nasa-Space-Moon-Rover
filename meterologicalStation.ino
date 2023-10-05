#include "DHT.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);


DHT dht;

void setup()
{
  Serial.begin(9600);
  Serial.println();
  Serial.println("Status Humidity (%)Temperature (C)");
    lcd.print("Status Humidity | Temperature (C)");


  dht.setup(2);   /* set pin for data communication */
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
}

void loop()
{
  delay(dht.getMinimumSamplingPeriod()+100);  /* Delay of amount equal to sampling period */  

  float humidity = dht.getHumidity();     /* Get humidity value */
  float temperature = dht.getTemperature(); /* Get temperature value */

  Serial.print(dht.getStatusString());
  //lcd.print(dht.getStatusString())
  
  Serial.print(humidity, 1);
  lcd.print(humidity, 1);

  Serial.print("\t\t");
  lcd.print(" % ");

  Serial.print(temperature, 1);
  lcd.print(temperature, 1);
  Serial.print("\t\t");
  lcd.print(" C");

    lcd.setCursor (0,1); // go to start of 2nd line

  
}
