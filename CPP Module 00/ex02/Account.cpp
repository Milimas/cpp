#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
    return (Account::_nbAccounts) ;
}

int	Account::getTotalAmount( void )
{
    return (Account::_totalAmount) ;
}

int	Account::getNbDeposits( void )
{
    return (Account::_totalNbDeposits) ;
}

int	Account::getNbWithdrawals( void )
{
    return (Account::_totalNbWithdrawals) ;
}

void	Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp() ;
    std::cout << "accounts:" << Account::getNbAccounts() << ";" ;
    std::cout << "total:" << Account::getTotalAmount() << ";" ;
    std::cout << "deposits:" << Account::getNbDeposits() << ";" ;
    std::cout << "withdrawals:" << Account::getNbWithdrawals() ;
    std::cout << std::endl ;
}

Account::Account( int initial_deposit )
{
    this->_accountIndex = Account::getNbAccounts() ;
    this->_amount = initial_deposit ;
    this->_nbWithdrawals = 0 ;
    this->_nbDeposits = 0 ;
    Account::_nbAccounts++ ;
    Account::_totalAmount += this->_amount ;

    Account::_displayTimestamp() ;
    std::cout << "index:" << this->_accountIndex << ";" ;
    std::cout << "amount:" << this->_amount << ";" ;
    std::cout << "created" ;
    std::cout << std::endl ;
}


Account::~Account( void )
{
    Account::_nbAccounts-- ;
    Account::_displayTimestamp() ;
    std::cout << "index:" << this->_accountIndex << ";" ;
    std::cout << "amount:" << this->_amount << ";" ;
    std::cout << "closed" ;
    std::cout << std::endl ;
}

void    Account::_displayTimestamp( void )
{
    // you need to display time stamp here like this [19920104_091532]
    std::time_t now ;
    std::time(&now);
    std::tm*    tm = std::localtime(&now);
    std::cout << "[" << tm->tm_year + 1900 ;
    std::cout << std::setw(2) << std::setfill('0') << tm->tm_mon ;
    std::cout << std::setw(2) << std::setfill('0') << tm->tm_mday << "_" ;
    std::cout << std::setw(2) << std::setfill('0') << tm->tm_hour ;
    std::cout << std::setw(2) << std::setfill('0') << tm->tm_min ;
    std::cout << std::setw(2) << std::setfill('0') << tm->tm_sec << "] " ;
}


void	Account::makeDeposit( int deposit )
{
    Account::_displayTimestamp() ;
    std::cout << "index:" << this->_accountIndex << ";" ;
    std::cout << "p_amount:" << this->_amount << ";" ;

    this->_amount += deposit ;
    std::cout << "deposit:" << deposit << ";" ;
    this->_nbDeposits++ ;
    Account::_totalAmount += deposit ;
    Account::_totalNbDeposits++ ;
    
    std::cout << "amount:" << this->_amount << ";" ;
    std::cout << "nb_deposits:" << this->_nbDeposits ;
    std::cout << std::endl ;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    Account::_displayTimestamp() ;
    std::cout << "index:" << this->_accountIndex << ";" ;
    std::cout << "p_amount:" << this->_amount << ";" ;
    if (withdrawal > this->_amount)
    {
        std::cout << "withdrawal:refused" << std::endl ;
        return (0) ;
    }
    this->_amount -= withdrawal ;
    this->_nbWithdrawals++ ;
    Account::_totalAmount -= withdrawal ;
    Account::_totalNbWithdrawals++ ;

    std::cout << "withdrawal:" << withdrawal << ";" ;
    std::cout << "amount:" << this->_amount << ";" ;
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals ;
    std::cout << std::endl ;

    return (1) ;
}
int		Account::checkAmount( void ) const
{
    return (this->_amount) ;
}

void	Account::displayStatus( void ) const
{
    Account::_displayTimestamp() ;
    std::cout << "index:" << this->_accountIndex << ";" ;
    std::cout << "amount:" << this->_amount << ";" ;
    std::cout << "deposits:" << this->_nbDeposits << ";" ;
    std::cout << "withdrawals:" << this->_nbWithdrawals ;
    std::cout << std::endl ;
}