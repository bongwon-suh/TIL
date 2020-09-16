# 조도센서

### 빛 저항

-  빛에 노출되면 저항이 줄어드는 저항 - 광전자 효과

  ![](https://github.com/bongwon-suh/TIL/blob/master/img/0916/01.JPG?raw=true)

### 회로 구성

- 빛 저항 연결

  - 한쪽은 vcc에 연결
  - 다른 한쪽은 A0에 연결
  - 10k옴 저항 연결

  ![](https://github.com/bongwon-suh/TIL/blob/master/img/0916/02.JPG?raw=true)

### constrain(x,a,b)

- 숫자를 어느 범위로 제한
  - x : 제한할 수
  - a : 범위의 하한
  - b : 범위의 상한
- 반환
  - x : x가 a와 b사이에 있을 시
  - a : x가 a보다 작을시
  - b : x가 b보다 클시
- `sensVal =constrain(sensVal, 10, 150);` 센서 값을 10에서 150사이로 제한



```c++
#include <LiquidCrystal_I2C.h>
#include <AnalogSensor.h>
#include <Led.h>
#include <PWMLed.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
AnalogSensor illu(A0, 0, 1023);
// Led led(3);
PWMLed led(3);
void setup() {
    lcd.init();
	lcd.backlight();
    Serial.begin(9600);
    led.off();
}

void printIllu(int value){
    char buf[17];
    sprintf(buf, "illu : %3d", value);
    lcd.setCursor(0,0);
    lcd.print(buf);
}

void loop(){
   
    int readVal = illu.read();
    readVal =constrain(readVal, 0, 200);
    int brigthness = map(readVal, 0, 200, 255, 0);
    printIllu(readVal);
    led.set(brigthness);

    delay(200);
}
```



