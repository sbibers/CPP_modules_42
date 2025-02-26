/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:48:20 by sbibers           #+#    #+#             */
/*   Updated: 2025/02/26 12:12:28 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

void replace(std::string file_name, std::string old_str, std::string new_str)
{
    std:: ifstream in(file_name.c_str());
    if (!in.is_open())
    {
        std :: cerr << "Error, Unable to open : " << file_name << "." << std :: endl;
        std :: exit(1);
    }
    std :: string new_file = file_name + ".replace";
    std :: ofstream out(new_file.c_str());
    if (!out.is_open())
    {
        std :: cerr << "Error, Unable to open : " << new_file << "." << std :: endl;
        in.close();
        std :: exit(1);
    }
    std :: stringstream buffer;
    buffer << in.rdbuf();
    std :: string content = buffer.str();
    int i = 0;
    while (old_str.length())
    {
        i = content.find(old_str, i);
        if (i == -1)
            break;
        content.erase(i, old_str.length());
        content.insert(i, new_str);
        i = i + new_str.length();
    }
    out << content;
    in.close();
    out.close();
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std :: cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return (1);
    }
    std :: string file_name = argv[1];
    std :: string old_str = argv[2];
    std :: string new_str = argv[3];
    if (old_str.empty())
    {
        std :: cerr << "Empty string to replace it." << std :: endl;
        return (1);
    }
    replace(file_name, old_str, new_str);
    return (0);
}
