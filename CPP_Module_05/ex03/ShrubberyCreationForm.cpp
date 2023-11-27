#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("Shrubbery", 145, 137), target("tree_shrubbery")
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm(target, 145, 137),  target(target + "_shrubbery")
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& form )
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
    AForm::operator=(form) ;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other )
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
    AForm::operator=(other) ;
    return (*this) ;
}

void    ShrubberyCreationForm::execute( Bureaucrat const& executor ) const
{
    AForm::checkExecution(executor) ;
    try
    {
        std::ofstream outfile(target) ;
        outfile
        << "              _{\\ _{\\{\\/}/}/}__" << std::endl
        << "             {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl
        << "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _" << std::endl
        << "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl
        << "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}" << std::endl
        << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl
        << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl
        << "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}" << std::endl
        << "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl
        << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl
        << "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl
        << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" << std::endl
        << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << std::endl
        << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl
        << "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << std::endl
        << "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}" << std::endl
        << "             {/{\\{\\{\\/}/}{\\{\\\\}/}" << std::endl
        << "              {){/ {\\/}{\\/} \\}\\}" << std::endl
        << "              (_)  \\.-'.-/" << std::endl
        << "          __...--- |'-.-'| --...__" << std::endl
        << "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__" << std::endl
        << " -\"    ' .  . '    |.'-._| '  . .  '   jro" << std::endl
        << " .  '-  '    .--'  | '-.'|    .  '  . '" << std::endl
        << "          ' ..     |'-_.-|" << std::endl
        << "  .  '  .       _.-|-._ -|-._  .  '  ." << std::endl
        << "              .'   |'- .-|   '." << std::endl
        << "  ..-'   ' .  '.   `-._.-�   .'  '  - ." << std::endl
        << "   .-' '        '-._______.-'     '  ." << std::endl
        << "        .      ~," << std::endl
        << "    .       .   |\\   .    ' '-." << std::endl
        << "    ___________/  \\____________" << std::endl
        << "   /  Why is it, when you want \\" << std::endl
        << "  |  something, it is so damn   |" << std::endl
        << "  |    much work to get it?     |" << std::endl
        << "   \\___________________________/" << std::endl ;
        outfile.close() ;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}