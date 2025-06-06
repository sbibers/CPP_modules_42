/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.amman>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:28:46 by sbibers           #+#    #+#             */
/*   Updated: 2025/06/06 14:39:13 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    load_data_base();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
    exchange = obj.exchange;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
    if (this != &obj)
        exchange = obj.exchange;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{}

static bool check_date(const std::string &date)
{
    int count = 0;
    for (size_t i = 0; i < date.length(); i++)
    {
        if (date[i] == '-')
            count++;
    }
    if (count == 2)
        return (true);
    return (false);
}

static std::string trim(const std::string& str)
{
    size_t first = str.find_first_not_of(" \t");
    if (first == std::string::npos)
        return ("");
    size_t last = str.find_last_not_of(" \t");
    return (str.substr(first, (last - first + 1)));
}

static bool check_header(const std::string& line, char delimiter,
    const std::string& expectedLeft, const std::string& expectedRight)
{
    size_t delimPos = line.find(delimiter);
    if (delimPos == std::string::npos)
        return (false);
    std::string left = trim(line.substr(0, delimPos));
    std::string right = trim(line.substr(delimPos + 1));
    return (left == expectedLeft && right == expectedRight);
}

void BitcoinExchange::load_data_base()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database file.");
    std::string line;
    std::getline(file, line); // Skip header
    if (line.empty())
        throw std::runtime_error("Error: (data.csv) empty.");
    if (!check_header(line, ',', "date", "exchange_rate")) // check_header
        throw std::runtime_error("Error: bad header in a file (data.csv).");
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date, rate;
        std::getline(ss, date, ',');
        if (date.empty()) // check if date empty.
            throw std::runtime_error("Error: bad data in file (data.csv).");
        if (!check_date(date)) // check if date have (double (-)).
            throw std::runtime_error("Error: bad data in file (data.csv)");
        std::getline(ss, rate);
        if (rate.empty()) // check if rate empty.
            throw std::runtime_error("Error: bad data in file (data.csv).");
        exchange[date] = std::atof(rate.c_str());
    }
}

bool BitcoinExchange::valid_date(const std::string& date) const
{
    if (date.length() != 10)
        return (false);
    if (date[4] != '-' || date[7] != '-')
        return (false);
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if (year < 2009 || year > 2024)
        return (false);
    if (month < 1 || month > 12)
        return (false);
    if (day < 1 || day > 31)
        return (false);
    return (true);
}

bool BitcoinExchange::valid_value(const float &value) const
{
    return (value >= 0 && value <= 1000);
}

float BitcoinExchange::get_close_rate(const std::string& date) const
{
    std::map<std::string, float>::const_iterator it = exchange.lower_bound(date);
    if (it == exchange.begin())
        return (it->second);
    if (it == exchange.end())
        return ((--it)->second);
    if (it->first == date)
        return (it->second);
    return ((--it)->second);
}

void BitcoinExchange::process_input_file(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line); // Skip header
    if (line.empty())
        throw std::runtime_error("Error: input file empty.");
    if (!check_header(line, '|', "date", "value"))
        throw std::runtime_error("Error: bad header input data file.");
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date, value;
        std::getline(ss, date, '|');
        if (date.empty())
            throw std::runtime_error("Error: bad input data file.");
        std::getline(ss, value);
        // Trim whitespace
        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        value.erase(0, value.find_first_not_of(" \t"));
        value.erase(value.find_last_not_of(" \t") + 1);
        calculate_value(date, value);
    }
}

void BitcoinExchange::calculate_value(const std::string& date, const std::string& value)
{
    if (!valid_date(date))
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return;
    }
    if (!valid_value(std::atof(value.c_str())))
    {
        if (std::atof(value.c_str()) < 0)
            std::cerr << "Error: not a positive number." << std::endl;
        else if (std::atof(value.c_str()) > 1000)
            std::cerr << "Error: too large a number." << std::endl;
        return;
    }
    float rate = get_close_rate(date);
    float val = std::atof(value.c_str());
    std::cout << date << " => " << value << " = " << (rate * val) << std::endl;
}
