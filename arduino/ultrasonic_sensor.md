# 초음파 센서

### 초음파 센서

- 초음파를 이용하여 벽이나 사물의 거리를 측정하는 센서
- HC-SR04 모듈
  - Vcc : 전원
  - Trig : 트리거(초음파 송출 제어)
  - Echo : 에코(초음파 수신)
  - GND : 접지



### 초음파 센서 동작 원리

- Trig에서 HIGH 전압 인가시 초음파 발사
- Echo에서 초음파 수신(처음에는 LOW)
- 시간차이를 측정하여 거리 계산

![](https://github.com/bongwon-suh/TIL/blob/master/img/0916/04.JPG?raw=true)

![](https://github.com/bongwon-suh/TIL/blob/master/img/0916/05.JPG?raw=true)



### 거리 계산

- 음속 : 340 m/s

- 비례식

  - 1,000,000 us : 34,000 cm = x us : y cm

  - y = 34,000*x/1,000,000

       = 0.034*x cm



### delayMircroseconds()

- 아두이노 보드를 일정 시간 멈추는 함수
- `delayMicroseconds(2)` 아두이노 보드를 0.002m/s(0.000002초)



### pulsIn()

- 디지털 입력 핀의 전압이 LOW 또는 HIGH가 될 때까지 걸린 시간 측정
- 핀은 꼭 pinMode 함수를 이용하여 입력 모드를 설정
- `pulseIn(핀번호, 전압)`
  - 핀 번호 : 전압이 바뀌는 시간을 재고자 하는 핀 번호
  - 전압 : 바뀌는 전압. HIGH - LOW 에서 HIGH가 될 때
- 반환값
  - 전압이 바뀌는데 걸린 시간을 마이크로초 기준으로 반환
  - 만약 1초 동안 기달렸는데도 전압이 바뀌지 않으면 0을 반환



### 회로 구성

![](https://github.com/bongwon-suh/TIL/blob/master/img/0916/06.JPG?raw=true)



```c++
#include <MiniCom.h>
#include "Ultra.h"
MiniCom com;
Ultra ultra(2, 3);


void checkDistance(){
    int distance = ultra.read();
    com.print(0, "distance", distance);
}
void setup() {
    com.init();
    com.setInterval(1000, checkDistance);
}

void loop(){
    com.run();
}
```

