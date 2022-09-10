RSD:
	make gen
	./gen

gen:
	g++ gen.cpp -o gen	

install:
	sudo cp RDL /usr/include
