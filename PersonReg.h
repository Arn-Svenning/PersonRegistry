#pragma once

#include <iostream>


class Person;

class PersonReg
{

public:

	PersonReg(int maxSize);

	~PersonReg();

#pragma region FUNCTIONS

public:

	void Print() const; // Print all the people in the registry

	void Empty(); // Remove all people in the registry

	void RemoveEntry(Person* ptrToRemove); // Remove a specific person from the registry

	Person* SearchName(const std::string& name) const; // Search for a person in the registry and return the pointer

	Person* SearchFreely(const std::string& searchFor, Person* startOnNextPerson) const; // Search for a person in the registry from a specific index in the registry

	bool Add(const Person* const person);  // Add a Person in the registry based on an already defined person object

	bool AddTest(const std::string& name, const std::string& address); // Dynamically create People objects and add to registry




#pragma region LAB 4

	Person* Begin();
	Person* End();

	static bool Greater(const Person& x, const Person& y);

	void SortPersonReg();

#pragma endregion


	

protected:

private:


#pragma endregion


#pragma region Variables

public:

protected:

private:

	Person* _People;

	int _MaxSize;

	int _NumberOfPeople;


#pragma endregion

};

