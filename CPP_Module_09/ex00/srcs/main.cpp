/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 23:29:31 by brook             #+#    #+#             */
/*   Updated: 2023/03/31 23:29:31 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void importInputFile(const std::string &filename, std::multimap<std::string, std::string> &input) {
	std::ifstream file(filename);
	if (!file.is_open())
		throw std::invalid_argument("Error: cannot open file => " + filename);
	std::string line;
	std::getline(file, line); //skip the first line
	while(std::getline(file, line)) {
		std::istringstream iss(line);
		std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
										 std::istream_iterator<std::string>());
		input.insert(std::make_pair(results[0], results[2]));
	}
}

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << BOLDRED"Usage: ./btc <input_file>"RESET << std::endl;
		return 1;
	}
	try {
		std::multimap<std::string, std::string> input;
		importInputFile(argv[1], input);
		BitcoinExchange exchange;
		exchange.importExchangeRate("./data.csv");
		exchange.convert(input);
//		exchange.print();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}