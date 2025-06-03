/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule86 <aule86@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:06:59 by aszamora          #+#    #+#             */
/*   Updated: 2025/06/03 12:23:25 by aule86           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string target ): AForm("PresidentialPardonForm", 25, 5), target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &src ): AForm(src)
{
	*this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &src )
{
	if (this != &src) {
		this->target = src.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	
}

std::string PresidentialPardonForm::getTarget( void )
{
	return this->target;
}

void PresidentialPardonForm::Zaphod( void ) const
{
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

void PresidentialPardonForm::execute( Bureaucrat const &executor ) const
{
	AForm::execute(executor);
	this->Zaphod();
}