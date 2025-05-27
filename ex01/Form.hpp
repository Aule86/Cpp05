#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string   name;
        bool                isSigned;
        const int           signGrade;
        const int           execGrade;
    public:
        Form(void);
        Form( std::string name, int signGrade, int execGrade );
        Form(const Form &src);
        Form &operator=(const Form &src);
        ~Form(void);
        std::string getName(void)const;
        bool getIsSigned( void );
		void setIsSigned( bool state );
		int getSignGrade( void ) const;
		int getExecGrade( void ) const;
		void beSigned(const Bureaucrat& bureaucrat);
        class   GradeTooHighException: public std::exception
        {
            public:
                const char *what() const throw();
        };
        class   GradeTooLowException: public std::exception
        {
            public:
                const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, Form &f);

#endif