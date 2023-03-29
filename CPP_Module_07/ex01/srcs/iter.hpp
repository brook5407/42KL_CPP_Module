/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:43:46 by brook             #+#    #+#             */
/*   Updated: 2023/03/27 16:43:46 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void iter(T *array, size_t length, void (*f)(T const &)) {
	for (size_t i = 0; i < length; i++) {
		f(array[i]);
	}
}

#endif
