#pragma once
#include <iostream>

class byte_array {
	unsigned char* data;
	size_t size;

	void data_initialize();
	void read_file(const char* file_name);
public:
	byte_array(const char* file_name);
	~byte_array() { delete[] data; }
	byte_array(const byte_array& d) {
		size = d.size;
		data = new unsigned char[size];
		memcpy(data, d.data, size);
	}

	void print_hex();
	bool is_readed() {
		return data != nullptr;
	}

	void print_size() { printf("%d\n", size); }
	size_t get_size() { return size; }
	unsigned char operator[](int index);

	short byte_to_2byte(int index);
};