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