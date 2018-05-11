import paho.mqtt.client as mqtt
import time


# use onse data

def on_connect(client, userdata, flags, rc):
    print("Connected with result code " + str(rc))

def on_publish(client, userdata, mid):

mqttc = mqtt.Client()
mqttc.on_connect = on_connect
mqttc.on_publish = on_publish

mqttc.connect("127.0.0.1")
mqttc.loop_start()

try:
    num = 0
    while True:
	tem = get1()
	hum = get2()
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
    mqttc.loop_stop()
    mqttc.disconnect()
