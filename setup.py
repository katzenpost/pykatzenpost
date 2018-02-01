# -*- coding: utf-8 -*-

from __future__ import absolute_import
from __future__ import print_function

from os.path import join
from os import listdir
from setuptools import setup

__version__ = '0.0.1'
__author__ = 'katzenpost dev team'
__contact__ = ''
__url__ = 'https://github.com/katzenpost/pykatzenpost'
__license__ = 'AGPL'
__copyright__ = 'Copyright 2018'


description = '''
    Katzenpost client library.
    https://github.com/katzenpost
    https://katzenpost.mixnetworks.org/
'''

setup(
    name='pykatzenpost',
    version=__version__,
    description=description,
    long_description=open('README.rst', 'r').read(),
    keywords=['python', 'mixnet', 'mix'],
    install_requires=open('requirements.txt').readlines(),
    # "pip install -e .[dev]" will install development requirements
    extras_require=dict(
        dev=open('dev-requirements.txt').readlines(),
    ),
    classifiers=[
        'Development Status :: 4 - Beta',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: MIT License',
        'Natural Language :: English',
        'Operating System :: POSIX :: Linux',
        'Operating System :: Unix',
        'Programming Language :: Python',
        'Programming Language :: Python :: 2',
        'Programming Language :: Python :: 2.6',
        'Programming Language :: Python :: 2.7',
        'Topic :: Software Development :: Libraries :: Python Modules',
        'Topic :: Internet',
        'Topic :: Security',
    ],
    author=__author__,
    author_email=__contact__,
    url=__url__,
    license=__license__,
    packages=[
        "pykatzenpost",
    ],

    # I'm a little unclear if I'm doing this "properly", especially
    # the documentation etc. Do we really want "share/txtorcon" for
    # the first member of the tuple? Why does it seem I need to
    # duplicate this in MANIFEST.in?

    data_files=[
        ('share/katzenpost', ['README.rst', 'MANIFEST.in', 'LICENSE']),
    ],
)
