#include "SHA256.hpp"
#include "SHA384.hpp"
#include "SHA512.hpp"
#include <iostream>
#include <sstream>

int main(int argc, char* argv[]) {
	SHA256 sha256;
	SHA384 sha384;
	SHA512 sha512;

	std::stringstream ss;
	ss << argv[1];

	std::cout << "SHA256:" << sha256.hash(ss.str()) << std::endl;
	std::cout << "SHA384:" << sha384.hash(ss.str()) << std::endl;
	std::cout << "SHA512:" << sha512.hash(ss.str()) << std::endl;

	return 0;
}
