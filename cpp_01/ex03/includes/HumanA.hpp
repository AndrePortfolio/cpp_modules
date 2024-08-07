/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:33:13 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/07/19 11:12:00 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "HumanA.h"

class HumanA
{
	private:
		std::string name;
		class Weapon &weapon;

	public:
		void attack();

	HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon){}
	~HumanA();
};

#endif
