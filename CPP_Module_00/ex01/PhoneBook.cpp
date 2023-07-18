#include "PhoneBook.hpp"

int PhoneBook::size = 0;
int PhoneBook::oldindex = 0;

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
    std::cout << "At Index: " << oldindex << std::endl ;
    std::cout << std::setw(20) << std::setfill('-') << "-" << std::endl ;
    std::cout << std::setfill(' ') ;

    do
    {
        std::cout << "First Name: " ;
        std::getline(std::cin, firstName) ;
        if (!isValid(firstName))
            firstName.clear() ;
    }
    while (firstName.empty() && !std::cin.eof()) ;

    do
    {
        std::cout << "Last Name: " ;
        std::getline(std::cin, lastName) ;
        if (!isValid(lastName))
            lastName.clear() ;
    }
    while (lastName.empty() && !std::cin.eof()) ;

    do
    {
        std::cout << "nickname: " ;
        std::getline(std::cin, nickname) ;
        if (!isValid(nickname))
            nickname.clear() ;
    }
    while (nickname.empty() && !std::cin.eof()) ;

    do
    {
        std::cout << "Phone Number: " ;
        std::getline(std::cin, phoneNumber) ;
        if (!isPhoneNumber(phoneNumber))
            phoneNumber.clear() ;
    }
    while (phoneNumber.empty() && !std::cin.eof()) ;

    do
    {
        std::cout << "Darket Secret: " ;
        std::getline(std::cin, darketSecret) ;
        if (!isValid(darketSecret))
            darketSecret.clear() ;
    }
    while (darketSecret.empty() && !std::cin.eof()) ;

    this->contacts[this->oldindex] = Contact(firstName, lastName, nickname, phoneNumber, darketSecret) ;
    this->oldindex = (this->oldindex + 1) % 8 ;
    if (this->size <= 7)
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
    do
    {
        std::cout << "Index: " ;
        std::getline(std::cin, index) ;
        if (index == "EXIT")
            return ;
        if (std::cin.eof())
            break ;
        if (!isPhoneNumber(index))
            std::cout << "Not a valid index" << std::endl ;
        else if (toIndex(index) < 0 || toIndex(index) >= this->size || !this->size)
        {
            if (!index.empty())
                std::cout << "Index out of range" << std::endl ;
            index.clear() ;
        }
    }
    while (index.empty() || !isPhoneNumber(index));

    if (!std::cin.eof())
    {
        std::system("clear") ;
        std::cout << " Index: "  << index ;
        std::cout << " First Name: " << this->contacts[toIndex(index)].getFirstName() << std::endl ;
        std::cout << " Last Name: " << this->contacts[toIndex(index)].getLastName() << std::endl ;
        std::cout << " Nickname: " << this->contacts[toIndex(index)].getNickname()  << std::endl ;
        std::cout << " Phone Number: " << this->contacts[toIndex(index)].getPhoneNumber()  << std::endl ;
        std::cout << " Darket Secret " << this->contacts[toIndex(index)].getDarketSecret()  << std::endl ;
    }
    
    std::cout << std::endl << "Press any key to continue..." << std::endl ;
    std::system("read") ;
}

bool PhoneBook::isValid( std::string str )
{
    for (int i = 0 ; str[i] ; i++)
    {
        if (!isprint(str[i]))
            return (false) ;
    }
    return (true) ;
}

bool PhoneBook::isPhoneNumber( std::string str )
{
    for (int i = 0 ; str[i] ; i++)
    {
        if (!isnumber(str[i]))
            return (false) ;
    }
    return (true) ;
} 

int PhoneBook::toIndex( std::string str )
{
    if (str.empty())
        return (-1) ;
    return (str[0] - '0') ;
}
