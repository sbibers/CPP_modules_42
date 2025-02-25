/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:48:20 by sbibers           #+#    #+#             */
/*   Updated: 2025/02/25 19:12:53 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

void replace(std::string file_name, std::string s1, std::string s2)
{
    int i;

    i = 0;
    std:: ifstream input_file(file_name.c_str());
    if (!input_file.is_open())
    {
        std::cerr << "Error, Unable to open : " << file_name << std :: endl;
        std::exit(1);
    }
    std::string new_file = file_name + ".replace";
    std::ofstream output_file(new_file.c_str());
    if (!output_file.is_open())
    {
        std::cerr << "Error, Unable to open : " << new_file << std :: endl;
        input_file.close();
        std::exit(1);
    }
    std::stringstream buffer;
    buffer << input_file.rdbuf();
    std::string content = buffer.str();
    i = 0;
    while (s1.length())
    {
        i = content.find(s1, i);
        if (i == -1)
            break;
        content.erase(i, s1.length());
        content.insert(i, s2);
        i = i + s2.length();
    }
    output_file << content;
    input_file.close();
    output_file.close();
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return (1);
    }
    std::string file_name = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (s1.empty())
    {
        std::cerr << "Empty string to replace it." << std :: endl;
        return (1);
    }
    replace(file_name, s1, s2);
    return (0);
}
