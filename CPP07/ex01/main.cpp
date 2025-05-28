/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:14:32 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/28 15:35:36 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <limits>

void print_int(const int &element)
{
    std::cout << element << " ";
}

void print_string(const std::string &str)
{
    std::cout << str << " ";
}

void increment(int &element)
{
    element++;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    std::cout << "Int Array Before Increment : ";
    ::iter(arr, 5, print_int);
    std::cout << std::endl;
    std::cout << "Int Array After Increment : ";
    ::iter(arr, 5, increment);
    ::iter(arr, 5, print_int);
    std::cout << std::endl;
    std::string arr_str[] = {"one", "two", "three", "four", "five"};
    std::cout << "String Array : ";
    ::iter(arr_str, 5, print_string);
    std::cout << std::endl;
    return (0);
}
