
import os
os.environ['GODEBUG'] = 'cgocheck=0'

import client

from .api import Key, Client
