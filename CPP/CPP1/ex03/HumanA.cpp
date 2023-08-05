/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:23:11 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/04/29 17:41:43 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {
    return;
}

HumanA::~HumanA(void) {
    return;
}

void    HumanA::attack(void) {
	std::cout << _name << " attacks with their " << this->_weapon.getType() << std::endl;
}