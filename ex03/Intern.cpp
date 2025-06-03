#include "Intern.hpp"

class Intern::CannotMakeForm : public std::exception
{
	public:
		virtual const char* what() const throw() { return("Cannot make form with given name"); }
};

const std::string Intern::forms[3] =
{
    "ShrubberyCreationForm",
    "RobotomyRequestForm",
    "PresidentialPardonForm"
};

const Intern::FormCreator Intern::formCreators[3] =
{
    &Intern::createShrubberyCreationForm,
    &Intern::createRobotomyRequestForm,
    &Intern::createPresidentialPardonForm
};

Intern::Intern()
{

}

Intern::Intern(const Intern &src)
{
    *this = src;
}

Intern &Intern::operator=(const Intern &src)
{
    if (this == &src)
        return (*this);
    return (*this);
}

Intern::~Intern()
{

}

AForm* Intern::makeForm(std::string name, std::string target)
{
    for (int idx = 0; idx < 3; ++idx) {
        if (this->forms[idx] == name) {
            std::cout << "Intern creates " << this->forms[idx] << std::endl;
            return (this->*formCreators[idx])(target);
        }
    }
    throw Intern::CannotMakeForm();
}

AForm* Intern::createShrubberyCreationForm(const std::string &target) const
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string &target) const
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string &target) const
{
    return new PresidentialPardonForm(target);
}