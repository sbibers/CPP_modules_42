/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:22:30 by salam             #+#    #+#             */
/*   Updated: 2025/03/08 17:13:05 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal &copy);
        Animal &operator=(const Animal &obj);
        virtual ~Animal();
        void setType(std::string type);
        std::string getType() const;
        virtual void makeSound() const;
};

// virtual : To ensure a function call makeSound() depends on the type of the object(Cat or Dog) 
// if we don't use virtual, the function makeSound() will be called from the Animal class

#endif
