
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    Intern intern;
    Bureaucrat bureaucrat("bureaucrat", 1);

    AForm*   form1 = intern.makeForm("ShrubberyCreationForm", "form1");
    AForm*   form2 = intern.makeForm("RobotomyRequestForm", "form2");
    AForm*   form3 = intern.makeForm("PresidentialPardonForm", "form3");


    std::cout << *form1 << std::endl;
    std::cout << *form2 << std::endl;
    std::cout << *form3 << std::endl;
    bureaucrat.signForm(*form1);
    bureaucrat.signForm(*form2);
    bureaucrat.signForm(*form3);
    bureaucrat.executeForm(*form1);
    bureaucrat.executeForm(*form2);
    bureaucrat.executeForm(*form3);

try
{
    AForm*  form4 = intern.makeForm("InvalidForm", "form4");
    std::cout << *form4 << std::endl;
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';

}

    std::cout << "-------------------" << std::endl;
    delete form1;
    delete form2;
    delete form3;
    return 0;
}
