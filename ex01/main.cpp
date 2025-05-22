#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat Pablo("Pablo", 2);
        std::cout << Pablo << std::endl;

        Pablo.incrementGrade();
        std::cout << Pablo << std::endl;

        Pablo.incrementGrade();
         } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        Bureaucrat Paloma("Paloma", 150);
        std::cout << Paloma << std::endl;

        Paloma.decrementGrade();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;

}