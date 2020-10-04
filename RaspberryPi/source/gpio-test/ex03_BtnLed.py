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