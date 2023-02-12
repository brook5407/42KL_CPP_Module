/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:49:01 by brook             #+#    #+#             */
/*   Updated: 2023/02/12 21:49:01 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char **argv){
	if (argc != 4){
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (EXIT_FAILURE);
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream	ifs(filename);
	if (ifs.fail()){
		std::cerr << "Error: Unable to open file " << filename << std::endl;
		return (EXIT_FAILURE);
	}

	std::ofstream	ofs(filename + ".replace");
	if (ofs.fail()){
		std::cerr << "Error: Unable to open file " << filename << std::endl;
		return (EXIT_FAILURE);
	}

	std::string line;
	while (getline(ifs, line)) {
		size_t idx = 0;
		while (1) {
			idx = line.find(s1, idx);
			if (idx == std::string::npos) {
				ofs << line << std::endl;
				break;
			}
			line.erase(line.begin() + idx, line.begin() + idx + s1.length());
			line.insert(idx, s2);
			idx += s2.length();
		}
	}
	ifs.close();
}
