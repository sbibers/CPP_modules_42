/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.amman>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:47:17 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/23 20:01:07 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <exception>
#include <cstdlib>
#include <limits>
#include <cmath>

#define INT_MIN std::numeric_limits<int>::min()
#define INT_MAX std::numeric_limits<int>::max()
#define FLOAT_MIN std::numeric_limits<float>::min()
#define FLOAT_MAX std::numeric_limits<float>::max()
#define DOUBLE_MIN std::numeric_limits<double>::min()
#define DOUBLE_MAX std::numeric_limits<double>::max()

enum type_of
{
    INVALID = -1,
    SPECIAL = 0,
    CHAR = 1,
    INT = 2,
    FLOAT = 3,
    DOUBLE = 4
};

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &obj);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &obj);
    public:
        static void convert(const std::string &str);
        class ScalarConverterErrorConvertException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

type_of which_type(const std::string &str, size_t &length);
void convert_double(const std::string &str);
void convert_float(const std::string &str);
void convert_int(const std::string &str);
void convert_char(const std::string &str, size_t &length);

#endif
