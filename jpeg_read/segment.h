#pragma once

#include "byte_array.h"

namespace segment{
class segment {
public:
	virtual void print_segment()=0;
	virtual void copied_from_byte_array(byte_array bytes, int begin) = 0;
};

class APP0 : segment {
	enum offset {
		MARKER = 0,
		LENGTH = 2,
		JFIF_ID = 4,
		VERSION = 9,
		INTENSITY = 11,
		WIDTH_INTENSITY = 12,
		HEIGHT_INTENSITY = 14,
		WIDTH_THUMB = 16,
		HEIGHT_THUMB = 17,
		THUMBNAIL = 18
	};
	short length;
	char JFIF[5];
	short version;
	char intensity;
	short width_intensity;
	short height_intensity;
	unsigned char width_thumbnail;
	unsigned char height_thumbnail;
	unsigned char *image_thumbnail;
public:
	void print_segment();
	void copied_from_byte_array(byte_array bytes, int begin);
};

class DQT : segment {
	enum offset{
		MARKER = 0,
		LENGTH = 2,
		ACCURACY = 4,
		QUALITY_FACT = 5
	};
	short length;
	unsigned char accuracy;
	union {
		unsigned char byte;
		unsigned short word;
	}table[64];
public:
	void print_segment();
	void copied_from_byte_array(byte_array bytes, int begin);
};

class SOF0 : segment {
	short length;
	unsigned char accuracy;
	short height;
	short width;
	unsigned char elements_number;
public:
	void print_segment() {}
	void copied_from_byte_array(byte_array bytes, int begin) {}
};

}