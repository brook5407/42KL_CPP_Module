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
	data->c = '#';
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

	std::cout << "---------------------------" << std::endl;
	char *p = reinterpret_cast<char*>(data);
	int *n = reinterpret_cast<int*>(data);
	std::cout << "n: " << *n << std::endl;
	p += sizeof(long long); // sizeof(long long) is 8
	std::string *str = reinterpret_cast<std::string*>(p);
	std::cout << "str: " << *str << std::endl;
	p+= sizeof(std::string); // sizeof(std::string) is 24
	char *c = reinterpret_cast<char*>(p);
	std::cout << "c: " << *c << std::endl;
	p += sizeof(char); // sizeof(char) is 1
	bool *b = reinterpret_cast<bool*>(p);
	std::cout << "b: " << *b << std::endl;

	delete data;
	return 0;
}