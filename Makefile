FILENAME = boundaryBoxes.cpp 

all:
	g++ `pkg-config --cflags opencv` -g -o binary $(FILENAME) -lpthread `pkg-config --libs opencv`

clear:
	rm -rf binary
