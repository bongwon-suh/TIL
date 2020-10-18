#!/usr/bin/env python

import time
import rospy
from std_msgs.msg import String
import ledpy

def led_callback(msg):
    led = ledpy.Led(18)
    rospy.loginfo(rospy.get_caller_id() + "COMMAND DATA is %s", msg.data)

    if msg.data == 'a' :
        led.led_on()
    elif msg.data == 's':
        led.led_off()
    
def led_ctrl():
    rospy.init_node('led_ctrl', anonymous=True)
    rospy.Subscriber("ctrl", String, led_callback)
    rospy.loginfo('I am Ready!')
    rospy.spin()

if __name__ == '__main__':
    led_ctrl()