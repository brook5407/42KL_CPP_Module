/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:19:06 by brook             #+#    #+#             */
/*   Updated: 2023/03/26 20:19:06 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Serializer.hpp"

int main(void)
{
	Serializer serializer;
	Data *data = new Data;
	std::cout << data << std::endl;
	data->n = 42;
	data->str = "Kuala Lumpur";
	data->c = '?';
	data->b = true;

	uintptr_t raw = serializer.serialize(data);
	std::cout << "raw: " << raw << std::endl;

	Data *deserialized = serializer.deserialize(raw);
	std::cout << "deserialized: " << deserialized << std::endl;

	std::cout << "n: " << deserialized->n << std::endl;
	std::cout << "str: " << deserialized->str << std::endl;
	std::cout << "c: " << deserialized->c << std::endl;
	std::cout << "b: " << deserialized->b << std::endl;

	std::cout << "---------------------------" << std::endl;
	std::cout << "n: " << data->n << std::endl;
	std::cout << "str: " << data->str << std::endl;
	std::cout << "c: " << data->c << std::endl;
	std::cout << "b: " << data->b << std::endl;

	delete data;
	return 0;
}