/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:45:57 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/04/29 14:56:31 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

Zombie*  zombieHorde( int N, std::string name ) {
    Zombie *hordeZ = new Zombie[N];

    for (int i = 0; i < N; i++) {
        hordeZ[i].setName(name);
    }
    return (hordeZ);
}