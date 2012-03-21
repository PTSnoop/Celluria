vpath %.cc src
vpath %.hh src
vpath %.o build

textures: svg
	python maketextures.py
depend: %.cc
	g++ -M $< > depends

build: build/cell/transport/walker.o
	g++ -o test $< 

build/%.o:src/%.cc
	mkdir -p `dirname $@`
	g++ -c -o $@ $< -I src

include depends

