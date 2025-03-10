/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:24:59 by salam             #+#    #+#             */
/*   Updated: 2025/03/10 15:31:37 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *brain;
    public:
        Dog();
        Dog(std::string type);
        Dog(const Dog &copy);
        Dog &operator=(const Dog &obj);
        ~Dog();
        void makeSound() const;
        void setBrain(Brain *brain);
        Brain *getBrain() const;
};

#endif
