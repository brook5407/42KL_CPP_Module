//
// Created by Chin Chun Yong on 23/03/2023.
//

#include "ScalarConverter.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <literal>" << std::endl;
		return 1;
	}
	ScalarConverter converter;
	converter.convert(argv[1]);
	return 0;
}