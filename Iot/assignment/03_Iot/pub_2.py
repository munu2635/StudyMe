import paho.mqtt.client as mqtt
import random
import time


def get1():
    msg = str(random.randrange(15, 36))
    return msg

def get2():
    msg = str(random.randrange(30, 96))
    return msg

def on_connect(client, userdata, flags, rc):
    print("Connected with result code " + str(rc))

def on_publish(client, userdata, mid):
    msg_id = mid
    print("message published")

mqttc = mqtt.Client()
mqttc.on_connect = on_connect
mqttc.on_publish = on_publish

# YOU NEED TO CHANGE THE IP ADDRESS OR HOST NAME
mqttc.connect("127.0.0.1")
#mqttc.connect("localhost")
mqttc.loop_start()

try:
    num = 0
    while True:
	tem = get1()
	hum = get2()
        if num == 0 :
            (result, m_id) = mqttc.publish("home/temperature", tem)
            time.sleep(2)
            num = 1
        else :
            (result, m_id) = mqttc.publish("home/humidity", hum)
            time.sleep(2)
            num = 0
        print("temperature : " + str(tem) +"  humidity : " + str(hum))


except KeyboardInterrupt:
    print("Finished!")
    mqttc.loop_stop()
    mqttc.disconnect()
