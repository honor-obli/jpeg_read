#include <iostream>
#include <fstream>

#include "byte_array.h"
using namespace std;

unsigned int get_size_from_eof_and_begin(ifstream& ifs) {
	unsigned int size;

	//EOFの位置と初期位置の差分は即ちファイルサイズ
	ifs.seekg(0, fstream::end);
	size = (unsigned int)ifs.tellg();
	ifs.seekg(0, fstream::beg);
	size -= (unsigned int)ifs.tellg();
	return size;
}

void byte_array::read_file(const char* file_name) {
	ifstream ifs(file_name, ios::in | ios::binary);
	if (!ifs) {
		cout << "cannot read" << endl;
	}else {
		size = get_size_from_eof_and_begin(ifs);
		data_initialize();
		ifs.read((char*)data, size);
	}
}

void byte_array::print_hex() {
	for (unsigned int i = 0; i < size; i++) {
		printf("%02x", data[i]);
		if (i % 32 == 31) {
			puts("");
		}
	}
	puts("");
}

void byte_array::data_initialize() {
	if (data != nullptr) {
		delete[] data;
	}
	data = new unsigned char[size];
	memset(data, 0, size);
}

unsigned char byte_array::operator[](int index) {
	return data[index];
}

short byte_array::byte_to_2byte(int index) {
	short r = data[index];
	r <<= 8;
	if (index < size) {
		r += data[index + 1];
	}
	return r;
}