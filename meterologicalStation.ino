#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define DHTPIN 2  // Pin where the DHT sensor is connected
#define DHTTYPE DHT11  // Type of DHT sensor (DHT11 or DHT22)

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (C)");
  lcd.init(); // Initialize the LCD
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Status Humidity | Temperature (C)");
  dht.begin(); // Initialize the DHT sensor
}

void loop()
{
  delay(2000); // Delay for 2 seconds between readings

  float humidity = dht.readHumidity();       /* Get humidity value */
  float temperature = dht.readTemperature(); /* Get temperature value */

  Serial.print("OK");
  Serial.print("\t");
  Serial.print(humidity, 1);
  Serial.print("\t\t");
  Serial.print(temperature, 1);

  lcd.setCursor(0, 1); // Go to start of the 2nd line
  lcd.print("OK");
  lcd.print("\t");
  lcd.print(humidity, 1);
  lcd.print(" % ");
  lcd.print(temperature, 1);
  lcd.print(" C");

  lcd.setCursor(0, 0); // Return to the first line
}
