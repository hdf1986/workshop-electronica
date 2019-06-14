#include <ESP8266WiFi.h> 

#include <DNSServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>

#include <ESP8266HTTPClient.h>

#include <WiFiManager.h> // For more information check https://github.com/tzapu/WiFiManager and https://www.grc.com/fingerprints.htm
WiFiManager wifiManager;

const int SERIAL_BAUD_RATE = 115200;
const int DEVICE_NUMBER = 1;

#define FINGERPRINT "C1:0D:53:49:D2:3E:E5:2B:A2:61:D5:9E:6F:99:0D:3D:FD:8B:B2:B3"


void setup() {
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

  HTTPClient http;

  http.begin("https://hooks.slack.com/services/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", FINGERPRINT);
  // In case you want to create a hook, look for the webhook application in your slack workspace
  http.addHeader("Content-Type", "application/json");
  http.POST(String("") + "{\"text\": \"Dispositivo #" + DEVICE_NUMBER +  "\"}");
  Serial.println(http.getString());
  http.end();
  Serial.println("Sent request");
  
}

void loop() {
  MDNS.update();
}
