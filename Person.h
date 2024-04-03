#pragma once

#include <iostream>

class PersonReg;

class Person
{

public:

	Person(); 

	virtual ~Person();

	Person(std::string name, std::string address);

#pragma region Functions

public:

	virtual void Print() const; // Print the current person object

	bool ReadReg(PersonReg& reg, std::string fileName); // Read people values from .txt file and add them to registry

	bool BHasName(); // Check if the current person has a name

	std::string GetName() { return Name; }; // Return the name of the current person object
	std::string GetAddress() { return Address; }; // Return the address of the current Person object

#pragma region Lab 4

	bool operator>(const Person& that) const;
	
		
	

#pragma endregion


protected:

private:

#pragma endregion

#pragma region Variables

public:

protected:

	 std::string Name; // Person name

	 std::string Address; // Person address

private:

	

#pragma endregion


};

