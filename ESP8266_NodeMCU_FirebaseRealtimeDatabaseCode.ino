#include<Wire.h>
#include "FirebaseESP8266.h"
#include<ESP8266WiFi.h>
//#include "FirebaseESP8266.h"   // => for ESP32
//#include<ESP8266WiFi.h>        // => for ESP32

const int MledPin = 13;
char FIREBASE_AUTH [] = " "; // Your Firebase Web API Key
char FIREBASE_HOST [] = " "; // Your Firebase Host URL
char WIFI_SSID [] = " ";     // Your WIFI SSID
char WIFI_PASSWORD [] = " "; // Your WIFI Password

FirebaseData MfirebaseData;

void setup(){
  Serial.begin(115200);
  pinMode(MledPin,OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop(){
  digitalWrite(MledPin, HIGH);
  Serial.println("LED is ON");
  Firebase.setString(MfirebaseData, "/data", "ON"); //This will create a path as 'data' and save the value on Firebase
  delay(5000);  

  digitalWrite(MledPin, LOW);
  Serial.println("LED is OFF");
  Firebase.setString(MfirebaseData, "/data", "OFF");
  delay(5000);  
}
