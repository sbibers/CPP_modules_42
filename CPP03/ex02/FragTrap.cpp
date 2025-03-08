#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() // default constructor
{
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) // parameterized constructor
{
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
    std::cout << "FragTrap parameterized constructor called for " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap &frag) : ClapTrap(frag) // copy constructor
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = frag;
}

FragTrap &FragTrap::operator=(const FragTrap &frag) // assignment operator
{
    std::cout << "FragTrap assignation operator called" << std::endl;
    if (this != &frag)
    {
        ClapTrap::operator=(frag);
    }
    return *this;
}

FragTrap::~FragTrap() // destructor
{
    std::cout << "FragTrap destructor called for " << this->getName() << std::endl;
}

void FragTrap::attack(const std::string& target) // attack function
{
    if (this->getEnergyPoints() <= 0)
    {
        std::cout << "FragTrap " << this->getName() << " has no energy points left to attack!" << std::endl;
        return;
    }
    if (this->getHitPoints() <= 0)
    {
        std::cout << "FragTrap " << this->getName() << " is already dead and cannot attack!" << std::endl;
        return;
    }
    std::cout << "FragTrap " << this->getName() << " attacks " << target 
              << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
    this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->getName() << " requests a high five!" << std::endl;
}
