/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:39:26 by brook             #+#    #+#             */
/*   Updated: 2023/03/30 21:39:26 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <fstream>

#define RESET   "\033[0m"
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

class BitcoinExchange {
private:
	std::map<std::string, float> _record;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &rhs);
	virtual ~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &rhs);

	void importExchangeRate(const std::string &filename);
	void convert(const std::multimap<std::string, std::string> &currency);
	void print();
};

#endif
