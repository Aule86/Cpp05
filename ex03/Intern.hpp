#ifndef INTERN_HPP
#define INTERN_HPP

#include <cstring>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		class CannotMakeForm;
		Intern();
		Intern(const Intern &src);
		Intern &operator=(const Intern &src);
		~Intern();

		AForm* makeForm(std::string name, std::string target);

	private:
		static const std::string forms[3];
		typedef AForm* (Intern::*FormCreator)(const std::string &target) const;

		static const FormCreator formCreators[3];

		AForm* createShrubberyCreationForm(const std::string &target) const;
		AForm* createRobotomyRequestForm(const std::string &target) const;
		AForm* createPresidentialPardonForm(const std::string &target) const;
};

#endif