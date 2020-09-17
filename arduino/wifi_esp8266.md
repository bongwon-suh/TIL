# WIFI ESP8066

### SoftSerial

- 아두이노 UNO는 RX(0번) / TX(1번) 핀 1벌만 지원(PC 연결에 사용)
- 일반 디지털 핀을 소프트웨어적으로 RX/TX 처리 이용 필요
  - SoftSerial
- 2번 핀 / 3번 디지털핀을 RX/TX로 연결
- 9600 속도에서 안정적으로 동작
  - 더 빨리지면 오류 발생
  - ESP8266의 속도를 9600으로 설정 필요



### ESP8266

![](https://github.com/bongwon-suh/TIL/blob/master/img/0917/01.JPG?raw=true)

- RX/TX 핀은 3.3V로 동작
  - 아두이노 디지털 출력은 5V로 전압 강하 필요
  - 1:2비율로  전압 강하로 RX로 연결
  - 아두이노는 1.7V 이상을 HIGH 미만을 LOW로 인식하므로 TX는 바로 연결



### 회로구성

![](https://github.com/bongwon-suh/TIL/blob/master/img/0917/02.JPG?raw=true)



``` c++
#include <SoftwareSerial.h>
#define BT_RXD 2
#define BT_TXD 3
SoftwareSerial softSerial(BT_RXD, BT_TXD);
void setup() {
    Serial.begin(9600);
    // 펌웨어로 설정된 디폴트 속도는 115200 bps
    softSerial.begin(115200); // 펌웨어 설정에 따라 조정
    softSerial.setTimeout(5000);
    delay(1000);
}
void loop() {
    if (Serial.available()){
    softSerial.write(Serial.read());
    }
    if (softSerial.available()) {
    Serial.write(softSerial.read());
    }
}
```



### AT 명령어

- `AT`
  - 동작 여부 확인 
  - 정상 : OK 응답
  - 비정상 : 무응답
- 보드레이트 재정의(펌웨어 디폴트 : 115200)
  - `AT+UART_DEF=9600,8,1,0,0`
- `AT+RST` 리셋 
- `AT+GMR` 모듈 버전 확인
- `AT+CWMODE(Current Working Mode) `
  - AT+CWMODE? : 현재 모드 출력
  - AT+CWMODE=1(Stand Alone) / 2(AP) / 3(Stand Alone + AP)
- `AT+CWLAP` AP 리스트 출력
- `AT+CWJAP`
  - AP 접속 명령
  - AT+CWJAP="SSID","비밀번호"
  - AT+CWJAP="SevenRoom3","12345678"
- AT+CIFSR
  - 접속 IP 확인
  - 192.168.25.4
- `AT+CWQAP` AP 접속 해제



### WiFiESP 라이브러리 메소드

- WiFi AP(공유기)에 접속하고 IP를 받는 역할 
- `WiFi.init(&softSerial)`  SoftwareSerial을 통해 초기화
- `WiFi.status()` AP 연결 상태 리턴 
- `WiFi.begin(ssid, password)`
  - AP 접속 
  - 접속 성공시 IP 할당 받음
- `WiFi.SSID()`  AP의 SSID 리턴 
- `WiFi.localIP()` 할당 받은 IP (IPAddress 객체) 리턴
- `WiFi.RSSI()` AP의 신호 강도 리턴



```c++
#include <WiFiEsp.h>
#include <SoftwareSerial.h>
SoftwareSerial softSerial(2, 3); // RX, TX
char ssid[] = "Twim"; // your network SSID (name)
char pass[] = "12345678"; // your network password
int status = WL_IDLE_STATUS; // the Wifi radio's status

void setup() {
    Serial.begin(115200);
    softSerial.begin(9600);
    WiFi.init(&softSerial);
    if (WiFi.status() == WL_NO_SHIELD) {
        Serial.println("WiFi shield not present");
        while (true);
    }
    while ( status != WL_CONNECTED) {
        Serial.print("Attempting to connect to WPA SSID: ");
        Serial.println(ssid);
        status = WiFi.begin(ssid, pass);
    }
    Serial.println("You're connected to the network");
    printWifiStatus();
}
void loop() {
}
void printWifiStatus() {
    // print the SSID of the network you're attached to
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());
    // print your WiFi shield's IP address
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);
    // print the received signal strength
    long rssi = WiFi.RSSI();
    Serial.print("Signal strength (RSSI):");
    Serial.print(rssi);
    Serial.println(" dBm");
}
```



### WiFiEspClient 객체

- TCP Socket 처리 객체
- connect(서버주소, 포트번호)
  - 지정 서버의 포트 번호로 접속
- print(), println()
  - 메세지 출력
- available()
  - 수신된 메시지 존재 여부
  - 수신된 메시지의 길이 리턴
- read()
  - 수신 메시지의 1바이트 읽기