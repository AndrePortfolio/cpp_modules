/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/08/19 15:41:24 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

/*----------------------------------------------------------------------------*/
/*------------------------- Contructors & Destructor -------------------------*/
/*----------------------------------------------------------------------------*/

Animal::Animal() : type("Unknown animal type")				// Default Contructor
{
	std::cout << "Animal Default Contructor called" << std::endl;
}

Animal::Animal(const Animal &copy)								// Copy Contructor
{
	this->type = copy.type;

	std::cout << "Animal Copy contructor called" << std::endl;
}

Animal::~Animal(void)												// Destructor
{
	std::cout << "Animal Destructor has been called" << std::endl;
}

/*----------------------------------------------------------------------------*/
/*--------------------------------- Operator ---------------------------------*/
/*----------------------------------------------------------------------------*/

Animal	&Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "Animal Copy Assignment operator  called" << std::endl;
	return (*this);
}

/*----------------------------------------------------------------------------*/
/*----------------------------- Member Functions -----------------------------*/
/*----------------------------------------------------------------------------*/

void	Animal::makeSound() const
{
	std::cout << "Animal made a sound" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->type);
}