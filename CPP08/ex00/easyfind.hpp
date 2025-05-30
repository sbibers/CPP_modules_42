/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.amman>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:53:32 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/30 18:05:52 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <vector>

class NumberDoesNotFound;

template <typename T>
typename T::iterator easyfind(T &container, int num)
{
    typename T::iterator it = std::find(container.begin(), container.end(), num);
    if (it == container.end())
        throw NumberDoesNotFound();
    return (it);
}

class NumberDoesNotFound : public std::exception
{
    public:
        const char *what() const throw()
        {
            return ("The Number Does Not Inside The Containter !!!");
        }
};

#endif
