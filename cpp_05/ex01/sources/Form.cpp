/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/08/20 16:06:12 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

/*----------------------------------------------------------------------------*/
/*------------------------- Constructors & Destructor -----------------------*/
/*----------------------------------------------------------------------------*/

Form::Form() : name("Default"), isSigned(false), signGrade(1), executeGrade(1)
{
	std::cout << "Default Constructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int executeGrade)
	: name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();

	std::cout << "Constructor called" << std::endl;
}

Form::Form(const Form &copy) : name(copy.name), isSigned(copy.isSigned),
	signGrade(copy.signGrade), executeGrade(copy.executeGrade)
{
	std::cout << "Copy Constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Destructor called" << std::endl;
}

/*----------------------------------------------------------------------------*/
/*--------------------------------- Operator ---------------------------------*/
/*----------------------------------------------------------------------------*/

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		isSigned = other.isSigned;

	std::cout << "Copy Assignment Operator called" << std::endl;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Form &form)
{
	out << "Form: " << form.getName() << ", Signed: "
		<< (form.getSigned() ? "Yes" : "No")
		<< ", Sign Grade: " << form.getGradeToSign()
		<< ", Execute Grade: " << form.getGradeToExecute() << std::endl;

	return (out);
}

/*----------------------------------------------------------------------------*/
/*------------------------------ Member Functions ----------------------------*/
/*----------------------------------------------------------------------------*/

const std::string	&Form::getName() const
{
	return (name);
}

bool	Form::getSigned() const
{
	return (isSigned);
}

int	Form::getGradeToSign() const
{
	return (signGrade);
}

int	Form::getGradeToExecute() const
{
	return (executeGrade);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();

	isSigned = true;
}

/*----------------------------------------------------------------------------*/
/*--------------------------- Exception Definitions --------------------------*/
/*----------------------------------------------------------------------------*/

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too High!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too Low!");
}
