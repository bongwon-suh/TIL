import RPi.GPIO as GPIO
import time

class Led:
    def __init__(self, led_pin):
        super().__init__()
        self.led_pin = led_pin
        GPIO.setmode(GPIO.BCM)
        GPIO.setup(led_pin, GPIO.OUT)
    
    def led_on(self):
        GPIO.output(self.led_pin, 1)

    def led_off(self):
        GPIO.output(self.led_pin, 0)
    
    def cleanup(self):
        GPIO.cleanup()
        
