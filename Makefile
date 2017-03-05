all:
	g++ `pkg-config --cflags opencv` -g -o binary diff.cpp  `pkg-config --libs opencv`

clear:
	rm -rf binary
