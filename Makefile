all:
	g++ `pkg-config --cflags opencv` -g -o binary surveillanceCam.cpp  `pkg-config --libs opencv`

clear:
	rm -rf binary
