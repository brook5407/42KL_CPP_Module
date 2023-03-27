/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:52:03 by brook             #+#    #+#             */
/*   Updated: 2023/03/22 22:52:03 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#define RESET   "\033[0m"
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#include <iostream>
#include <limits>
#include <cfloat>

class ScalarConverter {
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &rhs);
	ScalarConverter &operator=(const ScalarConverter &rhs);
	~ScalarConverter();
	void	convert(const std::string &literal);

private:
	char	_cVal;
	int 	_iVal;
	float 	_fVal;
	double	_dVal;
	void	convertChar(const std::string &literal);
	void	convertInt(const std::string &literal);
	void	convertFloat(const std::string &literal);
	void	convertDouble(const std::string &literal);
	void 	convertOther(const std::string &literal);
};

#endif
