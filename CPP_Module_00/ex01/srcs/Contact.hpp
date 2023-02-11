/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:48:29 by brook             #+#    #+#             */
/*   Updated: 2023/02/09 21:48:29 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>

class Contact {
public:
	Contact();
	~Contact();
	void	set_contact(std::string field[5]);
	void	print_list();
	void	print_contact();

private:
	std::string	_firstname;
	std::string	_lastname;
	std::string	_nickname;
	std::string _phonenumber;
	std::string _darkestsecret;
};

