
#include "jpeg_parse.h"
#include "segment.h"

void jpeg_parse::parse(byte_array bytes) {
	int size = bytes.get_size();
	for (int i = 0; i < size-1; i++) {
		if (bytes[i] == 0xFF) {
			switch (bytes[i+1]) {
			case SOI:
				break;
			case APP0: {
				printf("APP0 : %dbytes length:%d\n", i + 1, bytes.byte_to_2byte(i+2));
				segment::APP0 app0;
				app0.copied_from_byte_array(bytes, i);
				app0.print_segment();
			}
				break;
			case DQT: {
				printf("DQT  : %dbytes length:%d\n", i + 1, bytes.byte_to_2byte(i + 2));
				segment::DQT dqt;
				dqt.copied_from_byte_array(bytes, i);
				dqt.print_segment();
			}
				break;
			case SOF0:
				printf("SOF0 : %dbytes length:%d\n", i+1, bytes.byte_to_2byte(i + 2));
				break;
			case DHT:
				printf("DHT  : %dbytes length:%d\n", i+1, bytes.byte_to_2byte(i + 2));
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