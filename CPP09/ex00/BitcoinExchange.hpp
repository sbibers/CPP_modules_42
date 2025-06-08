/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.amman>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:32:07 by sbibers           #+#    #+#             */
/*   Updated: 2025/06/08 17:11:30 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <cstdlib>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _map;
        float get_close_rate(const std::string& date) const;
        bool check_header(const std::string &line, char delimiter,
            const std::string &expected_left, const std::string &expected_right);
        bool check_date(const std::string &date) const;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &);
        BitcoinExchange &operator=(const BitcoinExchange &);
        ~BitcoinExchange();
        void process_input_file(const std::string& file_name);
        void calculate_value(const std::string &date, const std::string &value);
        class CanNotOpenFile : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class BadData : public std::exception
        {
            public: 
                const char *what() const throw();
        };
};

#endif
