#include "PersonWithPhone.h"

PersonWithPhone::PersonWithPhone()
{
}

PersonWithPhone::~PersonWithPhone()
{
}

PersonWithPhone::PersonWithPhone(std::string name, std::string address, std::string telephoneNumber)
{
	this->Name = name;
	this->Address = address;
	this->_TelephoneNumber = telephoneNumber;
}



void PersonWithPhone::Print() const
{
	std::cout << "Person Name: " << Name << " Person Address: " << Address << " Person Phone Number: " << _TelephoneNumber << std::endl;

}
