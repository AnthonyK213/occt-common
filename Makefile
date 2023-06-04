.PHONY: build clean_build test clean_test
.ONESHELL:

build:
	cd build
	cmake ..
	cmake --build .

clean_build:
	cd build
	rm CMakeCache.txt
	cmake ..
	cmake --build .

test:
	cd build
	cmake ..
	cmake --build .
	./tests/OcctCommonTest

clean_test:
	cd build
	rm CMakeCache.txt
	cmake ..
	cmake --build .
	./tests/OcctCommonTest
