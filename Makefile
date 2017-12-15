build_go:
	GODEBUG=cgocheck=0 gopy bind -output=katzenpost github.com/katzenpost/bindings
build:
	python setup.py build
wheel:
	# TODO -- replicate the docker script for building the manylinux wheel
	setuptools-golang-build-manylinux-wheels
clean:
	rm -rf dist/ build/ katzenpost/minclient.so
