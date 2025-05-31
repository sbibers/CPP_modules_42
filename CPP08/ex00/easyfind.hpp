/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:53:32 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/31 12:27:59 by sbibers          ###   ########.fr       */
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

class NumberDoesNotFound : public std::exception
{
    public:
        const char *what() const throw()
        {
            return ("The Number Does Not Inside The Containter !!!");
        }
};

template <typename T>
typename T::iterator easyfind(T &container, int num)
{
    typename T::iterator it = std::find(container.begin(), container.end(), num);
    if (it == container.end())
        throw NumberDoesNotFound();
    return (it);
}

#endif
