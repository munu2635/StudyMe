import paho.mqtt.client as mqtt
import time

def on_connect(client, userdata, flags, rc):
    print("connected with result code " + str(rc))
    client.subscribe("home/person")
    client.subscribe("home/temperature")
    client.subscribe("home/humidity")

tem = 0
hum = 0
per = 0

def on_message(client, userdata, msg):
    #print("Topic: " + msg.topic + " Message: " + str(msg.payload)) 
    global tem
    global hum
    global per

    if msg.topic == "home/person" :
	   per = msg.payload
    if msg.topic == "home/temperature" :
	   tem = msg.payload
    if msg.topic == "home/humidity" :
	   hum = msg.payload


def on_publish(client, userdata, mid):
    mig_id = mid
    print("message published")

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

# YOU NEED TO CHANGE THE IP ADDRESS OR HOST NAME
client.connect("127.0.0.1", 1883, 60)
try:
    client.loop_start()
except KeyboardInterrupt:
    client.loop_stop()
    client.unsubscribe(["home/person","home/temperature", "home/humidity"])
    client.disconnect()
    
    
def on_publish(client, userdata, mid):
    msg_id = mid
    print("message published ")

mqttc = mqtt.Client()
mqttc.on_connect = on_connect
mqttc.on_publish = on_publish

mqttc.connect("127.0.0.1")
mqttc.loop_start()

try:
    num = 0
    while True :
        if num == 0 :
            (result, m_id) = mqttc.publish("sys/person", per)
            print(str(per) + " - person data")
	    time.sleep(1)
            num = 1
        else :
            if tem != 0 and hum != 0 :
		a = 1.8*float(tem)
		b = (1-(float(hum)/100))
                thi = a - 0.55*b*(a - 26) + 32
                if thi >= 80 :
                  print(str(thi) + "(VeryHigh)[temperature: " + str(tem) +", humidity: " + str(hum) + "]") 
                  (result, m_id) = mqttc.publish("sys/thi", 1)
                elif thi >= 75 :
                  print(str(thi) + "(High)[temperature: " + str(tem) + ", humidity: " + str(hum) + "]")
                  (result, m_id) = mqttc.publish("sys/thi", 2)
                elif thi >= 68 :
                  print(str(thi) + "(normal)[temperature: " + str(tem) + ", humidity: " + str(hum) + "]")
                  (result, m_id) = mqttc.publish("sys/thi", 3)
                else :
                  print(str(thi) + "(low)[temperature: " + str(tem) + ", humidity: " + str(hum) + "]")
                  (result, m_id) = mqttc.publish("sys/thi", 4)
            time.sleep(1)
            num = 0

except KeyboardInterrupt:
    print("Finished!")
    mqttc.loop_stop()
    mqttc.disconnect()

