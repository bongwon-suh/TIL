from gpiozero import LED, Button
from signal import pause

led = LED(18)
button = Button(16)

led.source = button.values

pause()