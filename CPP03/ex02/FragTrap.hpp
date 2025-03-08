#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap();                           // default constructor
    FragTrap(std::string name);           // parameterized constructor
    FragTrap(const FragTrap &frag);       // copy constructor
    FragTrap &operator=(const FragTrap &frag); // assignment operator
    ~FragTrap();                          // destructor
    void attack(const std::string& target);  // override attack function
    void highFivesGuys(void);              // special ability
};

#endif 