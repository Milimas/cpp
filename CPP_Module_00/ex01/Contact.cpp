#include "Contact.hpp"


Contact::Contact( std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darketSecret)
{
    this->firstName = firstName ;
    this->lastName = lastName ;
    this->nickname = nickname ;
    this->phoneNumber = phoneNumber ;
    this->darketSecret = darketSecret ;
}

Contact::~Contact()
{
}

Contact::Contact()
{
}

std::string Contact::getFirstName()
{
    return this->firstName ;
}
std::string Contact::getLastName()
{
    return this->lastName ;
}
std::string Contact::getNickname()
{
    return this->nickname ;
}

std::string Contact::getPhoneNumber()
{
    return this->phoneNumber ;
}

std::string Contact::getDarketSecret()
{
    return this->darketSecret ;
}
