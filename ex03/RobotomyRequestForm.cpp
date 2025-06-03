/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule86 <aule86@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:07:40 by aszamora          #+#    #+#             */
/*   Updated: 2025/06/03 12:27:13 by aule86           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
	
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src.name, src.gradeToSign, src.gradeToExecute)
{
	*this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src) {
		this->target = src.target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	
}

std::string RobotomyRequestForm::getTarget(void)
{
	return (this->target);
}

void RobotomyRequestForm::robotomize(void) const
{
	std::cout << "Drilling noises..." << std::endl;
	srand(static_cast<unsigned int>(std::time(0)));
	int random = rand();
	if (random % 2 == 0) {
		std::cout << this->target << " has been robotomized successfully." << std::endl;
	} else {

		std::cout << "Robotomization of " << this->target << " has failed." << std::endl;
	}
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	try {
		robotomize();
		std::cout << executor.getName() << " successfully executed " << this->getName() << " form." << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << " to execute" << std::endl;
	}
}