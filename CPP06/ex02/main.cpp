/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.amman>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:21:55 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/25 15:29:57 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    int random_number = rand() % 3;
    if (random_number == 0)
        return (new A);
    else if (random_number == 1)
        return (new B);
    else
        return (new C);
}

void identify(Base *p) // dynamic casting with pointers if does not cast return NULL.
{
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
}

void identify(Base &p)// dynamic casting with refernces if does not cast return throw (try, catch).
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A\n";
    }
    catch (std::exception &e)
    {}
    try
    {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B\n";
    }
    catch (std::exception &e)
    {}
    try
    {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C\n";
    }
    catch (std::exception &e)
    {}
}

int main()
{
    srand(time(NULL));
    Base *ptr = generate();
    Base &ref = *ptr;
    identify(ptr);
    identify(ref);
    delete ptr;
    return (0);
}
