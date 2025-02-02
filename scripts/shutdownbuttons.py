#!/usr/bin/env python3


# import libraries ***********************************************************
from gpiozero import Button
from signal import pause
import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BCM)
import os, sys
import time
# end import libraries *******************************************************


# Define GPIO ****************************************************************
power_off_pin = 4 # Shutdown is pulling signal at pin 4 (Phisical 7) 
				# On Hardware version 1: Add pin 5 to script to disable shutdown, i2c conflict

# End Define GPIO ************************************************************


holdTime = int(10) # Hold Button for at least 3 seconds

# Define Commands

def reboot():
	GPIO.cleanup()
	os.system("sudo reboot")
	
def shutdown():
#	GPIO.cleanup()
	os.system("sudo poweroff") #//Use "sudo shutdown now" if this does not work

# the script # Maybe it we need to use it in a while loop
pwroff  = Button(power_off_pin, hold_time=holdTime)
# rst = Button(reset_pin, hold_time=holdTime)
pwroff.when_held = shutdown
# rst.when_held = reboot
pause()

## We need to do this *******************************************************************
# $ chmod +x shutdownbuttons.py
## end We need to do this *******************************************************************

#and make sure its path is added to /etc/rc.local *****************************************
#sudo nano /etc/rc.local
#end and make sure its path is added to /etc/rc.local *****************************************

#and add *************************************************************************
#sudo python home/pi/shutdownbuttons.py
#end and add *************************************************************************

## it should look like this: *******************************************************
#sudo python home/pi/shutdownbuttons.py &
#exit 0
## end it should look like this: *******************************************************
