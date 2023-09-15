/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:14:24 by vhappenh          #+#    #+#             */
/*   Updated: 2023/09/07 15:06:48 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int sign, int exec) : _name(name), _signed(false), _sign(sign), _exec(exec) {
	std::cout << "Form constructor called!" << std::endl;
	if (sign > 150 || exec > 150)
		throw GradeTooLowException();
	else if (sign < 1 || exec < 1)
		throw GradeTooHighException();	
}

Form::Form(const Form& other) : _name(other._name), _sign(other._sign), _exec(other._exec) {
	std::cout << "Form copy constructor called!" << std::endl;
	*this = other;
}

Form& Form::operator=(const Form& other) {
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &other)
		_signed = other._signed;
	return (*this);
}

Form::~Form() {
	std::cout << "Form destructor called!" << std::endl;
}

std::string	Form::getName() const {
	return(_name);
}

bool	Form::getStatus() const {
	return (_signed);
}

int		Form::getSign() const {
	return (_sign);
}

int		Form::getExec() const {
	return (_exec);
}

void	Form::beSigned(const Bureaucrat& other) {
	if (other.getGrade() <= getSign())
		_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream&	operator<<(std::ostream &out, const Form& other) {
	out << other.getName();
	out << ", Form sign ";
	out << other.getSign();
	out << ", Form execute ";
	out << other.getExec();
	return out;
}