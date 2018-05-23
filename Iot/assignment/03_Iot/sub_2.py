import paho.mqtt.client as mqtt

per = 0;
thi = 0;
def on_connect(client, userdata, flags, rc):
    print("connected with result code " + str(rc))
    client.subscribe("sys/person")
    client.subscribe("sys/thi")

def on_message(client, userdata, msg):
    print("Topic: " + msg.topic + " Message: " + str(msg.payload))
    global per 
    global thi
    
    if msg.topic == "sys/person" :
	per = str(msg.payload)
    elif msg.topic == "sys/thi" :
	thi = str(msg.payload)
	
    if per == '1' and thi == '1' or thi == '2' :
        print("start air conditioning")
    else :
        print("stop air conditioning")

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

client.connect("127.0.0.1", 1883, 60)
try:
     client.loop_forever()
except KeyboardInterrupt:
    print("Finished!")
    client.unsubscribe(["sys/person", "sys/thi"])
    client.disconnect()
