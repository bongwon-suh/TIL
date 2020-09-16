# DHT11

### 온/습도 센서

- 내부에 써미스터와 정전식 습도 센서가 내장되어있는 온습도 센서
- 내부 써미스터는 온도에 따라 저항 값이 변하는 소자
- 정전식 습도 센서는 습도에 따라 저항 값이 변하는 소자
- 총 3개의 핀으로 구성되어 있으며 VCC, GND, DATA로 구성
- 온도 측정시 써미스터 특성상 약 1분 정도의 시간이 소요
- DHT11 라이브러리 이용



### 회로 구성

![](https://github.com/bongwon-suh/TIL/blob/master/img/0916/03.JPG?raw=true)



``` c++
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
```

