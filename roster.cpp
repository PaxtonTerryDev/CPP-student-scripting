#include <iostream>
#include <vector>
#include "roster.h"

// Constructor
Roster::Roster(int maxSize)
{
    this->maxSize = maxSize;
}

// Destructor
Roster::~Roster()
{
    for (Student *student : classRosterArray)
    {
        delete student;
    }
}

// Getter for roster size
int Roster::getSize() const
{
    return classRosterArray.size();
}

// Getter for a student by ID
Student *Roster::getStudentByID(const std::string &studentID) const
{
    for (Student *student : classRosterArray)
    {
        if (student->getID() == studentID)
        {
            return student;
        }
    }
    return nullptr; // Student not found
}

// Add a student to the roster
void Roster::add(const Student &student)
{
    if (classRosterArray.size() < maxSize)
    {
        // Create a new dynamically allocated Student object
        Student *newStudent = new Student(student);
        classRosterArray.push_back(newStudent);
    }
    else
    {
        std::cout << "Error: Roster is already full. Cannot add more students." << std::endl;
    }
}

// Remove a student from the roster by ID
void Roster::remove(const std::string &studentID)
{
    bool found = false;
    for (auto it = classRosterArray.begin(); it != classRosterArray.end(); ++it)
    {
        if ((*it)->getID() == studentID)
        {
            delete *it;
            classRosterArray.erase(it);
            found = true;
            break;
        }
    }
    if (!found)
    {
        std::cout << "Error: Student with ID " << studentID << " was not found." << std::endl;
    }
}

// Print all student data
void Roster::printAll() const
{
    for (const Student *student : classRosterArray)
    {
        student->printInfo();
    }
}

// Print invalid email addresses
void Roster::printInvalidEmails() const
{
    for (const Student *student : classRosterArray)
    {
        std::string email = student->getEmail();
        if (email.find('@') == std::string::npos || email.find('.') == std::string::npos || email.find(' ') != std::string::npos)
        {
            std::cout << "Invalid email: " << email << std::endl;
        }
    }
}

// Print average number of days in the course for a student
void Roster::printAverageDaysInCourse(const std::string &studentID) const
{
    Student *student = getStudentByID(studentID);
    if (student)
    {
        const int *daysToComplete = student->getDaysToComplete();
        int sum = daysToComplete[0] + daysToComplete[1] + daysToComplete[2];
        double average = static_cast<double>(sum) / 3;
        std::cout << "Average days in course for student " << studentID << ": " << average << std::endl;
    }
    else
    {
        std::cout << "Error: Student with ID " << studentID << " was not found." << std::endl;
    }
}

// Print student information by degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const
{
    for (const Student *student : classRosterArray)
    {
        if (student->getProgram() == degreeProgram)
        {
            student->printInfo();
        }
    }
}
