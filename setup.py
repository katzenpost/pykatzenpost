import commands
import os
import shlex
import sys
from distutils.spawn import spawn

from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext

MODULE = 'katzenpost'
REPO = 'github.com/katzenpost/bindings'

# TODO make this work with develop mode too
# TODO update rep if release (go get -u REPO)

COMPILE_CMD = "gopy bind -output={output} {repo}"

def check_gopy():
    has_gopy = commands.getoutput('which gopy')
    if not has_gopy:
        print('error: could not find gopy in your system. Get it with:')
        print ('--> go get github.com/go-python/gopy')
        sys.exit(1)

class MinclientBuildExt(build_ext):
    def build_extension(self, ext):
        check_gopy()
        os.environ['GODEBUG'] = 'cgocheck=0'
        ext_path = self.get_ext_fullpath(ext.name)
        output = os.path.join(os.path.split(ext_path)[0], 'katzenpost')
        cmd = COMPILE_CMD.format(output=output, repo=REPO)
        spawn(shlex.split(cmd))

setup(
    name='pykatzenpost',
    description='Python bindings for the katzenpost client',
    url='https://' + REPO,
    version='0.0.1',
    author='Kali Kaneko',
    author_email='kali@leap.se',

    classifiers=[
        'License :: OSI Approved :: MIT License',
        'Programming Language :: Python :: 2',
        'Programming Language :: Python :: 2.7',
        'Programming Language :: Python :: Implementation :: CPython',
        'Programming Language :: Python :: Implementation :: PyPy',
    ],

    packages=[MODULE],
    zip_safe=False,
    platforms='any',
    ext_modules=[
        Extension('minclient', sources=[])],
    cmdclass={
        'build_ext': MinclientBuildExt},
)
