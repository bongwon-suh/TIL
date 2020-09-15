# 가변저항

### 가변저항 특성

- 값이 변하는 저항

- 세 개의 선으로 회로에 연결

- 연결 방법에 따라 두가지 기능 제공

  - 바깥 단자와 중간 단자만 연결하는 경우

    ![](https://github.com/bongwon-suh/TIL/blob/master/img/0915_01.jpg?raw=true)

  - 세번째 단자도 회로에 연결하는 경우

    - 전형적인 전압 분압기

    ![](https://github.com/bongwon-suh/TIL/blob/master/img/0915_02.jpg?raw=true)

    

### 가변저항 모양

- trimmer 타입
  - 스크류 드라이버를 이용하여 저항을 조절
- rotary 타입
  - 손잡이로 저항을 조정



### 가변저항

- ADC로 연결되는 부품
  - 센서의 입력 원리와 같다
  - 센서는 환경에 따라 변하고, 가변저항은 사람이 조정하는 점이 차이

![](https://github.com/bongwon-suh/TIL/blob/master/img/0915_03.jpg?raw=true)



### 아날로그 값 읽기

- 아날로그 입력 핀 사용
  - A0 ~ A5 핀
  - 0 ~ 5V 사이의 입력 전압의 변화 감지
  - `analogRead(핀번호)`
    - 0 ~ 1023 범위의 아날로그 값으로 리턴
    - 해당 입력값을 Voaltage로 변환

```c++
int vResister = A0;

void setup(){
    Serial.begin(9600);
    pinMode(vResister, INPUT);
}

void loop(){
    Serial.println(analogRead(vResister));
    delay(1000);
}
```



### 가변 저항으로 LED 빛 조절하기

![](https://github.com/bongwon-suh/TIL/blob/master/img/0915_04.jpg?raw=true)

```c++
int LED = 3;
void setup() {
    pinMode(LED, OUTPUT);
}
void loop() {
    int readVal = analogRead(A0);
    int brightVal = readVa / 4;
    analogWrite(LED, brightVal);
    delay(10);
}
```



### map(value, fromLow, fromHigh, toLow, toHigh)

- 숫자를 한 범위에서 다른 곳으로 변환
- 매개변수
  - value : 변환할 수
  - fromLow : 현재 범위 값의 하한
  - fromHigh : 현재 범위 값으 상한
  - toLow : 목표 범위 값의 하한
  - toHigh : 목표 범위 값의 상한
- 반환값 : 새로운 범위의 값

```c++
const int ledPin = 3;
const int potentiometerPin = A0;
int potentiometerValue;
int brightness;

void setup() {
    Serial.begin(9600);
}
void loop() {
    potentiometerValue = analogRead(potentiometerPin);
    Serial.print("potentiometer Value : ");
    Serial.println(potentiometerValue);
    
    brightness = map(potentiometerValue, 0, 1023, 0, 255);
    Serial.print("potentiometer Value : ");
    Serial.println(potentiometerValue);
    
	analogWrite(ledPin, brightness);
}
```

