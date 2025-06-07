/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.amman>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:48:03 by sbibers           #+#    #+#             */
/*   Updated: 2025/06/07 21:14:28 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
    _vector = obj._vector;
    _deque = obj._deque;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &obj)
{
    if (this != &obj)
    {
        _vector = obj._vector;
        _deque = obj._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{}

const char *PmergeMe::InvalidInput::what() const throw()
{
    return ("Error: Invalid input");
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

void PmergeMe::merge_vector(std::vector<int> &array, int left, int mid, int right)
{
    std::vector<int> temp(right - left + 1);
    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right)
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }
    while (i <= mid)
        temp[k++] = array[i++];
    while (j <= right)
        temp[k++] = array[j++];
    for (i = 0; i < k; i++)
        array[left + i] = temp[i];
}

void PmergeMe::insertion_sort_vector(std::vector<int> &array, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int key = array[i];
        int j = i - 1;
        while (j >= left && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void PmergeMe::merge_insert_sort_vector(std::vector<int> &array)
{
    int len = array.size();
    if (len <= 1)
        return;
    for (int size = 1; size < len; size *= 2)
    {
        for (int left = 0; left < len - size; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = std::min(left + 2 * size - 1, len - 1);
            
            if (right - left <= 10)
                insertion_sort_vector(array, left, right);
            else
                merge_vector(array, left, mid, right);
        }
    }
}

void PmergeMe::merge_deque(std::deque<int> &array, int left, int right, int mid)
{
    std::deque<int> temp;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (array[i] <= array[j])
            temp.push_back(array[i++]);
        else
            temp.push_back(array[j++]);
    }
    while (i <= mid)
        temp.push_back(array[i++]);
    while (j <= right)
        temp.push_back(array[j++]);
    for (size_t i = 0; i < temp.size(); i++)
        array[left + i] = temp[i];
}

void PmergeMe::insertion_sort_deque(std::deque<int> &array, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int key = array[i];
        int j = i - 1;
        while (j >= left && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void PmergeMe::merge_insert_sort_deque(std::deque<int> &array)
{
    int len = array.size();
    if (len <= 1)
        return;
    for (int size = 1; size < len; size *= 2)
    {
        for (int left = 0; left < len - size; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = std::min(left + 2 * size - 1, len - 1);
            
            if (right - left <= 10)
                insertion_sort_deque(array, left, right);
            else
                merge_deque(array, left, right, mid);
        }
    }
}

void PmergeMe::print_time(const std::string &str, double time) const
{
    std::cout << "Time to process a range of " << _vector.size() 
              << " elements with std::" << str 
              << " : " << std::fixed << std::setprecision(5) 
              << time << " us" << std::endl;
}

void PmergeMe::store_and_check_input(int argc, char **argv)
// store and check the argumnets.
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
        temp_vector.push_back(number);
    }
}

void PmergeMe::sort(int argc, char **argv)
{
    store_and_check_input(argc, argv);
    // clock : save the number of ticks (time units) since the program started running until thie moment in the variable.
    start_time = clock();
    merge_insert_sort_vector(_vector);
    end_time = clock();
    // convert time to micro second.
    vector_time = (double)(end_time - start_time) * 1000000 / CLOCKS_PER_SEC;
    // sort deque
    start_time = clock();
    merge_insert_sort_deque(_deque);
    end_time = clock();
    deque_time = (double)(end_time - start_time) * 1000000 / CLOCKS_PER_SEC;
    print_before();
    print_after();
    print_time("vector", vector_time);
    print_time("deque", deque_time);
}

void PmergeMe::print_before() const
// print element before sorting.
{
    std::cout << "Before: ";
    for (size_t i = 0; i < temp_vector.size(); i++)
    {
        std::cout << temp_vector[i];
        if (i < temp_vector.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::print_after() const
// print element after sorting.
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
