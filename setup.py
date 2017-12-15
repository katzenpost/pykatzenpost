from setuptools import setup, Extension

def build_native(spec):
    # build the golang
    build = spec.add_external_build(
	cmd = ['go', 'build', '-buildmode=c-shared',
	       '-o', '../pykatz/_minclient.so', 'minclient.go'],
        path='./minclient'
    )

    #spec.add_cffi_module(
    #    module_path='pykatzen._native',
    #    dylib=lambda: build.find_dylib('_minclient')  #, in_path='target/release'),
    #    #header_filename=lambda: build.find_header('minclient.h', in_path='target')
    #)

setup(
    name='pykatzenpost',
    description='Python bindings for the katzenpost client',
    url='https://github.com/katzenpost/bindings/',
    version='0.0.1',
    author='Kali Kaneko',
    author_email='kali@leap.se',

    classifiers=[
        'License :: OSI Approved :: MIT License',
        'Programming Language :: Python :: 2',
        'Programming Language :: Python :: 2.7',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.5',
        'Programming Language :: Python :: 3.6',
        'Programming Language :: Python :: Implementation :: CPython',
        'Programming Language :: Python :: Implementation :: PyPy',
    ],

    #setuptools-golang doesn't seem to work...
    #build_golang={'root': 'github.com/katzenpost/bindings'},  # this repo?
    #ext_modules=[Extension('minclient', ['minclient/minclient.go'])],
    #setup_requires=['setuptools-golang'],

    packages=['pykatz'],
    zip_safe=False,
    platforms='any',
    setup_requires=['milksnake'],
    install_requires=['milksnake'],
    milksnake_tasks=[
        build_native
    ]
)
