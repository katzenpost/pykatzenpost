import katzenpost
import requests
import time
import sys

key1 = katzenpost.Key.generate()
print("[+] generated key 1")
print("  public\t%s"  % key1.public)
print("  private\t%s" % key1.private)

key2 = katzenpost.Key.generate()
print("[+] generated key 2")
print("  public\t%s"  % key2.public)
print("  private\t%s" % key2.private)

client1 = katzenpost.Client('eve@idefix', key1.private, logfile='/tmp/katzen1.log')
print
print client1
client2 = katzenpost.Client('obelix@idefix', key2.private, logfile='/tmp/katzen2.log')
print client2
print

client1.post = requests.post
client2.post = requests.post

register_uri = "http://217.197.90.63:8080/add"
print("[+] register with provider")
client1.register(register_uri)
client2.register(register_uri)

print("[+] connect")
client1.connect()
client2.connect()
print("[+] connected")

print("[+] send message")

now = time.ctime()

client1.send('hi obelix. Time is %s. Greetings, eve@idefix' % now, 'obelix@idefix')
client2.send('hi eve. Time is %s. Greetings, obelix@idefix' % now, 'eve@idefix')
print("[+] message(s) sent")

print("[+] receiving message(s)...")

"""
try:
    msg = client.receive_blocking(1)
    print("[+] got message: %s" % msg)
except Exception as exc:
    print "error:", exc
"""
messages = []
finished = False

def message_printer(msg):
    global messages
    global finished
    messages.append(msg)
    print "callback:", msg
    if len(messages) >= 2:
        client1.disconnect()
        client2.disconnect()
        finished = True

client1.set_receive_handler(message_printer)
client2.set_receive_handler(message_printer)

MAX = 60 * 2
for i in xrange(MAX):
    if finished:
        sys.exit(1)
    else:
        time.sleep(1)
