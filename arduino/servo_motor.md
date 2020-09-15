# 서보 모터

### 서보 모터

- 미리 정해진 범위 내에서 모터의 축을 세부 조정하도록 제한된 모터
- 취미용 서보
  - 축의 움직임 범위 180도
  - 50Hz 주파수 내에서 주파수를 이용해 동작 -> 20ms의 신호주기
- 제어를 위한 특별한 회로 없음 -> 바로 연결 가능
- 마이크로 서보모터(SG-90)
  - 0~180도 회전
  - 선 구분
    - 주황 : 디지털핀
    - 빨강 : VCC
    - 갈색 : GND



### 서보 모터 제어

- 신호가 HIGH로 설정된 시간 양 -> 서보의 각도

  - 가장 왼쪽에 배치
    - 1ms 동안 HIGH 유지, 남은 시간 LOW 유지
  - 가장 오른쪽에 배치
    - 2ms 동안 HIGH 유지, 남은 시간은 LOW 유지

  ![](https://github.com/bongwon-suh/TIL/blob/master/img/0915_05.jpg?raw=true)



### Servo 클래스 객체

- 서보모터 제어 메서드 제공

- Servo.h 포함

  ```c++
  #include <Servo.h>
  Servo servoMotor;
  ```

- `servoMotor.attach(핀번호);`서보 모터의 데이터 선 연결핀 설정

- `servomotor.write(각도); //0~179` 서보 모터에 전달할 각도



```c++
#include <Servo.h>

Servo servoMotor;

const int servoMotorPin = 9;
int angle;

void setup(){
    servoMotor.attach(servoMotorPin);
    servoMotor.write(0);
    delay(1000);
}


void loop() {
    for(angle=0; angle<=179; angle++){
        servoMotor.write(angle);
        delay(10);
    }
    delay(100);

    for(angle=179; angle>=0; angle--){
        servoMotor.write(angle);
        delay(10);
    }
    delay(100);
}
```



### 가변저항으로 모터 제어하기

![](https://github.com/bongwon-suh/TIL/blob/master/img/0915_06.jpg?raw=true)

```c++
#include <Servo.h>
#include <AnalogSensor.h>

Servo servo;
int servoPin = 9;

AnalogSensor poten(A0, 0, 179);

void setup(){
    servo.attach(servoPin);
    servo.write(0);
    delay(15);
}

void loop(){
    int val = poten.read();
    servo.write(val);
    delay(15);
}
```

