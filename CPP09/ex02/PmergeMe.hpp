/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.amman>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:43:56 by sbibers           #+#    #+#             */
/*   Updated: 2025/10/15 14:31:28 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <algorithm>

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::vector<int> _temp_vector;
        std::deque<int> _deque;
        clock_t start_time;
        clock_t end_time;
        double vector_time;
        double deque_time;
        
        // Ford-Johnson algorithm for vector
        void ford_johnson_sort_vector(std::vector<int> &arr);
        std::vector<int> generate_jacobsthal_sequence(int n);
        void binary_insert_vector(std::vector<int> &arr, int value, int end);
        
        // Ford-Johnson algorithm for deque
        void ford_johnson_sort_deque(std::deque<int> &arr);
        std::vector<int> generate_jacobsthal_sequence_deque(int n);
        void binary_insert_deque(std::deque<int> &arr, int value, int end);
        
        bool is_valid_number(const std::string &str) const;
        void print_time(const std::string &container, double time) const;
        void store_and_check_input(int argc, char **argv);
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &);
        PmergeMe& operator=(const PmergeMe &);
        ~PmergeMe();
        void sort(int argc, char **argv);
        void print_before() const;
        void print_after() const;
        class InvalidInput : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

#endif
