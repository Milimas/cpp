#include "Harl.hpp"

Harl::Harl( void )
{
    std::cout << "harl Object: Created" << std::endl ;
}

Harl::~Harl( void )
{
    std::cout << "harl Object: Destroyed" << std::endl ;
}

void Harl::debug( void ) const
{
    std::cout << "[DEBUG]: " ;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl ;
}

void Harl::info( void ) const
{
    std::cout << "[INFO]: " ;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl ;
}

void Harl::warning( void ) const
{
    std::cout << "[WARNING]: " ;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl ;
}

void Harl::error( void ) const
{
    std::cout << "[ERROR]: " ;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl ;
}

void Harl::complain( const std::string level ) const
{
    FnPtr map[4];
    std::string lvls[4] = {"DEBUG","INFO","WARNING","ERROR"};

    map[0] = &Harl::debug;
    map[1] = &Harl::info;
    map[2] = &Harl::warning;
    map[3] = &Harl::error;

    for (int i = 0; i < 4; i++)
    {
        if (lvls[i] == level)
            (this->*(map[i]))();
    }
}