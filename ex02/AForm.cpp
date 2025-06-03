/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule86 <aule86@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:46:27 by aszamora          #+#    #+#             */
/*   Updated: 2025/06/03 13:06:44 by aule86           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class AForm::GradeTooHighException : public std::exception {
public:
	const char* what() const throw(){
		return "Grade is too high!";
	};
};

class AForm::GradeTooLowException : public std::exception {
public:
	const char* what() const throw(){
		return "Grade is too low!";
	};
};

class AForm::FormNotSignedException : public std::exception {
public:
	const char* what() const throw(){
		return "Form is not signed!";
	};
};


AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    } else if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

AForm::~AForm()
{
	
}

const std::string& AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign) {
        throw GradeTooLowException();
    }
    isSigned = true;
}
void AForm::execute( Bureaucrat const &executor ) const
{
	if (!this->isSigned)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute()) {
		std::cout << executor.getName() << " couldn’t execute " << this->getName() << " because ";
		throw AForm::GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Form " << form.getName() << ", isSigned: " << form.getIsSigned()
       << ", gradeToSign: " << form.getGradeToSign()
       << ", gradeToExecute: " << form.getGradeToExecute() << std::endl;
    return os;
}

