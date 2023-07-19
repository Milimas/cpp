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

void Harl::complain( std::string level ) const
{
    std::string lvls[5] = {"", "DEBUG","INFO","WARNING","ERROR"};
    int i = -1;
    for (i = 0; i < 5 && lvls[i] != level; i++) ;

    FnPtr map[5];

    map[0] = &Harl::error ;
    map[1] = &Harl::debug ;
    map[2] = &Harl::info ;
    map[3] = &Harl::warning ;
    map[4] = &Harl::error ;

    (this->*(map[i]))();
}