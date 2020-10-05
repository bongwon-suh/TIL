# 아두이노 블루투스 통신

### HC-05

- Bluetooth 버전: 2.0 EDR
- Bace: csr BC417 라디오 + MX 29LV800CBXBI-70G 메모리
- 동작모드: AT mode, 통신모드
- AT모드 기본 통신속도: 38400
- 통신모드 기본 통신속도: 9600
- 입력전압: 5V
- 동작전압: 3.3V
- 민감도: -80dBm
- 전송출력: +4dBm



![](https://github.com/bongwon-suh/TIL/blob/master/img/1005/01.JPG?raw=true)

![](https://github.com/bongwon-suh/TIL/blob/master/img/1005/02.JPG?raw=true)

- AT 모드 진입 방법
  - 버튼을 누른채 전원 블루투스 전원을 뽑았다가 다시 연결
  - 블루투스 LED가 2초 간격으로 점멸 시(AT 모드 진입) 버튼을 뗌
  - 연결 모드시 빠르게 LED 점멸
- AT 모드의 속도 : 38400
- 데이터 통신 속도 : 9600



- 블루투스 모듈 이름 변경
  - 'AT+NAME=원하는이름' 
- PIN 변경
  - AT+PSWD="1234"

- 역할 확인

  - AT+ROLE
    - 0: 슬레이브
    - 1: 마스터
    - 2: LOOPBACK

- 역할 변경

  - AT+ROLE=1

- 주소 확인

  - AT+ADDR

    +ADDR:18:91:d7a231 (M)

    +ADDR:18:91:d71021 (S)

- 마스터에서 슬레이브 주소 BIND

  - AT+BIND=98d3,31,fd22d7
  - AT+RESET 또는 전원 재인가