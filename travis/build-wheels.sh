#!/bin/bash
set -e -x

GOLANG="https://storage.googleapis.com/golang/go1.7.5.linux-amd64.tar.gz"

wget "${GOLANG}" -q --no-check-certificate -O /tmp/golang.tar.gz
tar -xf /tmp/golang.tar.gz
export GOROOT=/tmp/go
export PATH="$GOROOT/bin:$PATH"

# Install a system package required by our library
go get github.com/go-python/gopy
export GODEBUG=cgocheck=0

# Compile wheels
 for PYBIN in /opt/python/*/bin; do
    #"${PYBIN}/pip" install -r /io/dev-requirements.txt
    "${PYBIN}/pip" wheel /io/ -w wheelhouse/
done

# Bundle external shared libraries into the wheels
for whl in wheelhouse/*.whl; do
    auditwheel repair "$whl" -w /io/wheelhouse/
done

# Install packages and test
for PYBIN in /opt/python/*/bin/; do
    "${PYBIN}/pip" install python-manylinux-demo --no-index -f /io/wheelhouse
    (cd "$HOME"; "${PYBIN}/nosetests" pymanylinuxdemo)
done
