
from collections import namedtuple
import threading
import time

import katzenpost



class Client(object):

    def __init__(self, cfg):
        client = katzenpost.New(cfg)


