/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:09:23 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/28 15:36:14 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>
#include <cstdlib>

template <typename T1, typename T2>
void iter(T1 address, int length, T2 function)
{
    if (length <= 0)
        return;
    for (int i = 0; i < length; i++)
        function(address[i]);
}

#endif
