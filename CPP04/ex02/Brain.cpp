/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:14:55 by salam             #+#    #+#             */
/*   Updated: 2025/03/10 21:25:59 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std :: cout << "Brain Constructor Called" << std :: endl;
}

Brain::Brain(const std::string *arr_of_ideas, size_t size)
{
    std :: cout << "Brain Constructor with array of ideas Called" << std :: endl;
    if (arr_of_ideas)
    { 
        for (size_t i = 0; i < size; i++)
        {
            this->ideas[i] = arr_of_ideas[i];
        }
    }
    else
    {
        std :: cout << "Error: Array of ideas is NULL" << std :: endl;
    }
}

Brain::Brain(const Brain &copy)
{
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = copy.ideas[i];
    }
}

Brain &Brain::operator=(const Brain &obj)
{
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = obj.ideas[i];
    }
    return (*this);
}

void Brain::setIdeas(int index, std::string idea)
{
    if (index >= 0 && index < 100)
        this->ideas[index] = idea;
    else
        std :: cerr << "Error: Index is out of bounds" << std :: endl;
}

std::string Brain::getIdeas(int index) const
{
    if (index < 0 || index >= 100)
    {
        std :: cerr << "Error: Index is out of bounds" << std :: endl;
        return ("");
    }
    return (this->ideas[index]);
}

Brain::~Brain()
{
    std :: cout << "Brain Destructor Called" << std :: endl;
}
