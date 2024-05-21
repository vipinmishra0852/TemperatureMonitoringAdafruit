#include <SimpleDHT.h>                
#include <WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

#define SSID "POCO M2 Pro"
#define PASS "00000000"

#define SERVER "io.adafruit.com"   
#define SERVERPORT 1883
#define USERNAME "YourUsername"
#define KEY "YourKey"
WiFiClient client;

Adafruit_MQTT_Client mqtt(&client, SERVER, SERVERPORT, USERNAME, KEY);
Adafruit_MQTT_Publish Temperature = Adafruit_MQTT_Publish(&mqtt, USERNAME "/feeds/Temperature");
Adafruit_MQTT_Publish Humidity = Adafruit_MQTT_Publish(&mqtt, USERNAME "/feeds/Humidity");
 
int pinDHT11 = 15;  
SimpleDHT11 dht11(pinDHT11);
byte hum = 0;  
byte temp = 0; 

void connect() {
  Serial.println("Connecting to Adafruit IO... ");
  int ret;

  while ((ret = mqtt.connect()) != 0) {
    switch (ret) {
      case 1: Serial.println(F("Wrong protocol")); break;
      case 2: Serial.println(F("ID rejected")); break;
      case 3: Serial.println(F("Server unavail")); break;
      case 4: Serial.println(F("Bad user/pass")); break;
      case 5: Serial.println(F("Not authed")); break;
      case 6: Serial.println(F("Failed to subscribe")); break;
      default: Serial.println(F("Connection failed")); break;
    }
 
    if(ret >= 0) mqtt.disconnect();
 
    Serial.println(F("Retrying connection..."));
    delay(10000);
  }
  Serial.println(F("Adafruit IO Connected!"));
}
 
void setup()  {
  Serial.begin(115200);

  Serial.println(); Serial.println();
  delay(10);
  Serial.print(F("Connecting to "));
  Serial.println(SSID);
  WiFi.begin(SSID, PASS); //Connect to WiFi

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(F("."));
  }

  Serial.println();
  Serial.println(F("WiFi connected"));
  Serial.println(F("IP address: "));
  Serial.println(WiFi.localIP());

  connect();
}
 
void loop() {

  // ping adafruit io a few times to make sure we remain connected
  if(! mqtt.ping(3)) {
    if(! mqtt.connected()) connect();
  }

  dht11.read(&temp, &hum, NULL);
  Serial.print((int)temp); Serial.print(" *C, ");
  Serial.print((int)hum); Serial.println(" H");
  delay(5000);
   
  if (!Temperature.publish(temp)) { Serial.println(F("Failed")); }              //Publish Temperature data to Adafruit
  if (!Humidity.publish(hum)) { Serial.println(F("Failed")); }         //Publish Humidity data to Adafruit
  else { Serial.println(F("Sent!")); }
  
}
 
 
