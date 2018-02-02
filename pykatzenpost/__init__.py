import os
os.environ['GODEBUG'] = 'cgocheck=0'

import minclient

from .api import Key, Client
