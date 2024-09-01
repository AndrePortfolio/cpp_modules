/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/08/24 13:22:14 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include "libft.h"

template<typename T>
void	iter(T*	array, size_t length, void	(*func)(T&, size_t index))
{
	for (size_t i = 0; i < length; i++)
	{
		func(array[i], i);
	}
}

#endif
