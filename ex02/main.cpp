
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	
    // Crear un formulario de creación de arbustos
    ShrubberyCreationForm form("arboles");
    std::cout << form << std::endl;

    // Crear un burócrata
    Bureaucrat David("David", 10);
    std::cout << David << std::endl;

    // Firmar el formulario
    try {
        David.signForm(form);
        form.beSigned(David);
        std::cout << form;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    //ejecutar el formulario
    try {
        David.executeForm(form);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    // Crear un burócrata que no pueda firmar el formulario o ejecutarlo un nuevo form
    Bureaucrat John("John", 146); // John tiene un grado demasiado bajo para firmar el formulario
    ShrubberyCreationForm form2("arboles2");
    std::cout << form2 << std::endl;
    try {
        John.signForm(form2);
        form2.beSigned(John);
        std::cout << form2;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        John.executeForm(form2);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    //crear un burocrata para firmar el RobotomyCreationForm
//con nivel para hacerlo

    Bureaucrat John2("John2", 10); // John tiene un grado demasiado bajo para firmar el formulario
    RobotomyRequestForm form3("robot");
    std::cout << form3 << std::endl;
    try {
        John2.signForm(form3);
        form3.beSigned(John2);
        std::cout << form3;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        John2.executeForm(form3);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    //crear un burocrata para firmar el PresidentialPardonForm
//con nivel para hacerlo

    Bureaucrat John3("John3", 10); // John tiene un grado demasiado bajo para firmar el formulario
    PresidentialPardonForm form4("pardon");
    std::cout << form4 << std::endl;
    try {
        John3.signForm(form4);
        form4.beSigned(John3);
        std::cout << form4;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        John3.executeForm(form4);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    //ahora un burocrata con nivel para firmar el PresidentialPardonForm y para ejecutarlo
    Bureaucrat John4("John4", 1); 
    PresidentialPardonForm form5("pardon2");
    std::cout << form5 << std::endl;
    try {
        John4.signForm(form5);
        form5.beSigned(John4);
        std::cout << form5;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        John4.executeForm(form5);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}