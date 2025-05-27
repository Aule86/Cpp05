#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{

    try {
        Bureaucrat David("David", 10);
        Form form("sheet", 10, 5);
        std::cout << std::boolalpha << form << "\n";

        try {
            form.beSigned(David);
            std::cout << David;
            David.signForm(form);
            std::cout << "\n" << form;
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        
        // Añadir un burócrata que no pueda firmar el formulario
        Bureaucrat John("John", 11); // John tiene un grado demasiado bajo para firmar el formulario

        try {
            John.signForm(form);
            form.beSigned(John);
            std::cout << "\n" << form;
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}