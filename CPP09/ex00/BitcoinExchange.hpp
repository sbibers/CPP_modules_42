/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.amman>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:32:07 by sbibers           #+#    #+#             */
/*   Updated: 2025/06/06 14:38:16 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>

class BitcoinExchange
{
    private:
        std::map<std::string, float> exchange;
        
        bool valid_date(const std::string& date) const;
        bool valid_value(const float &value) const;
        float get_close_rate(const std::string& date) const;
        void load_data_base();
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &);
        BitcoinExchange &operator=(const BitcoinExchange &);
        ~BitcoinExchange();
        void process_input_file(const std::string& filename);
        void calculate_value(const std::string& date, const std::string& value);
};

#endif
