/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.amman>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:41:10 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/25 15:15:46 by sbibers          ###   ########.fr       */
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
