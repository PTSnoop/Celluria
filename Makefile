vpath %.cc src
vpath %.hh src
vpath %.o build

SOURCE=cell/transport/walker

textures: svg
	python maketextures.py

source.mk:src
	rm -rf depends
	mkdir depends
	(cd src;find -type f -name '*.cc'|awk '{print "build: build/" substr($$0,3,length($$0)-4) "o" "\ndepends.d: depends/"substr($$0,3,length($$0)-4) "d"}') > $@

depends.d:source.mk
	find depends/ -type f -name '*.d'|awk '{print "include " $$0}' > $@

depends/%.d:src/%.cc
	mkdir -p `dirname $@`
	g++ -g -M $< -I src> $@

main: build/gui/main.o build/gui/driver/irrlichtscreen.o build/gui/driver/irrlichtreceiver.o build/gui/driver/texturepack.o build/gui/driver/texturecard.o build/net/tdsocket/Socket.o
	g++ -g -fopenmp -lIrrlicht -o main $^ 

net: build/gui/main.o build/gui/driver/irrlichtscreen.o build/gui/driver/irrlichtreceiver.o build/gui/driver/texturepack.o build/gui/driver/texturecard.o build/net/tdsocket/Socket.o

run: main
	./main

build: build/cell/transport/walker.o
	g++ -o test $< 

build/%.o:src/%.cc
	mkdir -p `dirname $@`
	g++ -fopenmp -g -c -o $@ $< -I src

include source.mk
include depends.d

