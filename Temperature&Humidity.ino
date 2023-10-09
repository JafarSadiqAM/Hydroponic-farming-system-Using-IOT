#define BLYNK_TEMPLATE_ID "TMPL3eNa_2N74"
#define BLYNK_TEMPLATE_NAME "Temperature and humidity monitor"
#define BLYNK_AUTH_TOKEN "CsuY8a_-USVkUXED4tl_cMogOh_vTjTa"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h>

#include <DHT.h>
char auth[] = "CsuY8a_-USVkUXED4tl_cMogOh_vTjTa";
char ssid[] = "Redmi 10 Prime";  // type your wifi name
char pass[] = "00000000";  // type your wifi password
BlynkTimer timer;

#define DHTPIN 2 //Connect Out pin to D4 in NODE MCU
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);

void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
    Blynk.virtualWrite(V0, t);
    Blynk.virtualWrite(V1, h);
    Serial.print("Temperature : ");
    Serial.print(t);
    Serial.print("    Humidity : ");
    Serial.println(h);
}
void setup()
{   
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(100L, sendSensor);
  }

void loop()
{
  Blynk.run();
  timer.run();
 }
