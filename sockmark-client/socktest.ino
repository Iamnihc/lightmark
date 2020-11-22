#include <b64.h>


#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
// Set WiFi credentials
#define WIFI_SSID "Mi Wi Fi"
#define WIFI_PASS "--\\_(0_0)_/--"
IPAddress server(192, 168, 86, 69);
char serverAddress[] = "http://192.168.86.69";  // server address
int port = 8080;
WiFiClient wclient;
WebSocketClient client = WebSocketClient(wifi, serverAddress, port);
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
    Serial.println("starting WebSocket client");
  client.begin();

  while (client.connected()) {
    Serial.print("Sending hello ");
    Serial.println(count);

    // send a hello #
    client.beginMessage(TYPE_TEXT);
    client.print("hello ");
    client.print(count);
    client.endMessage();

    // increment count for next message
    count++;

    // check if a message is available to be received
    int messageSize = client.parseMessage();

    if (messageSize > 0) {
      Serial.println("Received a message:");
      Serial.println(client.readString());
    }

    // wait 5 seconds
    delay(5000);
  }

  Serial.println("disconnected");

  // http.begin("http://192.168.86.69:8080");
  // http.GET();
  // Serial.print(http.getString());
  // while (client.available())
  // {
  //   char[]
  //   char c = client.read();

  //   Serial.write(c);
  // }

  // Serial.println("\nStarting connection to server...");

  // // if you get a connection, report back via serial:

  // if (client.connect(server, 8080))
  // {

  //   Serial.println("connected to server");

  //   // Make a HTTP request:

  //   client.println("GET /");
  //   client.println();
  // }
  // delay(100)
}