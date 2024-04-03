#include "PersonReg.h"
#include "Person.h"
#include <cstdlib>
#include <algorithm>

PersonReg::PersonReg(int maxSize)
{

	std::srand(std::time(0));

	this->_MaxSize = maxSize;

	_NumberOfPeople = 0;

	_People = new Person[_MaxSize];
}

PersonReg::~PersonReg()
{	
	delete[] _People; 
}

void PersonReg::Print() const
{
	for (Person* ptr = _People; ptr != _People + _MaxSize; ++ptr) // Loop through the array with ptr, loop till end of _People array,
	{                                                             // ptr points to +1 memory address in the array

		ptr->Print(); // Call print from each element in the _People array
	}
}

void PersonReg::Empty()
{
	for (Person* ptr = _People; ptr != _People + _MaxSize; ++ptr) 
	{

		if (ptr != nullptr)
		{
			
			*ptr = Person(); // Assign all people to empty person object
			_NumberOfPeople = 0;
		}
	}
}

void PersonReg::RemoveEntry(Person* ptrToRemove)
{
	
	for (Person* ptr = _People; ptr != _People + _MaxSize; ++ptr)
	{
		if (ptr->GetName() == ptrToRemove->GetName() && ptr->GetAddress() == ptrToRemove->GetAddress())
		{
			*ptr = Person(); // Assign the found person to empty person object
			
			--_NumberOfPeople;

			return;
		}
		
	}
	
}


Person* PersonReg::SearchName(const std::string& name) const
{
	for (Person* ptr = _People; ptr != _People + _MaxSize; ++ptr) {


		if (ptr->GetName() == name)
		{
			std::cout << "The searched for person is: " <<"Name: " << ptr->GetName() << " Address: " << ptr->GetAddress() << " Pointer is: " << ptr << std::endl;
			return ptr; 
			
		}							
	}
	return nullptr;
}

Person* PersonReg::SearchFreely(const std::string& searchFor, Person* startOnNextPerson) const
{
	Person* startPtr = (startOnNextPerson == nullptr) ? _People : startOnNextPerson + 1; // If startOnNextPerson is null, assign startPtr to first index in _People array
																						 // If startOnNextPerson is valid assign it to index after that person
	for (Person* ptr = startPtr; ptr != _People + _MaxSize; ++ptr)
	{
		if (ptr->GetName().find(searchFor) != std::string::npos)
		{
			std::cout << ptr << std::endl;
			return ptr;
		}
	}

	return nullptr;
}

bool PersonReg::Add(const Person* const person)
{
	for (Person* ptr = _People; ptr != _People + _MaxSize; ++ptr)
	{
		if (!ptr->BHasName())
		{
			if (person != nullptr && _People != nullptr)
			{
				if (_NumberOfPeople < _MaxSize)
				{
					*ptr = *person;

					_NumberOfPeople++;

					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
	return false;
	
}

bool PersonReg::AddTest(const std::string& name, const std::string& address)
{
	for (Person* ptr = _People; ptr != _People + _MaxSize; ++ptr)
	{
		if (!ptr->BHasName())
		{
			if (_People != nullptr)
			{
				if (_NumberOfPeople < _MaxSize)
				{
					*ptr = Person(name, address);

					_NumberOfPeople++;

					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}

	
	return false;
}

void PersonReg::SortPersonReg()
{
	std::cout << "-------------" << std::endl;
	std::random_shuffle(_People, _People + _MaxSize);

	std::cout << "Unsorted: " << std::endl;
	Print();
	std::cout << "-------------" << std::endl;

	std::sort(Begin(), End(), Greater);

	std::cout << "Sorted: " << std::endl;
	Print();
	std::cout << "-------------" << std::endl;
}

Person* PersonReg::Begin()
{
	return _People;
}

Person* PersonReg::End()
{
	return _People + _NumberOfPeople;
}

bool PersonReg::Greater(const Person& x, const Person& y)
{
	return x > y;
}



