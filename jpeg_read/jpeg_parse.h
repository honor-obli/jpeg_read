#pragma once
#include "byte_array.h"

enum marker {
	SOI = 0xD8,
	APP0 = 0xE0,
	DQT = 0xDB,
	SOF0 = 0xC0,
	DHT = 0xC4,
	SOS = 0xDA,
	EOI = 0xD9,
};

class jpeg_parse {
public:
	void parse(byte_array bytes);
	//short byte_to_2byte(unsigned char upper, unsigned char lower);
};