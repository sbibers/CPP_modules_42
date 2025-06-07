/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.amman>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:50:51 by sbibers           #+#    #+#             */
/*   Updated: 2025/06/07 15:43:48 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

// Reverse polish notation = numbers - 1 = operators (-+*/).
// 1 2+3- = (1 + 2) - 3 = 0.

class RPN
{
    private:
        std::stack<int> _stack;
    public:
        RPN();
        RPN(const RPN &);
        RPN &operator=(const RPN &);
        ~RPN();
        void take_input(std::string input);
        int calculate_result(int number1, int number2, char c);
        class InvalidInput : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class WrongOperands : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class InvalidExpression : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

#endif
