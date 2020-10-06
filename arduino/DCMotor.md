# DC 모터

![](https://github.com/bongwon-suh/TIL/blob/master/img/1006/01.JPG?raw=true)

### 속도 설정

![](https://github.com/bongwon-suh/TIL/blob/master/img/1006/02.JPG?raw=true)

- ENA, ENB
  - 점퍼 스위치가 있는 경우 정속도(속도 조절 불가)
  - 점퍼 스위치를 제거하고 PWM핀에 연결하면 속도 조절 가능



### 모터 방향 설정

![](https://github.com/bongwon-suh/TIL/blob/master/img/1006/04.JPG?raw=true)

| IN1(IN3) | IN2(IN4) | 출력A(출력B) |
| -------- | -------- | ------------ |
| HIGH     | LOW      | 정방향       |
| LOW      | HIGH     | 역방향       |
| HIGH     | HIGH     | 정지         |
| LOW      | LOW      | 정지         |



### 회로 구성

![](https://github.com/bongwon-suh/TIL/blob/master/img/1006/03.JPG?raw=true)