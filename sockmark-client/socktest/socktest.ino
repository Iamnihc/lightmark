#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
// Set WiFi credentials
#define WIFI_SSID "Mi Wi Fi"
#define WIFI_PASS "--\\_(0_0)_/--"
IPAddress server(192, 168, 86, 69);
WiFiClient client;
HTTPClient http;
void setup()
{
  // Setup serial port
  Serial.begin(115200);
  Serial.println();

  // Begin WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  // Connecting to WiFi...
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  // Loop continuously while WiFi is not connected
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.print(".");
  }

  // Connected to WiFi
  Serial.println();
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());
}

void loop()
{
  http.begin("http://192.168.86.69:8080");
  http.GET();
  Serial.print(http.getString());
  while (client.available())
  {
    char[]
    char c = client.read();

    Serial.write(c);
  }

  Serial.println("\nStarting connection to server...");

  // if you get a connection, report back via serial:

  if (client.connect(server, 8080))
  {

    Serial.println("connected to server");

    // Make a HTTP request:

    client.println("GET /");
    client.println();
  }
  delay(100)
}