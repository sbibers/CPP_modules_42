/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.amman>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:46:04 by sbibers           #+#    #+#             */
/*   Updated: 2025/06/08 16:54:26 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: Invalid Number Of Argument\n";
        return (1);
    }
    try
    {
        RPN obj;
        obj.solution(argv[1]);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
