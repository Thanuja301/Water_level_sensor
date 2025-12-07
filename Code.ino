#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>

// ---------- WIFI ----------
const char* ssid = "Thanuja301";
const char* password = "Th@nu2006";

// ---------- THINGSPEAK MQTT ----------
const char* mqttServer = "mqtt3.thingspeak.com";
const int mqttPort = 8883;

int channelID = 3170146;

const char mqttUserName[] = "DDohKiATPCgmHBs5Axo5ABI";
const char clientID[]     = "DDohKiATPCgmHBs5Axo5ABI";
const char mqttPass[]     = "+dI3fSbZACrJegAwWmsZIkWL";

WiFiClientSecure espClient;
PubSubClient mqttClient(espClient);

// Water Level Sensor pin
int sensorPin = 34;

void setup() {
  Serial.begin(115200);
  delay(2000);

  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("\nWiFi Connected!");
  Serial.println(WiFi.localIP());

  espClient.setInsecure();

  mqttClient.setServer(mqttServer, mqttPort);

  Serial.println("Connecting to ThingSpeak MQTT...");
  while (!mqttClient.connect(clientID, mqttUserName, mqttPass)) {
    Serial.println("MQTT connect failed. Retrying...");
    delay(2000);
  }
  Serial.println("MQTT Connected!");
}

void loop() {
  int waterValue = analogRead(sensorPin);
  Serial.print("Water Level Value: ");
  Serial.println(waterValue);

  if (!mqttClient.connected()) {
    Serial.println("MQTT disconnected… reconnecting");
    mqttClient.connect(clientID, mqttUserName, mqttPass);
  }

  String topic = "channels/" + String(channelID) + "/publish";
  String payload = "field1=" + String(waterValue);

  mqttClient.publish(topic.c_str(), payload.c_str());

  Serial.println("Data Sent to ThingSpeak!");
  delay(15000);
}
