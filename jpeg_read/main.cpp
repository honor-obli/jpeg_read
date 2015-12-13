#include <iostream>
#include <fstream>
#include <vector>

#include "byte_array.h"
#include "jpeg_parse.h"
#include "segment.h"
using namespace std;







int main() {
	byte_array data;
	data.read_file("test.jpg");

	jpeg_parse parser;
	parser.parse(data);

	segment::APP0 hoge;
	return 0;
}