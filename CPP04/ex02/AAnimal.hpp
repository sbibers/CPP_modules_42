/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:22:30 by salam             #+#    #+#             */
/*   Updated: 2025/03/10 16:11:48 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

// abstract class, class has at least one pure virtual function, pure virtual function executed by child class

class AAnimal
{
    protected:
        std::string type;
    public:
        AAnimal();
        AAnimal(std::string type);
        AAnimal(const AAnimal &copy);
        AAnimal &operator=(const AAnimal &obj);
        virtual ~AAnimal();
        void setType(std::string type);
        std::string getType() const;
        virtual void makeSound() const = 0; // pure virtual function
};

// virtual : To ensure a function call makeSound() depends on the type of the object(Cat or Dog) 
// if we don't use virtual, the function makeSound() will be called from the Animal class

#endif
