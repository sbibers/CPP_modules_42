/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:10:39 by sbibers           #+#    #+#             */
/*   Updated: 2025/02/26 11:41:19 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
    private:
        std :: string type;
    public:
        Weapon();
        Weapon(std::string type);
        void setType(std::string type);
        std::string const& getType() const;
};

#endif
