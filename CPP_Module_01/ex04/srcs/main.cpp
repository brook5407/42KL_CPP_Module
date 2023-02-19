/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:49:01 by brook             #+#    #+#             */
/*   Updated: 2023/02/13 10:35:19 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char **argv){
	// Check for the correct number of arguments
	if (argc != 4){
		std::cerr << "\033[1;31mUsage: " << argv[0] << " <filename> <string for replace> <string to replace>\033[0m" << std::endl;
		return (EXIT_FAILURE);
	}
	// Get the filename, s1, and s2 from the command line arguments
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	// Open the input file
	std::ifstream	ifs(filename);
	if (ifs.fail()){
		std::cerr << "\033[1;31mError: Unable to open file " << filename << std::endl;
		return (EXIT_FAILURE);
	}
	 // Open the output file
	std::ofstream	ofs(filename + ".replace");
	if (ofs.fail()){
		std::cerr << "\033[1;31mError: Unable to open file " << filename << std::endl;
		return (EXIT_FAILURE);
	}
	// Copy contents of input file to output file since nothing could replace
	if (s1.empty())
		ofs << ifs.rdbuf();
	else {
		// Copy the contents of the input file to the output file, replacing s1 with s2
		std::string line;
		while (getline(ifs, line)) {
			size_t pos = 0;
			while (1) {
				pos = line.find(s1, pos);
				if (pos == std::string::npos) {
					ofs << line << std::endl;
					break;
				}
				line.erase(line.begin() + pos, line.begin() + pos + s1.length());
				line.insert(pos, s2);
				pos += s2.length();
			}
		}
	}
	// Close the input and output files
	ifs.close();
	ofs.close();
	return (EXIT_SUCCESS);
}
