/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:14:39 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/07/11 11:14:09 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.h"

void	error_message(std::string str)
{
	std::cerr << YELLOW << str << RESET << std::endl;
	exit(1);
}

int	main(int argc, char *argv[])
{
	Harl		isHarl;

	if (argc != 2)
		error_message("[ Probably complaining about insignificant problems ]");
	isHarl.filter(argv[1]);
}