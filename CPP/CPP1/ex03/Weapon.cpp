/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:19:42 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/04/30 09:54:04 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
Weapon::Weapon(std::string type) {
	setType(type);
    return;
}

Weapon::~Weapon(void) {
    return;
}

void    Weapon::setType(std::string type) {
	 this->_type = type;
}

const std::string&    Weapon::getType(void) {
	return this->_type;
}