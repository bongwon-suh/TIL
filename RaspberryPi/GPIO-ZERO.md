# GPIO-ZERO

### 설치

- pi@raspberrypi:~$ sudo apt update
- pi@raspberrypi:~$ sudo apt install python3-gpiozero



### 문서

- https://gpiozero.readthedocs.io/en/stable/



### Importing GPIO Zero

- import gpiozero
  button = gpiozero.Button(2)
- from gpiozero import Button
  button = Button(2)



![](https://github.com/bongwon-suh/TIL/blob/master/img/1004/10.JPG?raw=true)

![](https://github.com/bongwon-suh/TIL/blob/master/img/1004/11.JPG?raw=true)



![](https://github.com/bongwon-suh/TIL/blob/master/img/1004/12.JPG?raw=true)



### PWM

- PWMLED 객체
  - value 속성 : 0 ~ 1 사이의 값 지정
  - pulse() : 지속적으로 fade in/out 반복



### Button

- 속성
  - is_pressed : 버튼이 눌러진 경우 True
  - when_pressed : 버튼을 눌렀을 때 호출할 콜백 함수
  - when_released : 버튼을 뗄 때 호출할 콜백 함수
- 메서드
  - wait_for_press() : 버튼이 눌러질 때 까지 대기(동기 메서드)

![](https://github.com/bongwon-suh/TIL/blob/master/img/1004/13.JPG?raw=true)



### 초음파센서

![](https://github.com/bongwon-suh/TIL/blob/master/img/1004/14.JPG?raw=true)



### 서보모터

```python
Servo(pin, *, initial_value=0, min_pulse_width=1/1000, max_pulse_width=2/1000, frame_width=20/1000, pin_factory=None)
```

- min() : 최소 각도로 이동
- mid() : 중간 각도로 이동
- max() : 최대 각도로 이동
- value : 이동 값
  - -1 : 최소 각도
  - 0 : 중간 각도
  - 1 : 최대 각도