/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.amman>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:37:42 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/24 16:45:42 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>

// uintptr_t : unsigned integer pointer, store the vlaue of any pointer.
// reinterpret_cast : to convert a pointer of some data type into a pointer of another data type.

class Serialization
{
    private:
        Serialization();
        ~Serialization();
        Serialization(const Serialization &);
        Serialization &operator=(const Serialization &);
    public:
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};

#endif
