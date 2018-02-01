from collections import namedtuple
import threading
import time

import minclient

PKI = namedtuple('PKI', ['uri', 'key'])
DEFAULT_PKI = PKI(
    "37.218.242.147:29485",
    "F0463ECC44BE34AC5064AD65153ED47F5F5B5B03A21FC7E94B3CD57C99DECB5A")


class Key(object):

    @classmethod
    def generate(kls):
        katzen = minclient.GenKey()
        return kls(katzen.Private)

    def __init__(self, private):
        katzen = minclient.StringToKey(private)
        self.public = katzen.Public
        self.private = katzen.Private
        self._katzen = katzen


class Client(object):

    pki = DEFAULT_PKI
    post = None

    def __init__(self, fulluserid, privatekey, logfile=None):
        username, provider = fulluserid.split('@')
        self._username = username
        self._provider = provider
        self._logfile = logfile

        self.key = Key(privatekey)
        self._client = None
        self._session = None

        self._receiver = None
        self._listeners = []
        self._quit = False

    def connect(self):
        # blocks.
        # TODO - this should return a deferred for twisted
        if not self._client:
            self._bootstrap()

    def disconnect(self):
        self._session.Shutdown()
        if self._receiver:
	    self._receiver.stop()

    def register(self, uri):
        if self.post:
            self.post(uri, {'user': self._username,
                            'key': self.key.public})

    def send(self, msg, to=None):
        if not self._client:
            raise RuntimeError('Create session first')
        if not to:
            raise RuntimeError('Need a recipient')
        to_user, to_provider = to.split('@')
        sent = False
        while not sent:
            try:
                self._session.SendMessage(to_user, to_provider, msg)
                sent = True
            except RuntimeError as exc:
                print exc
                time.sleep(1)
        return True

    def receive_blocking(self, timeout=0):
        return self._session.GetMessage(timeout)

    def set_receive_handler(self, callback):
        self._listeners.append(callback)
        if not self._receiver:
            self._receiver = StoppableThread(target=self._receiver_worker)
            self._receiver.start()

    def _receiver_worker(self):
        while True:
            if self._receiver and self._receiver.stopped():
                break
            try:
                msg = self.receive_blocking(1)
                for listener in self._listeners:
                    listener(msg)
            except RuntimeError as exc:
                time.sleep(1)

    def _bootstrap(self):
        # TODO cache the pki client
        if self._logfile:
            args = [self._logfile, 'DEBUG', True]
        else:
            args = []
        logConfig = minclient.LogConfig(*args)

        self._client = minclient.NewClient(
            self.pki.uri, self.pki.key, logConfig)
        self._session = self._client.NewSession(
            self._username, self._provider, self.key._katzen)
        self._session.WaitToConnect()

    def __repr__(self):
        return "<Client [%s@%s:%s]>" % (
            self._username, self._provider, self.key.public)



class StoppableThread(threading.Thread):

    def __init__(self, target):
        super(StoppableThread, self).__init__(target=target)
        self._stop_event = threading.Event()

    def stop(self):
        self._stop_event.set()

    def stopped(self):
        return self._stop_event.is_set()


"""
client = katzenpost.Client('user@provider', 'secret')
>>> None
client = katzenpost.Client('user@provider', Key('secret').generate().private))
>>> None
client.connect()
>>> True
client.send('hello there', to='bob')
>>> True
client.receive_blocking()
>>> None
client.set_receive_handler(lambda msg: print msg)
>>> True
"""
