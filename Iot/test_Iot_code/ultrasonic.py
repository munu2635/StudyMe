import RPi.GPIO as GPIO
import time

trig_pin = 13
echo_pin = 19

GPIO.setmode(GPIO.BCM)
GPIO.setup(trig_pin, GPIO.OUT)
GPIO.setup(echo_pin, GPIO.IN)

try:
    while True:
        GPIO.output(trig_pin, False)
        time.sleep(1)

        GPIO.output(trig_pin, True)
        time.sleep(0.00001)
        GPIO.output(trig_pin, False)

        while GPIO.input(echo_pin) == 0:
            pulse_start = time.time()

        while GPIO.input(echo_pin) == 1:
            pulse_end = time.time()

        pulse_duration = pulse_end - pulse_start
        distance = pulse_duration *17000
        distance = round(distance, 2)

        print "Distance : ", distance, "cm"

except KeyboardInterrupt:
    GPIO.cleanup()
