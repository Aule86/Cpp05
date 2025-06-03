/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule86 <aule86@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:08:33 by aszamora          #+#    #+#             */
/*   Updated: 2025/06/03 12:35:55 by aule86           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

class ShrubberyCreationForm::FileError : public std::exception
{
	public:
		virtual const char* what() const throw() { return ("Cannot open file\n"); }
};

std::string ShrubberyCreationForm::asciiTree =
"       _-_\n"	
"    /~~   ~~\\\n"
" /~~         ~~\\\n"
"{               }\n"
" \\  _-     -_  /\n"
"   ~  \\\\ //  ~\n"
"_- -   | | _- _\n"
"  _ -  | |   -_\n"
;

ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
	: AForm("ShrubberyCreationForm", 145, 137), target (target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &src )
    : AForm(src.name,src.gradeToSign, src.gradeToExecute)
{
    *this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &src )
{
    if (this != &src) {
        this->target = src.target;
		this->asciiTree = src.asciiTree;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{

}

std::string ShrubberyCreationForm::getTarget( void )
{
	return (this->target);
}

void ShrubberyCreationForm::execute( Bureaucrat const &executor ) const 
{
    AForm::execute(executor);
    try {
        writeFile();
        std::cout << executor.getName() << " successfully executed " << this->getName() << " form." << std::endl;
    } catch(std::exception &e) {
        std::cout << e.what() << " to execute" << std::endl;
    }
}

void ShrubberyCreationForm::writeFile( void ) const
{
    std::ofstream outFile;
    std::string filename = target + "_shrubbery";
	outFile.open(filename.c_str());
	
	if (!outFile.is_open())
		throw ShrubberyCreationForm::FileError();
	outFile << asciiTree;
    outFile.close();
}