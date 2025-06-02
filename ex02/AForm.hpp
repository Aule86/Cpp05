#ifndef AAForm_HPP
#define AAForm_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string   name;
        bool  isSigned;
        const int gradeToSign;
        const int gradeToExecute;

    public:
        
       

};

std::ostream &operator<<(std::ostream &os, AForm &f);

#endif