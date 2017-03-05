all:
	g++ `pkg-config --cflags opencv` -g -o binary trackbar.cpp  `pkg-config --libs opencv`

clear:
	rm -rf binary
