/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:29:10 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/04/30 09:42:06 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
	if (argc != 4){
		std::cout << "input error" << std::endl;
		return (1);
	}
	
	std::ifstream ifs(argv[1]);
	if (!ifs.is_open()) {
		std::cout << "File opening error" << std::endl;
		return (1);
	}
	
	std::string output_filename = std::string(argv[1]) + ".replace";
	std::ofstream ofs(output_filename.c_str());
	if (!ofs.is_open()) {
		std::cout << "File creation error" << std::endl;
		ifs.close();
		return (1);
	}

	std::string line;
    std::string string_to_replace = argv[2];
    std::string new_string = argv[3];
	while(std::getline(ifs, line)) {
		size_t pos = 0;
		while ((pos = line.find(string_to_replace, pos)) != std::string::npos) {
            line = line.substr(0, pos) + new_string + line.substr(pos + string_to_replace.length());
            pos += new_string.length();
        }
		ofs << line << std::endl;
	}


	ifs.close();
	ofs.close();

	std::cout << "File modified successfully\n";
	
	return 0;
}