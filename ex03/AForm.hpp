#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    protected:
        const std::string   name;
        bool  isSigned;
        const int gradeToSign;
        const int gradeToExecute;

    public:
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		virtual ~AForm();

		const std::string& getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat& bureaucrat);
		class GradeTooLowException;
		class GradeTooHighException;
		class FormNotSignedException;
		virtual void execute( Bureaucrat const &executor ) const = 0;

};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif