/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:59:45 by salam             #+#    #+#             */
/*   Updated: 2025/08/04 19:24:51 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std :: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std :: endl;
        return (1);
    }
    for (size_t i = 1; argv[i]; i++)
    {
        std::string str;
        for (size_t j = 0; argv[i][j]; j++)
        {
            str += toupper(argv[i][j]);
        }
        std::cout << str;
    }
    std :: cout << std :: endl;
    return (0);
}
