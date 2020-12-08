#include <ArduinoJson.h>
#include <ESP8266WiFi.h>

int in = D8;
int out = D7;
int thrsh = 175;
int beats, rate, beat, ex;
unsigned long time2, time1;
bool temp = true;
int lat = 1;
int lon = 2;

const char* ssid = "Deepansh Makkar";
const char* password = "9896965676";
const char* host = "maker.ifttt.com";



void setup() {
  Serial.begin(115200);
  delay(100);

  pinMode(in, INPUT);
  pinMode(out, OUTPUT);
  digitalWrite(out, LOW);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if (temp) {
    beats = Hrate();
    //push_button();
    Serial.println("Heart rate is: ");
    Serial.print(beats);
  }
}
int Hrate() {
  while (beat < 5)
  {
    if (digitalRead(in))
    {
      if (beat == 0)
        time1 = millis();
      beat++;
      while (digitalRead(in));
    }
  }
  time2 = millis();
  rate = (time2 - time1) / 5;
  rate = 60000 / rate;
  if (rate > thrsh) {
    digitalWrite(out, HIGH);
    delay(15000);
    sendmessage();
  }
  return rate;
}
void sendmessage() {

  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  String url = "/trigger/high_pulse/with/key/cAL5ONrrSgZ41TeWu0KXB-vLyJt37Kzh8Om_DRYdpwx";


  Serial.print("Requesting URL: ");
  Serial.println(url);
  client.print(String("POST ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
  temp = false;
  digitalWrite(out, HIGH);
  delay(1000);
  digitalWrite(out, LOW);
}
void push_button() {
  if (digitalRead(in)) {
    sendmessage();
  }
}
