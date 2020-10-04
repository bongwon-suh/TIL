# GPIO 제어

### GPIO

- General Purpose Input Output
- 범용 입출력 포트



### GPIO 제어 모듈

- RPi.GPIO 모듈이 기본 설치
- 절차
  - 모듈 임포트
  - 핀 번호 지정 방식 설정
    - BCM * : GPIO 핀 번호 사용
    - BOARD : 보드 핀 번호 사용
    - 핀 I/O 모드 설정
    - 핀 제어
    - 마칠때 cleanup() : 모든 GPIO 핀 초기화



### GPIO 핀 배치

![](https://github.com/bongwon-suh/TIL/blob/master/img/1004/01.JPG?raw=true)



### ex01_led.py

```python
import RPi.GPIO as GPIO
import time

led_pin = 18

GPIO.setmode(GPIO.BCM)
GPIO.setup(led_pin, GPIO.OUT)

for i in range(10):
    GPIO.output(led_pin, 1)
    time.sleep(1)
    GPIO.output(led_pin, 0)
    time.sleep(1)

GPIO.cleanup()
```



### 푸시 버튼

![](https://github.com/bongwon-suh/TIL/blob/master/img/1004/02.JPG?raw=true)

### ex02_Btn_Polling.py

```python
import RPi.GPIO as GPIO
import time

button_pin = 16

GPIO.setmode(GPIO.BCM)

GPIO.setup(button_pin, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)

while 1:
    if GPIO.input(button_pin)==GPIO.HIGH:
        print("BUTTON PUSHED")
    time.sleep(0.1)
```

### ex03_BtnLed.py

```python
#!/usr/bin/python
import RPi.GPIO as GPIO
import time

button_pin=16
led_pin = 18

GPIO.setmode(GPIO.BCM)
GPIO.setup(button_pin, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
GPIO.setup(led_pin, GPIO.OUT)

try:
    while 1:
        GPIO.output(led_pin, GPIO.input(button_pin))
        time.sleep(0.1)

except KeyboardInterrupt:
    GPIO.cleanup()
```



### GPIO 핀의 상태 변경 감지

- GPIO.add_event_detect(채널, GPIO.RISING, callback=my_callback)
  - GPIO 핀의 상태가 0 또는 1 로 변경될 때 호출할 함수(my_callback)을 등록



### 푸시 버튼 Event 알림방식

![](https://github.com/bongwon-suh/TIL/blob/master/img/1004/03.JPG?raw=true)

![](https://github.com/bongwon-suh/TIL/blob/master/img/1004/04.JPG?raw=true)

```python
#!/usr/bin/python
import RPi.GPIO as GPIO
import time

button_pin=16
led_pin = 18

GPIO.setmode(GPIO.BCM)
GPIO.setup(button_pin, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
GPIO.setup(led_pin, GPIO.OUT)

# boolean 변수 설정
light_on = False

def button_callback(channel):
    global light_on
    if light_on==False:
        GPIO.output(led_pin, 1) # led on
        print("led on")
    else:
        GPIO.output(led_pin, 0)
        print("led off")
    light_on = not light_on # false<->true

# Event 알림 방식으로 GPIO 핀의 Rising 신호를 감지하면 button_callback 함수를 실행
# 300ms 바운스타임을 설정하여 잘못된 신호를 방지합니다.
GPIO.add_event_detect(button_pin,GPIO.RISING, callback=button_callback, bouncetime=300)


try:
    while 1:
        time.sleep(0.1)

except KeyboardInterrupt:
    GPIO.cleanup()
```

