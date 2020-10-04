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



### PWM LED

![](https://github.com/bongwon-suh/TIL/blob/master/img/1004/05.JPG?raw=true)

- 절차
  - PWM 인스턴스 생성 p = GPIO.PWM(channel, frequency)
  - 시작 듀티비 설정 p.start(dc)
  - 사용할 주파수 변경 p.ChangeFrequency(freq)
  - 듀티비 설정 p.ChangeDutyCycle(dc)
  - PWM 인스턴스 정지 p.stop()

```python
import RPi.GPIO as GPIO
import time

class PwmEx:
    def __init__(self):
        self.led_pin = 18

        GPIO.setup(self.led_pin, GPIO.OUT)
        self.p = GPIO.PWM(self.led_pin, 50)
        self.p.start(0)

    def __call__(self):
        try:
            while 1:
                # fade in
                for dc in range(0, 101, 5): # dc의 값은 0에서 100까지 5만큼 증가
                    self.p.ChangeDutyCycle(dc) # dc의 값으로 듀티비 변경
                    time.sleep(0.1) # 0.1초 딜레이
                
                # fade out
                for dc in range(100, -1, -5): # dc의 값은 100에서 0까지 5만큼 감소
                    self.p.ChangeDutyCycle(dc) # dc의 값으로 듀티비 변경
                    time.sleep(0.1) # 0.1초 딜레이
        
        except KeyboardInterrupt: # 키보드 Ctrl+C 눌렀을 때 예외발생
            self.p.stop() # PWM을 종료
```



### PWM 서보모터

![](https://github.com/bongwon-suh/TIL/blob/master/img/1004/06.JPG?raw=true)

![](https://github.com/bongwon-suh/TIL/blob/master/img/1004/07.JPG?raw=true)



```python
import RPi.GPIO as GPIO
import time

class PwmServoEx:
    def __init__(self):
        self.led_pin = 25

        GPIO.setup(self.led_pin, GPIO.OUT)
        self.servo = GPIO.PWM(self.led_pin, 50)
        self.servo.start(0)

    def __call__(self):
        try:
            while 1:
                # 듀티비를 변경하여 서보모터를 원하는 만큼 움직임
                self.servo.ChangeDutyCycle(7.5) # 90도
                time.sleep(1)
                self.servo.ChangeDutyCycle(12.5) # 180도
                time.sleep(1)
                self.servo.ChangeDutyCycle(2.5) # 0도
                time.sleep(1)
        
        except KeyboardInterrupt: # 키보드 Ctrl+C 눌렀을 때 예외발생
            self.servo.stop() # PWM을 종료
```



### 초음파센서

![](https://github.com/bongwon-suh/TIL/blob/master/img/1004/08.JPG?raw=true)

![](https://github.com/bongwon-suh/TIL/blob/master/img/1004/09.JPG?raw=true)

```python
import RPi.GPIO as GPIO
import time

class UltraEx:
    def __init__(self):
        self.TRIG = 23
        self.ECHO = 24

        GPIO.setup(self.TRIG, GPIO.OUT)
        GPIO.setup(self.ECHO, GPIO.IN)
        

    def __call__(self):
        GPIO.output(self.TRIG, 0)
        print("Waiting for sensor to settle")
        time.sleep(2)

        while True:
            GPIO.output(self.TRIG, True) # Triger 핀에 펄스신호를 만들기 위해 1 출력
            time.sleep(0.00001) # 10µs 딜레이
            GPIO.output(self.TRIG, False)

            while GPIO.input(self.ECHO)==0:
                start = time.time() # Echo 핀 상승 시간

            while GPIO.input(self.ECHO)==1:
                stop = time.time() # Echo 핀 하강 시간

            check_time = stop - start
            distance = check_time * 34300 / 2
            print("Distance : %.1f cm" % distance)
            time.sleep(0.4) # 0.4초 간격으로 센서 측정
```

