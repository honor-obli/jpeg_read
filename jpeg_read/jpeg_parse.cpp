
#include "jpeg_parse.h"

void jpeg_parse::parse(byte_array bytes) {
	int size = bytes.get_size();
	for (int i = 0; i < size-1; i++) {
		if (bytes[i] == 0xFF) {
			switch (bytes[i+1]) {
			case SOI:
				break;
			case APP0:
				printf("APP0 : %dbytes length:%d\n", i+1, byte_array::byte_to_2byte(bytes[i + 2], bytes[i + 3]));
				break;
			case DQT:
				printf("DQT  : %dbytes length:%d\n", i+1, byte_array::byte_to_2byte(bytes[i + 2], bytes[i + 3]));
				break;
			case SOF0:
				printf("SOF0 : %dbytes length:%d\n", i+1, byte_array::byte_to_2byte(bytes[i + 2], bytes[i + 3]));
				break;
			case DHT:
				printf("DHT  : %dbytes length:%d\n", i+1, byte_array::byte_to_2byte(bytes[i + 2], bytes[i + 3]));
				break;
			case SOS:
				printf("SOS  : %dbytes\n", i + 1);
				break;
			case EOI:
				printf("EOI  : %dbytes \n", i+1);
				return;
			default:
				break;
			}
		}
	}
}

//short jpeg_parse::byte_to_2byte(unsigned char upper, unsigned char lower) {
//	short r = upper;
//	r <<= 8;
//	r += lower;
//	return r;
//}