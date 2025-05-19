#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>


class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    
    public:
        Bureaucrat(const std:: string &name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        const std::string& getName() const;
        int getGrade() const;
        void incrementGrade ();
        void decrementGrade();
        class GradeTooLowException;
        class GradeTooHighException;

        
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif