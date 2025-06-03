/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule86 <aule86@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:28:19 by aszamora          #+#    #+#             */
/*   Updated: 2025/06/03 13:10:39 by aule86           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Grade Too High Exception");
}
const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Grade Too Low Exception");
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << name << " has been destroyed." << std::endl;
}

const std::string &Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
        throw GradeTooHighException();
    grade--;
	std::cout << "Bureaucrat " << name << " has been demoted to grade " << grade << std::endl;
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
        throw GradeTooLowException();
    grade++;
    std::cout << "Bureaucrat " << name << "has been promoted to grade" << grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
	if (grade < 1)
		throw GradeTooHighException();
    else if (grade > 150) 
		throw GradeTooLowException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other) 
		return *this;
	grade = other.grade;
	return *this;
}

void Bureaucrat::signForm(AForm& form) 
{
    try 
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    } 
    catch (std::exception& e) 
    {
        std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void    Bureaucrat::executeForm( AForm const &form )
{
    if (this->getGrade() <= form.getGradeToExecute() && form.getIsSigned()) {
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
        form.execute(*this);
    }
    else {
        std::cout << this->getName() << " couldn’t execute " << form.getName() << " because ";
        throw Bureaucrat::GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << " " ;
    return os;
}