/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.amman>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:48:03 by sbibers           #+#    #+#             */
/*   Updated: 2025/10/15 14:31:22 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
    _vector = obj._vector;
    _deque = obj._deque;
    _temp_vector = obj._temp_vector;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
    if (this != &obj)
    {
        _vector = obj._vector;
        _deque = obj._deque;
        _temp_vector = obj._temp_vector;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

const char *PmergeMe::InvalidInput::what() const throw()
{
    return ("Error: Invalid Input!!!");
}

bool PmergeMe::is_valid_number(const std::string &str) const
{
    if (str.empty())
        return (false);
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return (false);
    }
    return (true);
}

std::vector<int> PmergeMe::generate_jacobsthal_sequence(int n)
{
    std::vector<int> jacobsthal;
    if (n <= 0)
        return jacobsthal;
    
    jacobsthal.push_back(1);
    if (n == 1)
        return jacobsthal;
    
    jacobsthal.push_back(3);
    
    while (jacobsthal.back() < n)
    {
        int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        if (next > n)
            break;
        jacobsthal.push_back(next);
    }
    
    return jacobsthal;
}

void PmergeMe::binary_insert_vector(std::vector<int> &arr, int value, int end)
{
    int left = 0;
    int right = end;
    
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    
    arr.insert(arr.begin() + left, value);
}

void PmergeMe::ford_johnson_sort_vector(std::vector<int> &arr)
{
    int n = arr.size();
    if (n <= 1)
        return;
    
    std::vector<std::pair<int, int> > pairs;
    bool has_odd = (n % 2 == 1);
    int odd_element = has_odd ? arr[n - 1] : 0;
    
    for (int i = 0; i < n - (has_odd ? 1 : 0); i += 2)
    {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }
    
    if (pairs.empty())
    {
        if (has_odd)
            arr[0] = odd_element;
        return;
    }
    
    std::vector<int> larger_elements;
    std::vector<int> smaller_elements;
    
    for (size_t i = 0; i < pairs.size(); i++)
    {
        larger_elements.push_back(pairs[i].first);
        smaller_elements.push_back(pairs[i].second);
    }
    
    ford_johnson_sort_vector(larger_elements);
    
    std::vector<int> main_chain;
    if (!smaller_elements.empty())
        main_chain.push_back(smaller_elements[0]);
    
    for (size_t i = 0; i < larger_elements.size(); i++)
        main_chain.push_back(larger_elements[i]);
    
    if (smaller_elements.size() > 1)
    {
        std::vector<int> jacobsthal = generate_jacobsthal_sequence(smaller_elements.size());
        std::vector<bool> inserted(smaller_elements.size(), false);
        inserted[0] = true;
        
        for (size_t i = 0; i < jacobsthal.size(); i++)
        {
            int jacob_num = jacobsthal[i];

            int start = (i == 0) ? jacob_num : jacobsthal[i - 1] + 1;
            
            for (int j = std::min(jacob_num, (int)smaller_elements.size()) - 1; j >= start - 1 && j >= 1; j--)
            {
                if (!inserted[j])
                {
                    int pos = j + 1; // Position in main chain where this element's pair is
                    binary_insert_vector(main_chain, smaller_elements[j], pos);
                    inserted[j] = true;
                }
            }
        }
        
        for (size_t i = 1; i < smaller_elements.size(); i++)
        {
            if (!inserted[i])
                binary_insert_vector(main_chain, smaller_elements[i], main_chain.size());
        }
    }

    if (has_odd)
        binary_insert_vector(main_chain, odd_element, main_chain.size());
    
    arr = main_chain;
}

std::vector<int> PmergeMe::generate_jacobsthal_sequence_deque(int n)
{
    return generate_jacobsthal_sequence(n);
}

void PmergeMe::binary_insert_deque(std::deque<int> &arr, int value, int end)
{
    int left = 0;
    int right = end;
    
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    
    arr.insert(arr.begin() + left, value);
}

void PmergeMe::ford_johnson_sort_deque(std::deque<int> &arr)
{
    int n = arr.size();
    if (n <= 1)
        return;
    
    // Step 1: Create pairs and sort them
    std::vector<std::pair<int, int> > pairs;
    bool has_odd = (n % 2 == 1);
    int odd_element = has_odd ? arr[n - 1] : 0;
    
    for (int i = 0; i < n - (has_odd ? 1 : 0); i += 2)
    {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }
    
    if (pairs.empty())
    {
        if (has_odd)
            arr[0] = odd_element;
        return;
    }
    
    std::deque<int> larger_elements;
    std::deque<int> smaller_elements;
    
    for (size_t i = 0; i < pairs.size(); i++)
    {
        larger_elements.push_back(pairs[i].first);
        smaller_elements.push_back(pairs[i].second);
    }
    
    ford_johnson_sort_deque(larger_elements);
    
    std::deque<int> main_chain;
    if (!smaller_elements.empty())
        main_chain.push_back(smaller_elements[0]);
    
    for (size_t i = 0; i < larger_elements.size(); i++)
        main_chain.push_back(larger_elements[i]);
    
    if (smaller_elements.size() > 1)
    {
        std::vector<int> jacobsthal = generate_jacobsthal_sequence_deque(smaller_elements.size());
        std::vector<bool> inserted(smaller_elements.size(), false);
        inserted[0] = true;
        
        for (size_t i = 0; i < jacobsthal.size(); i++)
        {
            int jacob_num = jacobsthal[i];
            
            int start = (i == 0) ? jacob_num : jacobsthal[i - 1] + 1;
            
            for (int j = std::min(jacob_num, (int)smaller_elements.size()) - 1; j >= start - 1 && j >= 1; j--)
            {
                if (!inserted[j])
                {
                    int pos = j + 1;
                    binary_insert_deque(main_chain, smaller_elements[j], pos);
                    inserted[j] = true;
                }
            }
        }
        
        for (size_t i = 1; i < smaller_elements.size(); i++)
        {
            if (!inserted[i])
                binary_insert_deque(main_chain, smaller_elements[i], main_chain.size());
        }
    }
    
    if (has_odd)
        binary_insert_deque(main_chain, odd_element, main_chain.size());
    
    arr = main_chain;
}

void PmergeMe::print_time(const std::string &str, double time) const
{
    std::cout << "Time to process a range of " << _vector.size()
              << " elements with std::" << str
              << " : " << std::fixed << std::setprecision(5)
              << time << " us" << std::endl;
}

void PmergeMe::store_and_check_input(int argc, char **argv)
{
    for (int i = 1, j = 0; i < argc; i++, j++)
    {
        if (!is_valid_number(argv[i]))
            throw PmergeMe::InvalidInput();
        int number = std::atoi(argv[i]);
        if (number < 0)
            throw PmergeMe::InvalidInput();
        _vector.push_back(number);
        _deque.push_back(number);
        _temp_vector.push_back(number);
    }
}

void PmergeMe::sort(int argc, char **argv)
{
    store_and_check_input(argc, argv);
    
    // sort vector using Ford-Johnson algorithm
    start_time = clock();
    ford_johnson_sort_vector(_vector);
    end_time = clock();
    vector_time = (double)(end_time - start_time) * 1000000 / CLOCKS_PER_SEC;
    
    // sort deque using Ford-Johnson algorithm
    start_time = clock();
    ford_johnson_sort_deque(_deque);
    end_time = clock();
    deque_time = (double)(end_time - start_time) * 1000000 / CLOCKS_PER_SEC;
    
    print_before();
    print_after();
    print_time("vector", vector_time);
    print_time("deque", deque_time);
}

void PmergeMe::print_before() const
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _temp_vector.size(); i++)
    {
        std::cout << _temp_vector[i];
        if (i < _temp_vector.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::print_after() const
{
    std::cout << "After: ";
    for (size_t i = 0; i < _vector.size(); i++)
    {
        std::cout << _vector[i];
        if (i < _vector.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}
