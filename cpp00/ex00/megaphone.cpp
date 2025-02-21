/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:59:45 by salam             #+#    #+#             */
/*   Updated: 2025/02/21 22:18:29 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std :: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std :: endl;
        return (1);
    }
    argv = &argv[1];
    for (size_t i = 0; argv[i]; i++)
    {
        for (size_t j = 0; argv[i][j]; j++)
        {
            std :: cout << (char)toupper(argv[i][j]);
        }
    }
    std :: cout << std :: endl;
    return (0);
}
