#include "Person.h"
#include "PersonReg.h"
#include <iostream>
#include <fstream>
#include <string>

Person::Person()
{
}

Person::~Person()
{
}

Person::Person(const std::string name, std::string address)
{

	this->Name = name;
	this->Address = address;

}


void Person::Print() const
{
	std::cout << "Person Name: " << Name << " Person Address: " << Address << std::endl;
}

bool Person::ReadReg(PersonReg& reg, std::string fileName)
{
    std::string line; // The line in the file that's currently being read
    std::ifstream myfile(fileName); // The file

    if (myfile.is_open()) // Check if the file is open
    {
        while (std::getline(myfile, line))
        {
            std::string name = line; // Assigns the name to the first line the getline encounters
            
            if (getline(myfile, line))  // Check for the next line in the .txt file
            {
                std::string address = line; // Assign address to the next line that was found
                
                reg.AddTest(name, address); // Add the people in the .txt file to the registry
                
            }
        }
        myfile.close();
        return true;
    }
    else {
        std::cout << "Unable to open file" << std::endl;
        return false;
    }

    return false; 
}

bool Person::BHasName()
{
    if (Name.empty()) // If Name = ""
    {
        return false;
    }
    else if (!Name.empty())
    {
        return true;
    }
    return false;
}

bool Person::operator>(const Person& that) const
{
    return this->Address > that.Address;
}



