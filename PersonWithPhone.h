#pragma once
#include "Person.h"
class PersonWithPhone : public Person
{

public:

	PersonWithPhone();

	virtual ~PersonWithPhone() override;

	PersonWithPhone(std::string name, std::string address, std::string telephoneNumber);


#pragma region FUNCTIONS

public:

	virtual void Print() const override; // Print the current person object

	std::string GetNumber() { return _TelephoneNumber; }; // Return the phone number of the current person object

protected:

private:

#pragma endregion

#pragma region VARIABLES

public:

protected:

private:

	std::string _TelephoneNumber; // Person phone number

#pragma endregion



};

