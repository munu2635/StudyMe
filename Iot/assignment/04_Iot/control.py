import paho.mqtt.client as mqtt
import time

def on_connect(client, userdata, flags, rc):
    print("connected with result code " + str(rc))
    client.subscribe("environment/distance")
    client.subscribe("environment/temperature")
    client.subscribe("environment/humidity")

def on_message(client, userdata, msg):
    global tem
    global hum
    global distance
    if msg.topic == "environment/distance" :
	   distance = msg.payload
    if msg.topic == "environment/temperature" :
	   tem = msg.payload
    if msg.topic == "environment/humidity" :
	   hum = msg.payload

def on_publish(client, userdata, mid):
	print("message published")

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.on_publish = on_publish
client.connect("127.0.0.1", 1883, 60)
client.loop_start()

try:
    while True :
        if tem > 20 and hum > 40 :
            print("Publish data : LED - All")
            client.publish("control/led",All)
        elif distance >= 50 :
            print("Publish data : LED - Green")
            client.publish("control/led", Green)
        elif distance > 20 :
            print("Publush data : LED - yellow")
            client.publish("control/led", Yellow)
        else :
            print("Publish data : LED - Red")
            client.publish("control/led", Red)
        time.sleep(2)

except KeyboardInterrupt:
    client.loop_stop()
    client.unsubscribe(["environment/distance", "environment/temperature", "environment/humidity"])
    client.disconnect()

