#include <DHT.h> 
#include <ESP8266WiFi.h> 
#include <MicroGear.h>

const char* ssid = "I'm Zheza GOD";      //************Change*******************
const char* password = "P@ssw0rd";        //************Change*******************

#define APPID "testMid"   //************Change*******************
#define KEY "vlJts3GT67DzPPs"     //************Change*******************
#define SECRET "HjXhVkul3GJNixmC18YiyREcx"  //************Change*******************
#define ALIAS "PHUNUDET_8266" 
WiFiClient client;
int timer = 0; 
char str[32];
#define DHTTYPE DHT22 //Define sensor type 
#define DHTPIN D4 // Define sensor pin 
DHT dht(DHTPIN, DHTTYPE, 15); //Initialize DHT sensor
int humid; 
int temp;
MicroGear microgear(client);  

void onMsghandler(char *topic, uint8_t* msg, unsigned int msglen) {
      Serial.print("Incoming message --> ");
      msg[msglen] = '\0';
      Serial.println((char *)msg);
}

void onConnected(char *attribute, uint8_t* msg, unsigned int msglen) {
      Serial.println("Connected to NETPIE...");
      microgear.setAlias(ALIAS);
}
void setup() { 
  dht.begin();
  
  microgear.on(MESSAGE,onMsghandler);
  microgear.on(CONNECTED,onConnected);
  Serial.begin(115200);
  Serial.println("Starting...");

  if (WiFi.begin(ssid, password)) {
      while (WiFi.status() != WL_CONNECTED) {
          delay(500);
          Serial.print(".");
      }
  }
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
  microgear.init(KEY,SECRET,ALIAS);
  microgear.connect(APPID);
}

void loop() {
  if (microgear.connected()) {
      Serial.println("connected");
      if (timer >= 1000) {
          humid = dht.readHumidity();
          temp = dht.readTemperature();
          sprintf(str,"%d,%d",humid,temp);
          Serial.println(str);
          Serial.println("Sending --> "); 
          microgear.publish("/dht",str);
          microgear.publish("/kfc",str); /////////////////////kfc
          timer = 0;
      }
      else timer += 100;
  }
  else { 
    Serial.println("connection lost, reconnect...");
    if (timer >= 5000) { 
      microgear.connect(APPID);
      timer = 0;
      }
      else timer += 100;
  }
  delay(1000);
}

