import paho.mqtt.client as mqtt


def on_connect(client, userdata, flags, rc):
    print("connected with result code " + str(rc))
    client.subscribe("sys/person")

def on_message(client, userdata, msg):
    print("Topic: " + msg.topic + " Message: " + str(msg.payload))
    if str(msg.payload) == '1':
    	print("Light on")
    else :
	print("Light off")
	
client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

client.connect("127.0.0.1", 1883, 60)

try:
    client.loop_forever()
except KeyboardInterrupt:
    print("Finished!")
    client.unsubscribe(["sys/person"])
    client.disconnect()
