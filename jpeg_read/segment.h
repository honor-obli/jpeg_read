#pragma once

#include "byte_array.h"

namespace segment{
class segment {
public:
	virtual void print_segment()=0;
	virtual void copied_from_byte_array(byte_array bytes) = 0;
};

class APP0 : segment {
	short length;
	char JFIF[5];
	short version;
	char intensity;
	short width_intensity;
	short height_intensity;
	short width_thumbnail;
	short height_thumbnail;
	short *image_thumbnail;
public:
	void print_segment();
	void copied_from_byte_array(byte_array bytes);
};

class DQT : segment {
	void print_segment() {}
	void copied_from_byte_array() {}
};

class SOF0 : segment {
	void print_segment() {}
	void copied_from_byte_array() {}
};

}