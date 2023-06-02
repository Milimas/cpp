#include "PhoneBook.hpp"

int PhoneBook::size = 0;

PhoneBook::PhoneBook(): contacts()
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add(  )
{
    std::string firstName ;
    std::string lastName ;
    std::string nickname ;
    std::string phoneNumber ;
    std::string darketSecret ;

    std::cout << "First Name: " ;
    std::cin >> firstName ;

    std::cout << "Last Name: " ;
    std::cin >> lastName ;

    std::cout << "nickname: " ;
    std::cin >> nickname ;

    std::cout << "Phone Number: " ;
    std::cin >> phoneNumber ;

    std::cout << "Darket Secret: " ;
    std::cin >> darketSecret ;

    this->contacts[this->size] = Contact(firstName, lastName, nickname, phoneNumber, darketSecret) ;
    if (this->size < 8)
        this->size++ ;
    std::cout << std::endl << "Contact created successfully." << std::endl << "Press any key to continue..." << std::endl ;
    
    std::system("read") ;
}

std::string PhoneBook::trim( std::string str )
{
    if (str.length() > 10)
        return str.substr(0, 10).replace(9, 1, ".") ;
    return str ;
}

void PhoneBook::search()
{
    std::cout << "|" << std::setw(44) << std::setfill('-') << "|" << std::endl ;
    std::cout.fill(' ');
    for (int i = 0; i < 8; i++)
    {
        std::cout << "|" ;
        std::cout << std::right << std::setw(10) << i ;
        std::cout << "|" ;
        std::cout  << std::setw(10) << this->trim(this->contacts[i].getFirstName()) ;
        std::cout << "|" ;
        std::cout << std::setw(10) << this->trim(this->contacts[i].getLastName()) ;
        std::cout << "|" ;
        std::cout << std::setw(10) << this->trim(this->contacts[i].getNickname()) ;
        std::cout << "|" ;
        std::cout << std::endl ;
    }
    std::cout << "|" << std::setw(44) << std::setfill('-') << "|" << std::endl ;

    std::string index;
    std::cin >> index ;
    if (stoi(index) < 0 || stoi(index) > this->size)
    {
        std::cout << "Index out of range" << std::endl ;
        return ;
    }
    std::cout << "| "  << index ;
    std::cout << " | " << this->contacts[stoi(index)].getFirstName() ;
    std::cout << " | " << this->contacts[stoi(index)].getLastName() ;
    std::cout << " | " << this->contacts[stoi(index)].getNickname()  << " |" << std::endl ;
    std::cout << "Press any key to continue..." << std::endl ;
    
    std::system("read") ;
}
