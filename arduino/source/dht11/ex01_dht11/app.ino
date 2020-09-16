#include <DHT.h>
#include "MiniCom.h"
#define DHTPIN 3
#define DHTTYPE DHT11

DHT dht11(DHTPIN, DHTTYPE);
MiniCom com;

void checkHumiTemp(){
    float h = dht11.readHumidity();
    float t = dht11.readTemperature();

    com.print(0, "Humi", h);
    com.print(1, "Temp", t);
}

void setup(){
    com.init();
    com.setInterval(2000, checkHumiTemp);
    com.print(0, "MiniCom start");
    com.print(1,"Humi/Temp ex" );
    dht11.begin();
}

void loop(){
    com.run();
}