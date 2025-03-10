/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:49:32 by salam             #+#    #+#             */
/*   Updated: 2025/03/10 16:03:19 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const std::string *arr_of_ideas, size_t size);
        ~Brain();
        Brain(const Brain &copy);
        Brain &operator=(const Brain &obj);
        void setIdeas(int index, std::string idea);
        std::string getIdeas(int index) const;
};


#endif
