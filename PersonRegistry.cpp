// Lab3PersonRegistry.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PersonReg.h"
#include "Person.h"
#include "PersonWithPhone.h"
#include <locale>

int main()
{
    std::locale::global(std::locale("Swedish")); 
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Flag that's checking for memory leaks

#pragma region UPPG 1

    std::cout << "UPPG 1: " << std::endl;

    PersonReg peopleRegistry(12);
    PersonReg* peopleRegistryPointer = &peopleRegistry;

    Person olle1("olle", "Rosengård");
    Person olle2("olle", "Limhamn");
    Person olle3("olle", "Lund");
    Person olle4("olle", "Möllan");
    Person olle5("olle", "Trelleborg");


    peopleRegistryPointer->Add(&olle1);
    peopleRegistryPointer->Add(&olle2);
    peopleRegistryPointer->Add(&olle3);
    peopleRegistryPointer->Add(&olle4);
    peopleRegistryPointer->Add(&olle5);

    Person person;
    Person* personPointer = &person;
    peopleRegistryPointer->Print();
    std::cout << "---------------------" << std::endl;

    personPointer->ReadReg(*peopleRegistryPointer, "PersonExample.txt");

    peopleRegistryPointer->RemoveEntry(&olle3);


    peopleRegistryPointer->Print();

    std::cout << "---------------------" << std::endl;

    peopleRegistryPointer->Add(&olle3);
    peopleRegistryPointer->Print();


    std::cout << "----------------------" << std::endl;
#pragma endregion
   
#pragma region UPPG 2

    std::cout << "UPPG 2: " << std::endl;

    Person* x1 = peopleRegistryPointer->SearchFreely("olle", nullptr); //x1 blir första träffen
    Person* x2 = peopleRegistryPointer->SearchFreely("olle", x1); //x2 blir andra träffen
    Person* x3 = peopleRegistryPointer->SearchFreely("olle", x2); //x3 blir tredje träffen
    Person* y2 = peopleRegistryPointer->SearchFreely("olle", x1); //y2 blir andra träffen

    std::cout << "x1: " << x1 << std::endl;
    std::cout << "x2: " << x2 << std::endl;
    std::cout << "x3: " << x3 << std::endl;
    std::cout << "y2: " << y2 << std::endl;

    std::cout << "-----------------------" << std::endl;

#pragma endregion

#pragma region UPPG 3

    std::cout << "UPPG 3: " << std::endl;
    Person* personWithNumber = new PersonWithPhone("Arn", "Industrigatan", "070 509 29 21");
    personWithNumber->Print();

    std::cout << "--------------------------" << std::endl;

    peopleRegistryPointer->Add(personWithNumber);
    peopleRegistryPointer->Print();

    delete personWithNumber;

#pragma endregion

#pragma region Lab 4

    peopleRegistryPointer->SortPersonReg();

#pragma endregion


}


