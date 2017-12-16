#!/bin/bash
set -e -x
yum install -y wget
GOLANG="https://storage.googleapis.com/golang/go1.7.5.linux-amd64.tar.gz"
GOPY="github.com/go-python/gopy"
BINDINGS="github.com/katzenpost/bindings"

wget "${GOLANG}" -q --no-check-certificate -O golang.tar.gz
tar -xf golang.tar.gz
export GOROOT=`pwd`/go
export GOPATH=`pwd`/go
export PATH="$GOROOT/bin:$PATH"
export GODEBUG=cgocheck=0

go get "${GOPY}"
go get "${BINDINGS}"

# Compile wheels
for PYBIN in /opt/python/*/bin; do
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
