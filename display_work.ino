#include <SPI.h>
#include <Wire.h>
#include <DHT.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <TimesNRCyr6.h>
#define OLED_RESET 4
#define DHTPIN 2 // номер пина, к которому подсоединен датчик
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
DHT dht(DHTPIN, DHT11);
void setup() 
{
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  dht.begin();
}
void drawPixel(uint16_t x, uint16_t y, uint16_t color);
void loop() 
{       display.clearDisplay();
        display.setFont(&TimesNRCyr6pt8b);
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0,12);
        float h = dht.readHumidity();
        float t = dht.readTemperature();

      if (isnan(h) || isnan(t)) { //проверка информации с датчиков
        
        display.print("Не удается считать показания");
        display.display();
        delay(1000);
      return;
}
        display.clearDisplay();
        display.drawCircle (93, 5, 1, 1);
        display.print("Температура: ");
        display.print(round(t));
        display.setCursor(90, 12);
        display.println("  C");
        display.print("Влажность: ");
        display.print(round(h));
        display.println(" %");
        display.display();
        delay(15000);
}
