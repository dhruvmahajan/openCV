FILENAME = diff.cpp

all:
	g++ `pkg-config --cflags opencv` -g -o binary $(FILENAME)  `pkg-config --libs opencv`

clear:
	rm -rf binary
