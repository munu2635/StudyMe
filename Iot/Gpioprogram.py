import RPi.GPIO as gpio
import spidev
import time

spi = spidev.SpiDev()
spi.open(0,0)
spi.max_speed_hz = 61000

trig_pin = 13
echo_pin = 19
yled_pin = 20
rled_pin = 16
gled_pin = 21

gpio.setmode(gpio.BCM)
gpio.setup(trig_pin, gpio.OUT)
gpio.setup(echo_pin, gpio.IN)
gpio.setup(yled_pin, gpio.OUT)
gpio.setup(rled_pin, gpio.OUT)
gpio.setup(gled_pin, gpio.OUT)


light_channel = 0

def readChannel(channel):
	adc =  spi.xfer2([1, (8 + channel) << 4, 0])
	adc_out = (( adc[1] & 3 ) << 8 ) + adc[2]
	return adc_out

def convert2volt(data, places):
	volts = (data * 3.3) / float(1023)
	volts = round(volts, places)
	return volts;

try:
	while True:
		light_level = readChannel(light_channel)
		light_volts = convert2volt(light_level, 2)

		gpio.output(trig_pin, False)
		time.sleep(1)

		gpio.output(trig_pin, True)
		time.sleep(0.00001)
		gpio.output(trig_pin, False)

		while gpio.input(echo_pin) == 0:
			pulse_start = time.time()

		while gpio.input(echo_pin) == 1:
			pulse_end = time.time()

		pulse_duration = pulse_end - pulse_start
		distance = pulse_duration * 17000
		distance = round(distance, 2)


		if light_level < 70 :
			gpio.output(gled_pin, True)
			gpio.output(rled_pin, True)
			gpio.output(yled_pin, True)

		elif distance >= 30.0 :
			gpio.output(gled_pin, True)
			gpio.output(rled_pin, False)
			gpio.output(yled_pin, False)

		elif distance > 10.0 :
			gpio.output(gled_pin, False)
			gpio.output(rled_pin, False)
			gpio.output(yled_pin, True)
		else :
			gpio.output(gled_pin, False)
			gpio.output(rled_pin, True)
			gpio.output(yled_pin, False)


		print("--------------------------------------")
		print("Light		: %d (%f V)" %(light_level, light_volts))
		print("Distance 	: %f cm" %distance)

		time.sleep(0.5)

except KeyboardInterrupt:
	print("finished")
	spi.close()
	gpio.cleanup()
