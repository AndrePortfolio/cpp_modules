/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/08/19 16:23:44 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

/*----------------------------------------------------------------------------*/
/*------------------------- Constructors & Destructor -----------------------*/
/*----------------------------------------------------------------------------*/

Brain::Brain()
{
	std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	*this = copy;

	std::cout << "Brain Copy Constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

/*----------------------------------------------------------------------------*/
/*--------------------------------- Operator ---------------------------------*/
/*----------------------------------------------------------------------------*/

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	std::cout << "Brain Copy Assignment Operator called" << std::endl;
	return (*this);
}

/*----------------------------------------------------------------------------*/
/*------------------------------ Member Functions ----------------------------*/
/*----------------------------------------------------------------------------*/
