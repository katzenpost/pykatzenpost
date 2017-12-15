build_go:
	GODEBUG=cgocheck=0 gopy bind -output=pykatz github.com/katzenpost/bindings
	mv pykatz/minclient.so pykatz/_minclient.so
gen_go:
	GODEBUG=cgocheck=0 gopy gen -output=pykatz github.com/katzenpost/bindings
build:
	python setup.py build
prepare:
	go get github.com/katzenpost/bindings
wheel:
	# ???
	setuptools-golang-build-manylinux-wheels
clean:
	rm -rf dist/ build/ pykatz/_minclient.so
