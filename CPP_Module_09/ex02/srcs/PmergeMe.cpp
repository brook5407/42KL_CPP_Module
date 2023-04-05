/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:21:23 by brook             #+#    #+#             */
/*   Updated: 2023/04/03 20:21:23 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

// intialise the 3000number argv into the container
PmergeMe::PmergeMe(int argc, char **argv) {
	int i = 0;
	while (i < argc) {
		_deque.push_back(atoi(argv[i]));
		_list.push_back(atoi(argv[i]));
		i++;
	}
}

PmergeMe::PmergeMe(const PmergeMe &rhs) {
	*this = rhs;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
	if (this != &rhs) {
		_deque = rhs._deque;
		_list = rhs._list;
	}
	return *this;
}

void dequeInsertionSort(std::deque<int> &container, std::deque<int>::iterator left, std::deque<int>::iterator right) {
	(void) container;
	std::deque<int>::iterator it = left;
	std::deque<int>::iterator ite = right + 1;
	while (it != ite) {
		std::deque<int>::iterator it2 = it;
		while (it2 != left && *it2 < *(it2 - 1)) {
			std::swap(*it2, *(it2 - 1));
			it2--;
		}
		it++;
	}
}

void dequeMergeSort(std::deque<int> &container, std::deque<int>::iterator left, std::deque<int>::iterator mid, std::deque<int>::iterator right) {
	(void) container;
	std::deque<int> temp;
	std::deque<int>::iterator it = left;
	std::deque<int>::iterator ite = mid + 1;
	while (it != mid + 1 && ite != right + 1) {
		if (*it < *ite) {
			temp.push_back(*it);
			it++;
		} else {
			temp.push_back(*ite);
			ite++;
		}
	}
	while (it != mid + 1) {
		temp.push_back(*it);
		it++;
	}
	while (ite != right + 1) {
		temp.push_back(*ite);
		ite++;
	}
	std::deque<int>::iterator it2 = temp.begin();
	std::deque<int>::iterator ite2 = temp.end();
	while (it2 != ite2) {
		*left = *it2;
		left++;
		it2++;
	}
}

void dequeMergeInsertSort(std::deque<int> &container, std::deque<int>::iterator left, std::deque<int>::iterator right) {
	if (right - left < 12) {
		dequeInsertionSort(container, left, right); // insertion sort for small range of elements (32)
	} else {
		std::deque<int>::iterator mid = left + (right - left) / 2;
		dequeMergeInsertSort(container, left, mid);
		dequeMergeInsertSort(container, mid + 1, right);
		dequeMergeSort(container, left, mid, right);
	}
}

void PmergeMe::dequeSort() {
	dequeMergeInsertSort(_deque, _deque.begin(), --_deque.end());
}

void listInsertionSort(std::list<int> &container, std::list<int>::iterator left, std::list<int>::iterator right) {
	(void) container;
	std::list<int>::iterator it = left;
	std::list<int>::iterator ite = right;
	while (it != ite) {
		std::list<int>::iterator it2 = it;
		while (it2 != left && *it2 < *(it2--)) {
			std::swap(*it2, *(it2--));
			it2--;
		}
		it++;
	}
}

void listMergeSort(std::list<int> &container, std::list<int>::iterator left, std::list<int>::iterator mid, std::list<int>::iterator right) {
	(void) container;
	std::list<int> temp;
	std::list<int>::iterator it = left;
	std::list<int>::iterator ite = mid;
	while (it != mid && ite != right) {
		if (*it < *ite) {
			temp.push_back(*it);
			it++;
		} else {
			temp.push_back(*ite);
			ite++;
		}
	}
	while (it != mid) {
		temp.push_back(*it);
		it++;
	}
	while (ite != right) {
		temp.push_back(*ite);
		ite++;
	}
	std::list<int>::iterator it2 = temp.begin();
	std::list<int>::iterator ite2 = temp.end();
	while (it2 != ite2) {
		*left = *it2;
		left++;
		it2++;
	}
}

void listMergeInsertSort(std::list<int> &container, std::list<int>::iterator left, std::list<int>::iterator right) {
	int size = std::distance(left, right);
if (size < 32) {
		listInsertionSort(container, left, right);
	} else {
		std::list<int>::iterator mid = left;
		std::advance(mid, size / 2);
		listMergeInsertSort(container, left, mid);
		listMergeInsertSort(container, mid, right);
		listMergeSort(container, left, mid, right);
	}
}

void PmergeMe::listSort() {
	listMergeInsertSort(_list, _list.begin(), _list.end());
}

void PmergeMe::printDeque() {
	std::deque<int>::iterator it = _deque.begin();
	std::deque<int>::iterator ite = _deque.end();
	while (it != ite) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void PmergeMe::printList() {
	std::list<int>::iterator it = _list.begin();
	std::list<int>::iterator ite = _list.end();
	while (it != ite) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}