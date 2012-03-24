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
	g++ -M $< -I src> $@

build: build/cell/transport/walker.o
	g++ -o test $< 

build/%.o:src/%.cc
	mkdir -p `dirname $@`
	g++ -c -o $@ $< -I src

include source.mk
include depends.d

