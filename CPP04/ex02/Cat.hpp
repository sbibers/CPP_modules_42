/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:25:50 by salam             #+#    #+#             */
/*   Updated: 2025/03/10 16:15:05 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
    private:
        Brain *brain;
    public:
        Cat();
        Cat(std::string type);
        Cat(const Cat &copy);
        Cat &operator=(const Cat &obj);
        ~Cat();
        void makeSound() const;
        void setBrain(Brain *brain);
        Brain *getBrain() const;
};

#endif
