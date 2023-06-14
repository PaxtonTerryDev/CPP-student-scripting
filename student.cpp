#include "student.h"
#include <iostream>

// Constructor
Student::Student(int id, const std::string &first, const std::string &last,
                 const std::string &emailAddress, int studentAge, const int days[3],
                 DegreeProgram studentProgram)
{
    studentID = id;
    firstName = first;
    lastName = last;
    email = emailAddress;
    age = studentAge;
    for (int i = 0; i < 3; i++)
    {
        daysToComplete[i] = days[i];
    }
    program = studentProgram;
}

// Getters

int Student::getID() const
{
    return studentID;
}

std::string Student::getFirst() const
{
    return firstName;
}

std::string Student::getLast() const
{
    return lastName;
}

std::string Student::getEmail() const
{
    return email;
}

int Student::getAge() const
{
    return age;
}

const int *Student::getDaysToComplete() const
{
    return daysToComplete;
}

DegreeProgram Student::getProgram() const
{
    return program;
}

// Setters

void Student::setID(int id)
{
    studentID = id;
}

void Student::setFirst(const std::string &first)
{
    firstName = first;
}

void Student::setLast(const std::string &last)
{
    lastName = last;
}

void Student::setEmail(const std::string &newEmail)
{
    email = newEmail;
}

void Student::setAge(int newAge)
{
    age = newAge;
}

void Student::setDaysToComplete(const int values[3])
{
    for (int i = 0; i < 3; i++)
    {
        daysToComplete[i] = values[i];
    }
}

void Student::setProgram(DegreeProgram newProgram)
{
    program = newProgram;
}

// Example member function
void Student::printInfo() const
{
    std::cout << "Student ID: " << studentID << std::endl;
    std::cout << "Name: " << firstName << " " << lastName << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Days to Complete: ";
    for (int i = 0; i < 3; i++)
    {
        std::cout << daysToComplete[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Program: " << static_cast<int>(program) << std::endl;
}
