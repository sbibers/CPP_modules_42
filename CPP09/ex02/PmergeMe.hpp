/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.amman>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:43:56 by sbibers           #+#    #+#             */
/*   Updated: 2025/06/07 21:14:12 by sbibers          ###   ########.fr       */
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

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::vector<int> temp_vector;
        std::deque<int> _deque;
        clock_t start_time;
        clock_t end_time;
        double vector_time;
        double deque_time;

        // vector sorting functions
        void merge_insert_sort_vector(std::vector<int> &arr);
        void merge_vector(std::vector<int> &arr, int left, int mid, int right);
        void insertion_sort_vector(std::vector<int> &arr, int left, int right);

        // deque sorting functions
        void merge_insert_sort_deque(std::deque<int> &arr);
        void merge_deque(std::deque<int> &arr, int left, int right, int mid);
        void insertion_sort_deque(std::deque<int> &arr, int left, int right);

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
