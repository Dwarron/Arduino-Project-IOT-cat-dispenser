#include <Servo.h>  // on inclut la bibliothèque pour piloter un servomoteur
#include <ESP8266WiFi.h>

const char* ssid = "Livebox-453A"; 
const char* password = "";
int servoPos = 0;

WiFiServer server(80);
Servo monServo;  // on crée l'objet monServo

void setup() {
  pinMode(13, OUTPUT);
  //Serial.begin(115200);
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }
  server.begin();
  Serial.println("Server started");
  Serial.println(WiFi.localIP());

  monServo.attach(A0); // on définit le Pin utilisé par le servomoteur
  monServo.write(0);
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  while (!client.available())
  {
    delay(1);
  }
  String req = client.readStringUntil('\r');
  client.flush();
  if (req.indexOf("/LEDoff") != -1)
  {
    Serial.print("0");
  }
  else if (req.indexOf("/LEDon") != -1)
  {
    Serial.print("1");
  }
  else if (req.indexOf("/distrib") != -1)
  {
    Serial.print("2");
  }

  String web = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r \n\r\n";
  web += "<html>\r\n";
  
  web += "<style type='text/css'>";
  web += "body {";
  web += "text-align: center;";
  web += "font-size: 40px;";
  web += "}";
  web += "button {";
  web += "resize: both;";
  web += "overflow: auto;";
  web += "min-width: 90%;";
  web += "min-height: 30%;";
  web += "text-align: center;";
  web += "font-size: 30px;";
  web += "border: 8px solid blue;";
  web += "border-radius: 100px;";
  web += "}";
  web += "</style>";
  
  web += "<body>\r\n";
  web += "<h1>Cat Dispenser</h1>\r\n";
  web += "<h2>Arduino ATmega328ESP8266</h2>\r\n";
  web += "<p>\r\n";
  web += "<a href=\"/LEDon\">\r\n";
  web += "<button>LED On</button>\r\n";
  web += "</a>\r\n";
  web += "</p>\r\n";
  web += "<a href=\"/LEDoff\">\r\n";
  web += "<button>LED Off</button>\r\n";
  web += "</a>\r\n";

  web += "<p>\r\n"; 
  web += "<a href=\"/distrib\">\r\n";
  web += "<button>Distribution des croquettes</button>\r\n";
  web += "</a>\r\n";
  web += "</p>\r\n";
  
  web += "</body>\r\n";
  web += "</html>\r\n";

  client.print(web);
}
