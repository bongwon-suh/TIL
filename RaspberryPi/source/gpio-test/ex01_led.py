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