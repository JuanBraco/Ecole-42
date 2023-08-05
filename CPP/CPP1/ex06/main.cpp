/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:43:23 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/04/30 10:33:24 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

#include "Harl.hpp"

int	main(int argc, char** argv)
{
	Harl Harl;
	std::string	levels[4] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
	};
	
	if (argc != 2 || (argv[1] != levels[0] && argv[1] != levels[1] && argv[1] != levels[2] && argv[1] != levels[3])) {
		std::cout << "Error in the input" << std::endl;
		return (1);
	}
	else {
		Harl.complain(argv[1]);
		return (0);
	}
	return (0);
}