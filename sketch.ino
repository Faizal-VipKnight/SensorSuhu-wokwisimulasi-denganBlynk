#define BLYNK_TEMPLATE_ID "TMPL6VGpR1mtf"
#define BLYNK_TEMPLATE_NAME "SensorDS18B20"
#define BLYNK_AUTH_TOKEN "v-Pvrt8pH8BUoDfalgtVAgfYaj7Gi8t5"

#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

BlynkTimer timer;

#include <WiFi.h>

#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define SENSOR_PIN  4 // ESP32 pin GPIO17 connected to DS18B20 sensor's DATA pin
const int buzzer = 5;
OneWire oneWire(SENSOR_PIN);
DallasTemperature DS18B20(&oneWire);

float tempC; // temperature in Celsius
//float tempF; // temperature in Fahrenheit

void setup() {
    Serial.begin(9600);
    delay(1000);  // Tunggu 1 detik sebelum inisialisasi
    Serial.println("Connecting to WiFi...");

    WiFi.begin(ssid, pass);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nWiFi connected!");
    Serial.println(WiFi.localIP());  // Menampilkan IP Address
    Blynk.begin(auth, ssid, pass);
    timer.setInterval(2000L, sendSensor);

     
  
    lcd.init();
    //lcd.init(16, 2);
    //lcd.begin();               
  //lcd.begin(16,2);         
    lcd.backlight();
    DS18B20.begin(); 
}

void loop() {
  DS18B20.requestTemperatures();       // send the command to get temperatures
  tempC = DS18B20.getTempCByIndex(0);  // read temperature in °C
  //tempF = tempC * 9 / 5 + 32; // convert °C to °F

  if (isnan(tempC)) {
    Serial.println("Failed to read temperature from sensor!");
    return;  // Hentikan eksekusi jika pembacaan suhu gagal
  } else {
    Serial.print("Current Temperature: ");
    Serial.println(tempC);
  }

if (isnan(tempC)) {
    Serial.println("Failed to read temperature from sensor!");
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
    delay(1000);
    return;
  } else {
    // Display temperature on Serial Monitor and LCD
    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.println("°C");

    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(tempC);
    lcd.print(" C   ");
  }
  // lcd.setCursor(0,0);             // karakter dimulai dari kolom 1 baris 3
  // lcd.print("Temc:");            // Karakter yang akan ditampilkan pada LCD
  // lcd.print(tempC);               // Menampilkan data jarak pada LCD
  // lcd.print("    °C");

    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(tempC);
    lcd.print(" C   ");

  // Serial.print("Temperature: ");
  // Serial.print(tempC);    // print the temperature in °C
  // Serial.print("°C");


  // delay(500);

  if ( tempC >= 100){       //buzzer akan bunyi ketika suhu diatas atau sama dengan 100 derajat
    tone(buzzer, 1000);
    delay(1000);

  } else {
      noTone(buzzer);
      delay(1000);
  }

  Blynk.run();
  timer.run();
}

void sendSensor(){
  Blynk.virtualWrite(V0, tempC);
  Serial.print("Sent to Blynk: ");
  Serial.println(tempC);

}

