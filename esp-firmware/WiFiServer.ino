/*
 *  This sketch demonstrates how to set up a simple HTTP-like server.
 *  The server will set a GPIO pin depending on the request
 *    http://server_ip/gpio/0 will set the GPIO2 low,
 *    http://server_ip/gpio/1 will set the GPIO2 high
 *  server_ip is the IP address of the ESP8266 module, will be 
 *  printed to Serial when the module is connected.
 */

#include <ESP8266WiFi.h>

const char* ssid = "We are here!";
const char* password = "eqwilibrium";

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(8888);

void setup() {
  Serial.begin(115200);
  delay(10);
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);

  int atempts = 60;
  while (WiFi.status() != WL_CONNECTED && atempts != 0) {
    delay(500);
    Serial.print(".");
    atempts--;
  }

  Serial.println("");
  IPAddress myIP;
  if (WiFi.status() != WL_CONNECTED)
  {
    String msg = "WiFi not connected to \"";
    msg += ssid;
    msg += "\"";
    Serial.println(msg);
    Serial.println("Setting up access point");
    WiFi.softAP("CamControl device");
    myIP = WiFi.softAPIP();
  }
  else
  {
    Serial.println("WiFi connected");
    myIP = WiFi.localIP();
  }
  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(myIP);
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  
  int req = client.read();
  Serial.println(req);
  client.flush();
  
  client.print("OK!!");
  delay(1);
  Serial.println("Client disonnected");
}

