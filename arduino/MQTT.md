# MQTT

### MQTT (Message Queue Telemetry Transport)

- 경량의 Publish / Subsribe 메세징 프로토콜
- M2M (Machine to Machine)과 IoT 분야 적용
- 특징
  - 저전력
  - 신뢰할 수 없는 네트워크에서 운용 가능
  - No TCP/IP 기반 운영 가능
  - 소형기기의 제어와 센서정보 수집에 유리

![](https://github.com/bongwon-suh/TIL/blob/master/img/0918/01.JPG?raw=true)



### 활용

- 센서 정보 수집
- 제어
  - 센서로 부터 받은 데이터를 토대로 기기 제어
  - 각 기기에 MQTT broker를 설치 또는 중앙 MQTT broker에 bind
- Message Push Server
  - 모바일 어플리케이션을 위한 메시지 Push 서버
  - 페이스북의 경우 MQTT를 이용하여 메시지를 push 하고 있음



### MQTT 특징

- Publish  / Subscribe
  - Publisher와 Subscriber는 모두 Broker에 대한 클라이언트로 작동
  - Publisher는 토픽을 발행
  - Subscriber는 토픽을 구독
  - 둘 다 Broker서버에 연동

![](https://github.com/bongwon-suh/TIL/blob/master/img/0918/02.JPG?raw=true)

- 토픽
  - Pub와 Sub은 토픽을 기준으로 작동
  - 토픽은 슬래시를 이용해서 계층적으로 구성
  - 대량의 센서 기기들을 효율적으로 관리

![](https://github.com/bongwon-suh/TIL/blob/master/img/0918/03.JPG?raw=true)

- 토픽 와일드 카드 문자

  - `+` 1레벨

    ex) iot/home1/+/temperature

    ​	-> iot/home1/livingroom/temperature

    ​	-> iot/home1/bedroom/temperature

  - `#`  하위 모든 레벨

- 시스템 토픽

  - $토픽명
  - 브로커 내부용으로 사용

- 메시지 버스

  - MQTT는 메시지 버스 시스템
  - MQTT broker가 메시지 버스를 만들고 여기에 메시지를 흘려보내면, 버스에 붙은 어플리케이션들이 메시지를 읽어가는 방식
  - 메시지 버스에는 다양한 주제의 메시지들이 흐를 수 있는데, 메시지를 구분하기 위해서 "Topic"을 이름으로 하는 메시지 채널을 만듬
  - 어플리케이션들은 Message Bus에 연결하고 관심있는 토픽(Topic)을 등록 해서 메시지를 구독(Sub) 하거나 발행(Pub) 함

  ![](https://github.com/bongwon-suh/TIL/blob/master/img/0918/04.JPG?raw=true)

- QoS

  - 3단계의 Qos제공
    - 0 : 메시지는 한번만 전달하며, 전달 여부를 확인하지 않는다. Fire and Forgot 타입
    - 1 : 메시지는 반드시 한번 이상 전달된다. 하지만 메시지의 핸드쉐이킹 과정을 엄밀하게 추적하지 않기 때문에, 중복 전송이 될 수도 있다.
    - 2 : 메시지는 한번만 전달된다. 메시지의 핸드쉐이킹 과정을 추적한다. 높은 품질을 보장하지만 성능의 희생이 따른다.
  - 서비스의 종류에 따라서 적당한 QoS레벨을 선택
  - No TCP/IP와 TCP/IP가 섞여있는 로컬 네트워크에서는 QoS 1, 2를 선택
  - 원격 네트워크에서는 0번
    - 네트워크의 신뢰성을 믿음
  - 클라이언트는 MQTT queue에 있는 메시지를 읽기 위해서 이전에 연결했던 MQTT에 연결
    - QoS레벨은 0으로 하고, 소프트웨어에서 QoS를 처리

  ![](https://github.com/bongwon-suh/TIL/blob/master/img/0918/05.JPG?raw=true)



### MQTT 브로커 : Mosquitto

- eclipse에서 제작 배포
- BSD라이센스 기반의 오픈소스 메시지 브로커

![](https://github.com/bongwon-suh/TIL/blob/master/img/0918/06.JPG?raw=true)



### Mosquitto 운영 테스트

- 구독자 (Subscriber) 실행
  - `mosquitto_sub -h 브로커주소 -t 토픽명`
- 발행자 (Publisher) 실행
  - `mosquitto_pub -v 브로커주소 -t 토픽명 -m 메세지`



### PubSubClient 라이브러리

- 주요 메소드

  - `PubSubClient(Client)`

    - 생성자
    - Client 객체를 매개변수로 지정
    - `WiFiEspClient espClient;`
    - `PubSubClient client(espClient);`

  - `setServer(서버주소, 포트번호)`

    - 서버 정보 설정

  - `setCallback(callback)`

    - 구독자인 경우 메시지 수신 처리 콜백 등록
    - `client.setCallback(callback);`

  - `connect()` `connect(ClientId)`

    - MQTT 서버 연결

  - `publisher(토픽, 메세지)`

    - 토픽 발행
    - `client.publisher("home/livingroom/led", message);`

  - `subscribe(토픽)`

    - 구독자로 등록
    - 주로 접속 성공 후 등록
    - `client.subscribe("home/livingroom/led");`

  - `void callback(char* topic, byte* payload, unsigned int length)`

    - 토픽 메세지 수신 시 호출

    - topic : 수신된 토픽

    - payload : 메시지 byte 배열

    - length : 수신된 메시지 길이

    - 문자열 변환 처리

      `char message[100];`

      `memcpy(message, payload, length);`
      `message[length]=NULL;`



```c++
#include <SoftwareSerial.h>
#include <WiFiEsp.h>
#include <PubSubClient.h>
#include <Ticker.h>
#include "WiFiUtil.h"

SoftwareSerial softSerial(2, 3); // RX, TX
const char ssid[] = "home"; // 네트워크 SSID
const char password[] = "123456789"; // 비밀번호
const char mqtt_server[] = "192.168.0.2"; // 서버 주소

// MQTT용 WiFi 클라이언트 객체 초기화
WiFiEspClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length) {
    payload[length] = NULL;
    char *message = payload;
    if(strcmp("1", message)==0) {
        digitalWrite(13, HIGH);
    } else {
   		digitalWrite(13, LOW);
    }
    Serial.print(topic);
    Serial.print(" : ");
    Serial.println(message);
}

void mqtt_init() {
	client.setServer(mqtt_server, 1883);
	// subscriber인경우 메시지 수신시 호출할 콜백 함수 등록
	client.setCallback(callback);
}

// MQTT 서버에 접속될 때까지 재접속 시도
void reconnect() {
	while (!client.connected()) {
		Serial.print("Attempting MQTT connection...");
        
		if (client.connect("ESP8266Client")) {
			Serial.println("connected");
			// subscriber로 등록
			client.subscribe("home/livingroom/led");
		} else {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            delay(5000);
		}
	}
}
void publish() {
    int state = !digitalRead(13);
    char message[10];
    sprintf(message, "%d", state);
    // 토픽 발행
    client.publish("home/livingroom/led", message);
}
// 2초 간격으로 publish
Ticker publishTicker(publish, 2000);

void setup() {
    wifi_init(ssid, password);
    mqtt_init();
    pinMode(13, OUTPUT);
    digitalWrite(13, LOW);
    publishTicker.start();
}
void loop() {
    if (!client.connected()) {
    	reconnect();
    }
    client.loop();
    publishTicker.update();
}
```

