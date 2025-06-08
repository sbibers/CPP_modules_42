/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.amman>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:53:38 by sbibers           #+#    #+#             */
/*   Updated: 2025/06/08 17:10:26 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN &obj)
{
    _stack = obj._stack;
}

RPN &RPN::operator=(const RPN &obj)
{
    if (this != &obj)
        _stack = obj._stack;
    return (*this);
}

RPN::~RPN()
{}

const char *RPN::InvalidInput::what() const throw()
{
    return ("Error: Invalid Input!!!");
}

const char *RPN::WrongOperands::what() const throw()
{
    return ("Error: Insufficient Operands!!!");
}

const char *RPN::InvalidExpression::what() const throw()
{
    return ("Error: Invalid Expression!!!");
}

int RPN::calculation(int number1, int number2, char c) const
{
    switch (c)
    {
        case '+':
            return (number1 + number2);
        case '-':
            return (number1 - number2);
        case '*':
            return (number1 * number2);
        case '/':
        {
            if (number2 == 0)
                throw RPN::InvalidInput();
            return (number1 / number2);
        }
    }
    return (0);
}

static bool check_char(char c)
{
    return (c != ' ' && c != '*' && c != '/'
        && c != '+' && c != '-');
}

void RPN::solution(const std::string &input)
{
    std::string operators = "+-*/";

    for (size_t i = 0; i < input.length(); i++)
    {
        if (std::isdigit(input[i]))
        {
            if (i + 1 > input.length())
            {
                if (check_char(input[i + 1]))
                    throw RPN::InvalidInput();
            }
            _stack.push(input[i] - '0');
        }
        else if (operators.find(input[i]) != std::string::npos)
        { 
            if (_stack.size() < 2)
                throw RPN::WrongOperands();
            int number2 = _stack.top();
            _stack.pop();
            int number1 = _stack.top();
            _stack.pop();
            int result = calculation(number1, number2, input[i]);
            _stack.push(result);
        }
        else if (std::isspace(input[i]))
            continue;
        else
            throw RPN::InvalidInput();
    }
    if (_stack.size() != 1)
        throw RPN::InvalidExpression();
    std::cout << _stack.top() << std::endl;
}
