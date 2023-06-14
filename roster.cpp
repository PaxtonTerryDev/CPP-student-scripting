#include "roster.h"
#include <iostream>

// Constructor
Roster::Roster()
{
    // Initialize the classRosterArray with null pointers
    for (int i = 0; i < MAX_STUDENTS; i++)
    {
        classRosterArray[i] = nullptr;
    }
}

// Destructor
Roster::~Roster()
{
    // Free the memory allocated for each student object
    for (int i = 0; i < MAX_STUDENTS; i++)
    {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}

// Add a student to the roster
void Roster::add(const std::string &studentID, const std::string &firstName, const std::string &lastName,
                 const std::string &emailAddress, int age, int daysInCourse1, int daysInCourse2,
                 int daysInCourse3, DegreeProgram degreeProgram)
{
    // Create a new student object
    Student *student = new Student(studentID, firstName, lastName, emailAddress, age,
                                   daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);

    // Find the first available spot in the classRosterArray
    int index = -1;
    for (int i = 0; i < MAX_STUDENTS; i++)
    {
        if (classRosterArray[i] == nullptr)
        {
            index = i;
            break;
        }
    }

    // If there is an available spot, add the student to the roster
    if (index != -1)
    {
        classRosterArray[index] = student;
        std::cout << "Student added to the roster." << std::endl;
    }
    else
    {
        std::cout << "Roster is full. Student could not be added." << std::endl;
    }
}

// Remove a student from the roster by student ID
void Roster::remove(const std::string &studentID)
{
    bool found = false;

    for (int i = 0; i < MAX_STUDENTS; i++)
    {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getID() == studentID)
        {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
            found = true;
            std::cout << "Student with ID " << studentID << " removed from the roster." << std::endl;
            break;
        }
    }

    if (!found)
    {
        std::cout << "Student with ID " << studentID << " not found in the roster." << std::endl;
    }
}

// Print all student data
void Roster::printAll() const
{
    for (int i = 0; i < MAX_STUDENTS; i++)
    {
        if (classRosterArray[i] != nullptr)
        {
            classRosterArray[i]->printInfo();
        }
    }
}

// Print average number of days in the courses for a student
void Roster::printAverageDaysInCourse(const std::string &studentID) const
{
    bool found = false;

    for (int i = 0; i < MAX_STUDENTS; i++)
    {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getID() == studentID)
        {
            const int *daysToComplete = classRosterArray[i]->getDaysToComplete();
            int sum =
