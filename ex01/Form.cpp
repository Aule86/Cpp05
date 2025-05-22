/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:46:27 by aszamora          #+#    #+#             */
/*   Updated: 2025/05/20 11:54:35 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char	*Form::GradeTooHighException::what() const throw()
{
	return("Form grade Too High Exception");
}
const char	*Form::GradeTooLowException::what() const throw()
{
	return("Form grade Too Low Exception");
}

Form::Form (void) : name ("Unnamed"), isSigned (false), signGrade(0), execGrade(0) 
{
    
}

Form::Form(std::string n, int gts, int gte) : name (n), isSigned (false), signGrade(gts), execGrade(gte)
{
    if (this->signGrade < 1 || this->execGrade < 1)
        throw Form::GradeTooHighException();
    if (this->signGrade > 150 || this->execGrade > 150)
        throw Form::GradeTooLowException();
    
}