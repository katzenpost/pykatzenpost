import os
os.environ['GODEBUG'] = 'cgocheck=0'

import katzenpost

from .api import Client
