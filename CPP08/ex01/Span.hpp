/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.amman>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:47:31 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/30 19:08:41 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
    private:
        unsigned int N;
        std::vector<int> vect;
    public:
        Span();
        Span(unsigned int N);
        ~Span();
        Span(const Span &);
        Span &operator=(const Span &);
        void addNumber(const int &num);
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortest_span();
        int longest_span();
        class FullContainerException : public std::exception
        {
            const char *what() const throw();
        };
        class NotEnoughNumberInVector : public std::exception
        {
            const char *what() const throw();
        };
};

#endif
