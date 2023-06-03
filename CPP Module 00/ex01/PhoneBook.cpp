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

    std::system("clear") ;

    std::cout << "Add new Contact: " << std::endl ;
    std::cout << std::setw(20) << std::setfill('-') << "-" << std::endl ;
    std::cout << std::setfill(' ') ;

    while (firstName.empty() && !std::cin.eof())
    {
        std::cout << "First Name: " ;
        std::getline(std::cin, firstName) ;
    }

    while (lastName.empty() && !std::cin.eof())
    {
        std::cout << "Last Name: " ;
        std::cin >> lastName ;
    }

    while (nickname.empty() && !std::cin.eof())
    {
        std::cout << "nickname: " ;
        std::cin >> nickname ;
    }

    while (phoneNumber.empty() && !std::cin.eof())
    {
        std::cout << "Phone Number: " ;
        std::cin >> phoneNumber ;
    }

    while (darketSecret.empty() && !std::cin.eof())
    {
        std::cout << "Darket Secret: " ;
        std::cin >> darketSecret ;
    }
    this->contacts[this->size] = Contact(firstName, lastName, nickname, phoneNumber, darketSecret) ;
    if (this->size < 7)
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
    std::system("clear") ;

    std::cout << "Search Contact: " << std::endl ;
    std::cout << std::setw(20) << std::setfill('-') << "-" << std::endl ;
    std::cout << std::setfill(' ') ;

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
    while (index.empty() || std::cin.eof() || index.find_first_not_of("0123456789") != std::string::npos)
    {
        std::cout << std::endl << "Index: " ;
        std::getline(std::cin, index) ;
    }

    if (stoi(index) < 0 || stoi(index) > this->size || !this->size)
    {
        std::cout << "Index out of range" << std::endl ;
    }
    else
    {
        std::system("clear") ;
        std::cout << " Index: "  << index ;
        std::cout << " First Name: " << this->contacts[stoi(index)].getFirstName() << std::endl ;
        std::cout << " Last Name: " << this->contacts[stoi(index)].getLastName() << std::endl ;
        std::cout << " Nickname: " << this->contacts[stoi(index)].getNickname()  << std::endl ;
        std::cout << " Phone Number: " << this->contacts[stoi(index)].getPhoneNumber()  << std::endl ;
        std::cout << " Darket Secret " << this->contacts[stoi(index)].getDarketSecret()  << std::endl ;
    }
    
    std::cout << std::endl << "Press any key to continue..." << std::endl ;
    std::system("read") ;
}
