import paho.mqtt.client as mqtt
import RPi.GPIO as gpio
import dht11
import time
import dateTime

gpio.setwarnings(False)
gpio.setmode(gpio.BCM)
gpio.cleanup()
instance =dht11.DHT11(pin = 5)

def on_connect(client, userdata, flags, rc):
    print("Connected with result code " + str(rc))

def on_publish(client, userdata, mid):
    print("message published")

mqttc = mqtt.Client()
mqttc.on_connect = on_connect
mqttc.on_publish = on_publish

mqttc.connect("127.0.0.1")
mqttc.loop_start()

try:
    num = 0
    while True:

	result = instance.read()
	if result.is_valid():
	    tem = result.temperature
	    hum = result.humidity
        if num == 0 :
            mqttc.publish("environment/temperature", tem)
            time.sleep(2)
            num = 1
        else :
            mqttc.publish("enironment/humidity", hum)
            time.sleep(2)
            num = 0
        print("temperature : " + str(tem) +"  humidity : " + str(hum))


except KeyboardInterrupt:
    print("Finished!")
    gpio.cleanup()
    mqttc.loop_stop()
    mqttc.disconnect()
