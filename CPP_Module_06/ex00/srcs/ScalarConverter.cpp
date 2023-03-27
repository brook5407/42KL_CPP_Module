/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:53:53 by brook             #+#    #+#             */
/*   Updated: 2023/03/22 22:53:53 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() /*: _cVal(0), _iVal(0), _fVal(0), _dVal(0)*/ {
}

ScalarConverter::ScalarConverter(const ScalarConverter &rhs) {
	(*this) = rhs;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
	this->_cVal = rhs._cVal;
	this->_iVal = rhs._iVal;
	this->_fVal = rhs._fVal;
	this->_dVal = rhs._dVal;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

// function to check whether the sting is a double or not
bool isDouble(const std::string &literal) {
	std::string::const_iterator i = literal.begin();
	while (i != literal.end() && std::isdigit(*i))
		++i;
	if (i == literal.end())
		return false;
	if (*i == '.') {
		++i;
		while (i != literal.end() && std::isdigit(*i))
			++i;
	}
	if (i == literal.end())
		return true;
	else
		return false;
}

// function to check whether the sting is a float or not
bool isFloat(const std::string &literal) {
	std::string::const_iterator i = literal.begin();
	while (i != literal.end() && std::isdigit(*i))
		++i;
	if (i == literal.end())
		return false;
	if (*i == '.') {
		++i;
		while (i != literal.end() && std::isdigit(*i))
			++i;
	}
	if (i == literal.end() || (*i == 'f' && i == literal.end() - 1))
		return true;
	else
		return false;
}

bool isInt(const std::string &literal) {
	std::string::const_iterator i = literal.begin();
	if (*i == '-' || *i == '+')
		++i;
	while (i != literal.end() && std::isdigit(*i))
		++i;
	if (i == literal.end())
		return true;
	else
		return false;
}

bool isChar(const std::string &literal) {
	if (literal.length() == 1 && !isdigit(literal[0]))
		return true;
	else
		return false;
}

void ScalarConverter::convert(const std::string &literal) {
	try {
		if (isFloat(literal)) {
			this->_fVal = std::stof(literal);
			this->_cVal = static_cast<char>(_fVal);
			this->_iVal = static_cast<long>(_fVal);
			this->_dVal = static_cast<double>(_fVal);
		} else if (isDouble(literal)) {
			this->_dVal = std::stod(literal);
			this->_cVal = static_cast<char>(_fVal);
			this->_iVal = static_cast<long>(_fVal);
			this->_fVal = static_cast<double>(_fVal);
		} else if (isInt(literal)) {
			this->_iVal = std::stoi(literal);
			this->_cVal = static_cast<char>(_iVal);
			this->_fVal = static_cast<float>(_iVal);
			this->_dVal = static_cast<double>(_iVal);
		} else if (isChar(literal)) {
			this->_cVal = literal[0];
			this->_iVal = static_cast<long>(_cVal);
			this->_fVal = static_cast<float>(_cVal);
			this->_dVal = static_cast<double>(_cVal);
		} else {
			throw std::exception();
		}
		this->convertChar(literal);
		this->convertInt(literal);
		this->convertFloat(literal);
		this->convertDouble(literal);
	}
	catch (...) {
		this->convertOther(literal);
	}
}

void ScalarConverter::convertChar(const std::string &literal) {
	(void) literal;
	std::cout << BOLDBLUE"char: ";
	if (isprint(this->_cVal))
		std::cout << "'" << this->_cVal << "'" << std::endl;
	else if (isascii(this->_cVal))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << RESET;
}

void ScalarConverter::convertInt(const std::string &literal) {
	(void) literal;
	std::cout << BOLDBLUE"int: ";
	if (this->_iVal >= INT_MIN && this->_iVal <= INT_MAX)
		std::cout << this->_iVal << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << RESET;
}

void ScalarConverter::convertFloat(const std::string &literal) {
	(void) literal;
	std::cout << BOLDBLUE"float: ";
	if (abs(this->_fVal) >= -FLT_MIN && this->_fVal <= FLT_MAX)
	{
		if (this->_iVal == this->_fVal)
			std::cout << this->_fVal << ".0f" << std::endl;
		else
			std::cout << this->_fVal << "f" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
	std::cout << RESET;
}

void ScalarConverter::convertDouble(const std::string &literal) {
	(void) literal;
	std::cout << BOLDBLUE"double: ";
	if (abs(this->_dVal) >= -DBL_MIN && this->_dVal <= DBL_MAX)
	{
		if (this->_iVal == this->_dVal)
			std::cout << this->_dVal << ".0" << std::endl;
		else
			std::cout << this->_dVal << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
	std::cout << RESET;
}

void ScalarConverter::convertOther(const std::string &literal) {
	if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << "inff" << std::endl;
		std::cout << "double: " << "inf" << std::endl;
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << "-inff" << std::endl;
		std::cout << "double: " << "-inf" << std::endl;
	}
	else if (literal == "nan" || literal == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}