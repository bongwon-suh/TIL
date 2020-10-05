from gpiozero import Button
from signal import pause

def say_hello():
    print("hello!")
def say_goodbye():
    print("goodbye!")

button = Button(16)

button.when_pressed = say_hello
button.when_released = say_goodbye

pause()