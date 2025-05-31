/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:06:51 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/31 12:35:02 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::cout << "Test vector container\n";
	Span span = Span(5);
	span.addNumber(6);
	span.addNumber(2);
	span.addNumber(21);
	span.addNumber(9);
	span.addNumber(10);
	try
	{
		span.addNumber(11);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
    std::cout << "---------------------\n";
    try
	{
		std::cout << "shortest_span: " << span.shortest_span() << std::endl;
		std::cout << "longest_span: " << span.longest_span() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
    std::cout << "---------------------\n";
    
	std::cout << "Test vector range\n";
	Span sp2 = Span(100);
	std::vector<int> v;
	std::srand(time(NULL));
	for (int i = 0; i < 100; i++)
		v.push_back(rand() % 1000000);
	try
	{
        sp2.addNumber(v.begin(), v.end());
		std::cout << "shortest_span: " << sp2.shortest_span() << std::endl;
		std::cout << "longest_span: " << sp2.longest_span() << std::endl;
	}
	catch (const std::exception &e)
	{
        std::cout << e.what() << std::endl;
	}
    std::cout << "---------------------\n";
    
	std::cout << "Test vector large range\n";
	Span sp3 = Span(100000);
	std::vector<int> v2;
	std::srand(time(NULL));
	for (int i = 0; i < 100000; i++)
    	v2.push_back(rand() % 1000000000);
	try
	{
        sp3.addNumber(v2.begin(), v2.end());
		std::cout << "shortest span: " << sp3.shortest_span() << std::endl;
		std::cout << "longest span: " << sp3.longest_span() << std::endl;
	}
	catch (std::exception &e)
	{
        std::cout << e.what() << std::endl;
	}
	exit(0);
    return (0);
}
