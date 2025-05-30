/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.amman>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:49:59 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/30 21:28:23 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    std::cout << "Test MutantStack\n";
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    std::cout << "Iterating through MutantStack : ";
    MutantStack<int>::iterator it_1 = mstack.begin();
    MutantStack<int>::iterator it_2 = mstack.end();
    while (it_1 != it_2)
    {
        std::cout << *it_1 << " ";
        it_1++;
    }
    std::cout << "\n---------------------\n";
    std::cout << "Test list for comparison\n";
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << "Top (last element): " << lst.back() << std::endl;
    lst.pop_back();
    std::cout << "Size after pop: " << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    std::cout << "Iterating through std::list : ";
    it_1 = mstack.begin();
    it_2 = mstack.end();
    while (it_1 != it_2)
    {
            std::cout << *it_1 << " ";
            it_1++;
    }
    std::cout << std::endl;
    return (0);
}
