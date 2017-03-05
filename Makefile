all:
	g++ `pkg-config --cflags opencv` -g -o binary test.cpp  `pkg-config --libs opencv`

clear:
	rm -rf binary
