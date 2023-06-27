#include <iostream>
#include "roster.h"

// constructor
Roster::Roster(std::array<std::string, 5> studentData)
{
    int arraySize = studentData.size();
    classRosterArray = nullptr; // Initialize classRosterArray with null pointer
    createRoster(studentData);
}

// destructor
Roster::~Roster()
{
    // Release memory for each student object
    for (int i = 0; i < classSize; i++)
    {
        delete classRosterArray[i];
    }

    // Release memory for the classRosterArray
    delete[] classRosterArray;
}
// private member function to parse student info from provided string array and create student object
Student *Roster::createStudent(std::string studentData)
{
    std::string studentID;
    std::string first;
    std::string last;
    std::string email;
    int age;
    std::array<int, 3> days;
    DegreeProgram program;
    std::stringstream ss(studentData);
    std::string item;

    // Parse and assign each comma-separated value
    std::getline(ss, studentID, ',');
    std::getline(ss, first, ',');
    std::getline(ss, last, ',');
    std::getline(ss, email, ',');
    ss >> age;
    ss.ignore();
    for (int j = 0; j < 3; j++)
    {
        ss >> days[j];
        ss.ignore();
    }
    std::string programStr;
    std::getline(ss, programStr);

    // Convert program string to enum
    if (programStr == "SECURITY")
    {
        program = SECURITY;
    }
    else if (programStr == "NETWORK")
    {
        program = NETWORK;
    }
    else if (programStr == "SOFTWARE")
    {
        program = SOFTWARE;
    }

    Student *newStudent = new Student(studentID, first, last, email, age, days, program);
    return newStudent;
}
// Getter
Student **Roster::getClassRosterArray() const
{
    return classRosterArray;
}
// Setter
void Roster::setClassRosterArray(Student **newArray, int newSize)
{
    if (classRosterArray != nullptr)
    {
        delete[] classRosterArray;
    }

    classRosterArray = newArray;
    classSize = newSize;
}

// Methods
void Roster::createRoster(std::array<std::string, 5> studentData)
{
    Student **newArray = new Student *[classSize];

    for (int i = 0; i < classSize; i++)
    {
        Student *newStudent = createStudent(studentData[i]);
        newArray[i] = newStudent;
    }
    setClassRosterArray(newArray, classSize);
}

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    std::array<int, 3> days = {daysInCourse1, daysInCourse2, daysInCourse3};

    Student *newStudent = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);

    std::cout << "New Student Added. ID: " << studentID << std::endl;

    int newSize = classSize + 1;
    Student **newArray = new Student *[newSize];
    for (int i = 0; i < classSize; i++)
    {
        newArray[i] = classRosterArray[i];
    }
    newArray[classSize] = newStudent;
    setClassRosterArray(newArray, newSize);

    std::cout << "-----------------------" << std::endl;
}
void Roster::remove(std::string studentID)
{
    bool found = false;
    for (int i = 0; i < classSize; i++)
    {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID)
        {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
            found = true;
            break;
        }
    }

    if (found)
    {
        std::cout << "Student with ID " << studentID << " has been removed from the roster." << std::endl;
    }
    else
    {
        std::cout << "Student with ID " << studentID << " was not found in the roster." << std::endl;
    }
    std::cout << "-----------------------" << std::endl;
}

void Roster::printAll()
{
    std::cout << "Current Class Roster" << std::endl;
    std::cout << "-----------------------" << std::endl;

    for (int i = 0; i < classSize; i++)
    {
        if (classRosterArray[i] != nullptr)
        {
            classRosterArray[i]->print();
        }
    }
    std::cout << "-----------------------" << std::endl;
}

void Roster::printAverageDaysInCourse(std::string studentID)
{
    bool found = false;
    for (int i = 0; i < classSize; i++)
    {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID)
        {
            found = true;
            int averageDays = classRosterArray[i]->calculateAverageDaysInCourse();
            std::cout << "Student ID: " << studentID << " - Average days in course: " << averageDays << std::endl;
            break;
        }
    }

    if (!found)
    {
        std::cout << "Student not found." << std::endl;
    }
}

void Roster::printInvalidEmails()
{
    std::cout << "Invalid Email Addresses" << std::endl;
    std::cout << "-----------------------" << std::endl;
    bool foundInvalid = false;

    for (int i = 0; i < classSize; i++)
    {
        if (classRosterArray[i] != nullptr)
        {
            std::string email = classRosterArray[i]->getEmail();

            // Check if email is valid
            if (email.find('@') == std::string::npos || email.find('.') == std::string::npos || email.find(' ') != std::string::npos)
            {
                foundInvalid = true;
                std::cout << "Invalid email: " << email << std::endl;
            }
        }
    }

    if (!foundInvalid)
    {
        std::cout << "No invalid email addresses found." << std::endl;
    }
    std::cout << "-----------------------" << std::endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    bool foundStudents = false;

    for (int i = 0; i < classSize; i++)
    {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegreeProgram() == degreeProgram)
        {
            foundStudents = true;
            classRosterArray[i]->print();
        }
    }

    if (!foundStudents)
    {
        std::cout << "No students found for the specified degree program." << std::endl;
    }
    std::cout << "-----------------------" << std::endl;
}