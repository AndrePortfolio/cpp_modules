/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by           #+#    #+#             */
/*   Updated: 2024/08/19 11:29:20 by       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <iostream>		// For input and output stream
# include <string>			// For string class and functions
# include <cstring>			// For C-style string functions
# include <cmath>			// For common mathematical functions
# include <sstream>			// For string stream classes
# include <fstream>			// For file stream classes
# include <iomanip>			// For input/output manipulation
# include <exception>		// For standard exception classes
# include <stdexcept>		// For standard exception classes (runtime_error, etc.)
# include <limits>			// For numeric limits
# include <typeinfo>		// For type information

# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

# define RED	"\x1b[31;1m"
# define GREEN	"\x1b[32;1m"
# define BLUE	"\x1b[34;1m"
# define CYAN	"\x1b[36;1m"
# define YELLOW	"\033[33;1m"
# define RESET	"\x1b[0m"

void errorMessage(std::string message);

#endif
