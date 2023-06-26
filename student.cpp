#include <iostream>
#include <array>
#include "student.h"

using namespace std;

// constructor
Student::Student(string id, string first, string last, string newEmail, int newAge, array<int, 3> days, DegreeProgram program)
{
    studentID = id;
    firstName = first;
    lastName = last;
    email = newEmail;
    age = newAge;
    daysToComplete = days;
    degreeProgram = program;
};

// getters

string Student::getStudentID()
{
    return studentID;
};
string Student::getFirstName()
{
    return firstName;
};
string Student::getLastName()
{
    return lastName;
};
string Student::getEmail()
{
    return email;
};
int Student::getAge()
{
    return age;
}
array<int, 3> Student::getDays()
{
    return daysToComplete;
};
DegreeProgram Student::getDegreeProgram()
{
    return degreeProgram;
};

void Student::setID(string id)
{
    studentID = id;
};
void Student::setFirstName(string first)
{
    firstName = first;
};
void Student::setLastName(string last)
{
    lastName = last;
};
void Student::setEmail(string newEmail)
{
    email = newEmail;
};
void Student::setAge(int newAge)
{
    age = newAge;
};
void Student::setDaysToComplete(array<int, 3> &newArray)
{
    daysToComplete = newArray;
};
void Student::setDegreeProgram(DegreeProgram program)
{
    degreeProgram = program;
};
void Student::printStudent()
{
    std::cout << studentID << std::endl;
    std::cout << firstName << std::endl;
    std::cout << lastName << std::endl;
    std::cout << email << std::endl;
    std::cout << age << std::endl;
    for (int i = 0; i < 3; i++)
    {

        std::cout << daysToComplete[i] << std::endl;
    }
    std::cout << degreeProgram << std::endl;
    std::cout << "----------------------" << std::endl;
}