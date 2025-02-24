/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:58:25 by sbibers           #+#    #+#             */
/*   Updated: 2025/02/24 17:08:57 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std :: cout << "Memory address : " << std :: endl;
    std :: cout << "str : " << &str << std :: endl;
    std :: cout << "stringPTR : " << stringPTR << std :: endl;
    std :: cout << "stringREF : " << &stringREF << std :: endl;
    std :: cout << "Value : " << std :: endl;
    std :: cout << "str : " << str << std :: endl;
    std :: cout << "stringPTR : " << *stringPTR << std :: endl;
    std :: cout << "stringREF : " << stringREF << std :: endl;
    return (0);
}
