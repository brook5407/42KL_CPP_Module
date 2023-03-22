/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:31:31 by brook             #+#    #+#             */
/*   Updated: 2023/03/20 15:31:31 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
private:
	std::string _name;
	int			_grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &bureaucrat);
	Bureaucrat &operator=(const Bureaucrat &bureaucrat);
	~Bureaucrat();
	std::string getName();
	int			getGrade();
	void	incrementGrade();
	void	decrementGrade();

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw()
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw()
	};
	friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
};

#endif
