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

std::string degreeProgramToString(DegreeProgram degreeProgram)
{
    switch (degreeProgram)
    {
    case DegreeProgram::SECURITY:
        return "Security";
    case DegreeProgram::NETWORK:
        return "Network";
    case DegreeProgram::SOFTWARE:
        return "Software";
    default:
        return "Unknown";
    }
}

int Student::calculateAverageDaysInCourse()
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += daysToComplete[i];
    }
    return sum / 3;
}

void Student::print()
{
    std::cout << "Student ID: " << studentID << "\tFirst Name: " << firstName
              << "\tLast Name: " << lastName << "\tAge: " << age
              << "\tdaysInCourse: {" << daysToComplete[0] << ", " << daysToComplete[1] << ", " << daysToComplete[2] << "}"
              << "\tDegree Program: " << degreeProgramToString(degreeProgram) << std::endl;
}
