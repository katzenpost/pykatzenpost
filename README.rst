pykatzenpost
============

python bindings to the katzenpost client.

installing
----------
pip can install a wheel with the library::

  pip install pykatzenpost

building
--------
You need gopy installed in your system::

  go get github.com/go-python/gopy

You also will need ``pkg-tools``.

using
-----

Export the GODEBUG variable::

  export GODEBUG=cgocheck=0
