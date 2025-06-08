/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.amman>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:28:46 by sbibers           #+#    #+#             */
/*   Updated: 2025/06/08 17:11:28 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const char *BitcoinExchange::CanNotOpenFile::what() const throw()
{
    return ("Error: Can Not Open File!!!");
}

const char *BitcoinExchange::BadData::what() const throw()
{
    return ("Error: Bad Data!!!");
}

BitcoinExchange::BitcoinExchange()
{
    std::ifstream data_file("data.csv");
    if (!data_file.is_open())
        throw BitcoinExchange::CanNotOpenFile();
    std::string str;
    std::getline(data_file, str);
    if (str.empty())
        throw BitcoinExchange::BadData();
    if (!check_header(str, ',', "date", "exchange_rate"))
        throw BitcoinExchange::BadData();
    while (std::getline(data_file, str))
    {
        size_t pos = str.find(',');
        if (pos == std::string::npos)
            throw BitcoinExchange::BadData();
        std::string date = str.substr(0, pos);
        std::string rate = str.substr(pos + 1, str.length());
        if (date.empty() || !check_date(date) || rate.empty())
            throw BitcoinExchange::BadData();
        _map[date] = std::atof(rate.c_str());
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
    this->_map = obj._map;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
    if (this != &obj)
        this->_map = obj._map;
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{}

bool BitcoinExchange::check_date(const std::string &date) const
{
    size_t count = 0;
    for (size_t i = 0; i < date.length(); i++)
    {
        if (date[i] == '-')
            count++;
    }
    if (count == 2)
        return (true);
    return (false);
}

static std::string trim(const std::string &str)
{
    size_t first = str.find_first_not_of(" \t"); // find first index does not equal (' ', '\t').
    if (first == std::string::npos)
        return ("");
    size_t last = str.find_last_not_of(" \t");
    return (str.substr(first, (last - first + 1)));
}

bool BitcoinExchange::check_header(const std::string &line, char delimiter,
    const std::string &expected_left, const std::string &expected_right)
{
    size_t delim_pos = line.find(delimiter);
    if (delim_pos == std::string::npos)
        return (false);
    std::string left = trim(line.substr(0, delim_pos));
    std::string right = trim(line.substr(delim_pos + 1));
    return (left == expected_left && right == expected_right);
}

static bool valid_date(const std::string &date)
{
    if (date.length() != 10)
        return (false);
    if (date[4] != '-' || date[7] != '-')
        return (false);
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if ((year < 2009 || year > 2025)
        || (month < 1 || month > 12)
        || (day < 1 || day > 31))
        return (false);
    return (true);
}

float BitcoinExchange::get_close_rate(const std::string& date) const
{
    std::map<std::string, float>::const_iterator it = _map.lower_bound(date);
    // --> get the first key in the map large or equal date or end if does not exist.
    if (it == _map.begin())
        return (it->second);
    if (it == _map.end())
        return ((--it)->second);
    if (it->first == date)
        return (it->second);
    return ((--it)->second);
}

void BitcoinExchange::calculate_value(const std::string &date, const std::string &value)
{
    if (!valid_date(date))
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return;
    }
    if (std::atof(value.c_str()) < 0 || std::atof(value.c_str()) > 1000)
    {
        if (std::atof(value.c_str()) < 0)
            std::cerr << "Error: not a positive number.\n";
        else if (std::atof(value.c_str()) > 1000)
            std::cerr << "Error: too large a number.\n";
        return;
    }
    float rate = get_close_rate(date);
    float val = std::atof(value.c_str());
    std::cout << date << " => " << value << " = " << (rate * val) << std::endl;
}

void BitcoinExchange::process_input_file(const std::string &file_name)
{
    std::ifstream file(file_name.c_str());
    if (!file.is_open())
        throw BitcoinExchange::CanNotOpenFile();
    std::string str;
    std::getline(file, str);
    if (str.empty())
        throw BitcoinExchange::BadData();
    if (!check_header(str, '|', "date", "value"))
        throw BitcoinExchange::BadData();
    while (std::getline(file, str))
    {
        size_t pos = str.find('|');
        std::string date = str.substr(0, pos);
        if (date.empty())
            throw BitcoinExchange::BadData();
        std::string value = str.substr(pos + 1, str.length());
        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        value.erase(0, value.find_first_not_of(" \t"));
        value.erase(value.find_last_not_of(" \t") + 1);
        calculate_value(date, value);
    }
}
