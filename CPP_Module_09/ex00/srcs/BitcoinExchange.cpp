/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:50:36 by brook             #+#    #+#             */
/*   Updated: 2023/04/07 13:08:29 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs) {
	*this = rhs;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	if (this != &rhs) {
		this->_record = rhs._record;
	}
	return *this;
}

//build a function to check the date format and the date must be in the range of 2009-01-01 to 2022-03-31
void isValidDate(std::string date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') //check if the date is in the format of yyyy-mm-dd
		throw std::invalid_argument("Error: bad date format => " + date);
	int year = std::stoi(date.substr(0, 4));
	int month = std::stoi(date.substr(5, 2));
	int day = std::stoi(date.substr(8, 2));

	if (year < 2009 || year > 2022) //check if the year is valid
		throw std::invalid_argument("Error: invalid date => " + date);
	if (month < 1 || month > 12) //check if the month is valid
		throw std::invalid_argument("Error: invalid date => " + date);

	int max_day; //the max day of each month
	if (month == 2) {
		if (year % 4 == 0)
			max_day = 29;
		else
			max_day = 28;
	} else if (month == 4 || month == 6 || month == 9 || month == 11)
		max_day = 30;
	else
		max_day = 31;

	if (day < 1 || day > max_day) //check if the day is valid
		throw std::invalid_argument("Error: invalid date => " + date);
}

//build a function to check the value format and the value must be a positive float
void isValidValue(std::string value) {
	if (value[0] == '-')
		throw std::invalid_argument("Error: not a positive number => " + value);
	if (value.empty() || value[0] == '.' || value[value.length() - 1] == '.'
		|| value.find('.') != value.rfind('.')) //check if the value is empty or negative or has more than one dot
		throw std::invalid_argument("Error: invalid value => " + value);
	for (size_t i = 0; i < value.length(); i++) {
		if (isdigit(value[i]) == 0 && value[i] != '.') //check if the value is a number
			throw std::invalid_argument("Error: invalid value");
		else if (value[i] == '.' && (i == 0 || i == value.length() - 1)) //check if the value is a float
			throw std::invalid_argument("Error: invalid value => " + value);
	if (std::stof(value) > 1000) //check if the value is negative
		throw std::invalid_argument("Error: too large a number => " + value);
	}
}

void BitcoinExchange::importExchangeRate(const std::string &filename) {
	std::ifstream file(filename);
	if (!file.is_open())
		throw std::invalid_argument("Error opening file");
	std::string line;
	std::getline(file, line); //skip the first line
	while (std::getline(file, line)) {
		std::istringstream iss(line);
		size_t pos = line.find(',');
		std::string date = line.substr(0, pos);
		float value = std::stof(line.substr(pos + 1));
		this->_record.insert(std::make_pair(date, value));
	}
}

void BitcoinExchange::convert(const std::multimap<std::string, std::string> &currency) {
	std::multimap<std::string, std::string>::const_iterator it;
	for (it = currency.begin(); it != currency.end(); it++) {
		try {
			isValidDate(it->first);
			isValidValue(it->second);
			std::map<std::string, float>::const_iterator it2;
			it2 = this->_record.lower_bound(it->first);
			if (it2->first != it->first)
				it2--;
			std::cout << BOLDGREEN << it->first << " => " << it->second << " = ";
			std::cout << std::stof(it->second) * it2->second << std::endl << RESET;
		}
		catch (std::invalid_argument &e) {
			std::cout << BOLDRED << e.what() << RESET << std::endl;
		}
	}
}

void BitcoinExchange::print() {
	std::cout << "Date,Value" << std::endl;
	std::map<std::string, float>::iterator it;
	for (it = this->_record.begin(); it != this->_record.end(); it++) {
		std::cout << it->first << "," << it->second << std::endl;
	}
}


