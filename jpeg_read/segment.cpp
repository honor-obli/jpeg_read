#include "segment.h"
#include <iostream>
using namespace std;
using namespace segment;

void APP0::print_segment() {
	cout << "APP0 length:" << length << endl;
	cout << "APP0 JFIF:" << JFIF << endl;
	cout << "APP0 version:" << version/0xFF << "." << version%0xFF << endl;
	cout << "APP0 intensity:" << (intensity==1?"Pixel/inch":"Pixel/cm") << endl;
	cout << "APP0 width_intensity:" << width_intensity << endl;
	cout << "APP0 height_intensity:" << height_intensity << endl;
	cout << "APP0 width_thumbnail:" << (int)width_thumbnail << endl;
	cout << "APP0 height_thumbnail:" << (int)height_thumbnail << endl;
}

void APP0::copied_from_byte_array(byte_array bytes, int begin) {
	length = bytes.byte_to_2byte(begin+LENGTH);
	for (int i = 0; i < 5; i++) {
		JFIF[i] = bytes[begin+JFIF_ID+i];
	}
	version = bytes.byte_to_2byte(begin + VERSION);
	intensity = bytes[INTENSITY];
	width_intensity = bytes.byte_to_2byte(begin + WIDTH_INTENSITY);
	height_intensity = bytes.byte_to_2byte(begin + HEIGHT_INTENSITY);
	width_thumbnail = bytes[begin + WIDTH_THUMB];
	height_thumbnail = bytes[begin + HEIGHT_THUMB];
}