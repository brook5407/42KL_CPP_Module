/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:48:40 by brook             #+#    #+#             */
/*   Updated: 2023/02/09 21:48:40 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();
	void	add();
	void	search();
	void	exit();

private:
	int	_volume;
	Contact	_contacts[8];
};



