/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:07:51 by brook             #+#    #+#             */
/*   Updated: 2023/03/27 17:07:51 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
private:
	unsigned int _size;
	T* _array;

public:
	Array() : _size(0), _array(NULL) {};
	Array(unsigned int n) : _size(n), _array(new T[n]) {
		memset(_array, 0, n * sizeof(T));
	};
	Array(Array const & rhs) : _size(rhs._size), _array(new T[rhs._size]) {
		memcpy(_array, rhs._array, _size * sizeof(T));
	};
	~Array() {
		delete[] _array;
	};

	Array & operator=(Array const & rhs) {
		if (this != &rhs) {
			delete[] _array;
			_size = rhs._size;
			_array = new T[rhs._size];
			for (unsigned int i = 0; i < _size; i++) {
				_array[i] = rhs._array[i];
			}
		}
		return *this;
	};

	T & operator[](unsigned int i) {
		if (i >= _size) {
			throw std::exception();
		}
		return *(_array + i);
	};

	int Length() { return _size; }

	void print() {
		for (unsigned int i = 0; i < _size; i++)
			std::cout << *(_array + i) << " ";
		std::cout << std::endl;
	}
	friend Array<T>* combine(Array<T>& a1, Array<T>& a2) {
		Array<T>* a = new Array<T>(a1._size + a2._size);
		for (unsigned int i = 0; i < a1._size; i++) {
			(*a)[i] = *(a1._array + i);
		}
		for (unsigned int i = 0; i < a2._size; i++) {
			(*a)[i + a1._size] = *(a2._array + i);
		}
		return a;
	};
};

#endif
