/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.amman>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:27:25 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/23 20:01:02 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool is_special(const std::string &str)
{
    return (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff");
}

static bool is_char(const std::string &str, size_t &length) // check if the input like this char -> ("'a'" or a)
{
    return ((length == 1 && !isdigit(str[0]))
        || (length == 3 && str[0] == '\'' && str[2] == '\''));
}

static bool is_int(const std::string &str, size_t &length)
{
    int i = 0;
    bool flag = false;

    if (str[0] == '-' || str[0] == '+')
    {
        i++;
        flag = true;
    }
    while ((str[i] && length > 0 && length <= 11) || (str[i] && !flag && length > 0 && length <= 10))
    {
        if (!isdigit(str[i]))
            return (false);
        i++;
    }
    return (true);
}

static bool is_float(const std::string &str, size_t &length, size_t &dot)
{
    for (int i = dot - 1; i >= 0; i--)
    {
        if (!isdigit(str[i]) && i != 0)
            return (false);
        if (!isdigit(str[i]) && i == 0 && str[i] != '+' && str[i] != '-')
            return (false);
    }
    for (size_t i = dot + 1; i < length; i++)
    {
        if (!isdigit(str[i]) && str[i] != 'f')
            return (false);
        if (str[i] == 'f' && i != length - 1)
            return (false);
    }
    return (true);
}

type_of which_type(const std::string &str, size_t &length)
{
    size_t dot = str.find("."); // function (find) do not find the string in a str it is return std::string::npos (-1 or SIZE_MAX).
    size_t find_f = str.find("f");
    if (dot == std::string::npos) // std::string::npos : constant variable (do not find it).
    {
        if (is_special(str))
            return (SPECIAL);
        if (is_char(str, length))
            return (CHAR);
        if (is_int(str, length))
            return (INT);
    }
    if (find_f != std::string::npos && dot != std::string::npos)
    {
        if (is_float(str, length, dot))
            return (FLOAT);
    }
    else if (find_f == std::string::npos && dot != std::string::npos)
        return (DOUBLE);
    return (INVALID);
}

