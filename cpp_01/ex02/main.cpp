/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:17:54 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/09/11 16:18:02 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << std::endl << "Memory address of the string variable: " << &string << std::endl;
	std::cout << "Memory address held by stringPTR:      " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF:      " << &stringREF << std::endl << std::endl;

	std::cout << "The value of the string variable:      " << string << std::endl;
	std::cout << "The value pointed to by stringPTR:     " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF:     " << stringREF << std::endl << std::endl;

	return (0);
}
