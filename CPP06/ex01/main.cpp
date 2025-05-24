/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.amman>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:41:10 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/24 17:08:34 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main()
{
    Data my_data;
    my_data.age = 20;
    my_data.name = "salam";
    std::cout << "original data address : " << &my_data << std::endl;
    uintptr_t raw = Serialization::serialize(&my_data);
    /* raw (unsigned int), this number save decimal number of the address of the my_data,
    it will print the same number of the address but in a dicemal not in a hexa. */
    std::cout << "Serialization value : " << raw << std::endl;
    Data *new_ptr = Serialization::deserialize(raw);
    std::cout << "Serialization Data process : " << new_ptr << std::endl;
    if (new_ptr == &my_data)
        std::cout << "Success, Pointers are equal!!!\n";
    else
        std::cout << "Fail, Pointers are not equal!!!\n";
    std::cout << "Deserialize Data : age = " << new_ptr->age << ", name = " << new_ptr->name << std::endl;
    return (0);
}
