#include <ESP8266WiFi.h>

#include <DNSServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>

#include <ESP8266HTTPClient.h>

#include <WiFiManager.h> // For more information check https://github.com/tzapu/WiFiManager and https://www.grc.com/fingerprints.htm
WiFiManager wifiManager;
HTTPClient http;

const int SERIAL_BAUD_RATE = 115200;
const int DEVICE_NUMBER = 1;

#define FINGERPRINT "08:3B:71:72:02:43:6E:CA:ED:42:86:93:BA:7E:DF:81:C4:BC:62:30"


void setup() {
  pinMode(D4, OUTPUT);
  Serial.begin(115200);

  // In case our configuration portal needs password, we can add it like this:
  // wifiManager.autoConnect("AP-NAME", "AP-PASSWORD");
  wifiManager.autoConnect("AP-NAME");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  MDNS.update();
  
  http.begin(String("https://workshop-electronica.herokuapp.com/devices/") + DEVICE_NUMBER + "/state", FINGERPRINT);
  http.GET();
  bool state = http.getString().equals("false");
  http.end();

  digitalWrite(D4, state);
  delay(400);
}
