/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:53:40 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/23 19:47:10 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
    *this = obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
    (void)obj;
    return (*this);
}

const char *ScalarConverter::ScalarConverterErrorConvertException::what() const throw()
{
    return ("ScalarConverterErrorConvertException: Error converting");
}

static void print_special(const std::string &str)
{
    if (str == "nan" || str == "nanf")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: +inff\n";
		std::cout << "double: +inf\n";
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
	}
}

static void convert_char(const std::string &str, size_t &length)
{
    char chr;

    if (length == 1)
        chr = str[0];
    else
        chr = str[1];
    if (isprint(chr))
    {
        std::cout << "char: '" << chr << "'\n";
        std::cout << "int: " << static_cast<int>(chr) << std::endl;
        std::cout << "float: " << static_cast<float>(chr) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(chr) << ".0" << std::endl;
    }
    else
    {
        std::cout << "char: Non Displayable\n";
        std::cout << "int: " << static_cast<int>(chr) << std::endl;
        std::cout << "float: " << static_cast<float>(chr) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(chr) << ".0" << std::endl;
    }
}

static void convert_int(const std::string &str)
{
    long num;
    try
    {
        num = std::atol(str.c_str());
    }
    catch (const ScalarConverter::ScalarConverterErrorConvertException &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "char: ";
    if (num > 127 || num < 127)
        std::cout << "impossible\n";
    else
    {
        if (isprint(num))
            std::cout << "'" << static_cast<char>(num) << std::endl;
        else
            std::cout << "Non displayable\n";
    }
    std::cout << "int: ";
    if (num > INT_MAX || num < INT_MIN)
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(num) << std::endl;
    std::cout << "float: " << static_cast<float>(num) << ".0f\n";
    std::cout << "double: " << static_cast<double>(num) << ".0\n";
}

static void convert_float(const std::string &str)
{
    float num;
    try
    {
        num = std::atof(str.c_str());
    }
    catch (const ScalarConverter::ScalarConverterErrorConvertException &e)
    {
        std::cout << e.what() << std::endl;
    }
    bool flag = std::fabs(num - static_cast<int>(num)) < 0.0000000000001;
    std::cout << "char: ";
    if (num < 0 || num > 127)
        std::cout << "impossible\n";
    else
    {
        if (isprint(num))
            std::cout << "'" << static_cast<char>(num) << "'\n";
        else
            std::cout << "Non displayable\n";
    }
    std::cout << "int: ";
    if (static_cast<long>(num) < INT_MIN || static_cast<long>(num) > INT_MAX)
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(num) << std::endl;
    std::cout << "float: ";
    if (num < FLOAT_MIN || num > FLOAT_MAX)
        std::cout << "impossible\n";
    else
    {
        if (flag)
            std::cout << num << ".0f\n";
        else
            std::cout << num << "f\n";
    }
    if (flag)
        std::cout << "double: " << static_cast<double>(num) << ".0\n";
    else
        std::cout << "double: " << static_cast<double>(num) << std::endl;
}

static void convert_double(const std::string &str)
{
    double num;
    try
    {
        num = std::atof(str.c_str());
    }
    catch (const ScalarConverter::ScalarConverterErrorConvertException &e)
    {
        std::cout << e.what() << std::endl;
    }
    bool flag = std::fabs(num - static_cast<int>(num)) < 0.0000000000001;

    std::cout << "char: ";
    if (num < 0 ||  num > 127)
        std::cout << "impossible\n";
    else
    {
        if (isprint(num))
            std::cout << "'" << static_cast<char>(num) << std::endl;
        else
            std::cout << "Non displayable\n";
    }
    std::cout << "int: ";
    if (num < INT_MIN || num > INT_MAX)
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(num) << std::endl;
    std::cout << "float: ";
    if (num < FLOAT_MIN || num > FLOAT_MAX)
        std::cout << "impossible\n";
    else
    {
        if (flag)
            std::cout << static_cast<float>(num) << ".0f\n";
        else
            std::cout << static_cast<float>(num) << ".f\n";
    }
    std::cout << "double: ";
    if (num < DOUBLE_MIN || num > DOUBLE_MAX)
        std::cout << "impossible\n";
    else
        std::cout << num << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
    size_t length = str.length();
    type_of type = which_type(str, length);
    if (!check_input(str, length) && !is_special(str))
    {
        std::cout << "INVALID_INPUT\n";
        return;
    }
    switch (type)
    {
        case INVALID:
            std::cout << "INVALID_INPUT\n";
            break;
        case SPECIAL:
            print_special(str);
            break;
        case CHAR:
            convert_char(str, length);
            break;
        case INT:
            convert_int(str);
            break;
        case FLOAT:
            convert_float(str);
            break;
        case DOUBLE:
            convert_double(str);
            break;
    }
}
