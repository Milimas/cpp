#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{
    try
    {
        Bureaucrat  amine = Bureaucrat("amine", 151) ;
        Form        cdi = Form("cdi", 1, 1) ;
        std::cout << amine << std::endl ;
        amine.signForm(cdi) ;
        std::cout << cdi.getName() << (cdi.getIsSigned() ? " is Signed" : "is Not Signed") << std::endl ;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n' ;
    }
    return (0) ;
}
