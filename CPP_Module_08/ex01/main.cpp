#include "Span.hpp"

int main( void )
{
    Span s(1000000) ;

    s.fill() ;
    std::cout << "Min span " << s.shortestSpan() << std::endl ;
    std::cout << "Max span " << s.longestSpan() << std::endl ;
    // s.print() ;

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    return (0) ;
}
