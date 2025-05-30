/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.amman>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:59:06 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/30 18:18:33 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::cout << "Test list container\n";
	std::list<int> _list;
	for (int i = 0; i <= 20; i++)
		_list.push_front(i);
	try
	{
		std::cout << *easyfind(_list, 15) << std::endl;
		std::cout << *easyfind(_list, 1000) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------\n";
	std::cout << "Test vector container\n";
	std::vector<int> _vector;
	for (int i = 1; i <= 10; i++)
		_vector.push_back(i);
	try
	{
		std::cout << *easyfind(_vector, 5) << std::endl;
		std::cout << *easyfind(_vector, 20) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------\n";
	std::cout << "Test deque container\n";
	std::deque<int> _deque;
	for (int i = 0; i <= 500; i++)
		_deque.push_back(i);
	try
	{
		std::cout << *easyfind(_deque, 349) << std::endl;
		std::cout << *easyfind(_deque, 501) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
