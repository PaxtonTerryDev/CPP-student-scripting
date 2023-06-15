#pragma once

#include <string>
#include <vector>
#include "student.h"

class Roster
{
private:
    std::vector<Student *> classRosterArray;
    int maxSize;

public:
    // Constructor
    Roster(int maxSize);

    // Destructor
    ~Roster();

    // Getter for roster size
    int getSize() const;

    // Getter for a student by ID
    Student *getStudentByID(const std::string &studentID) const;

    // Add a student to the roster
    void add(const Student &student);

    // Remove a student from the roster by ID
    void remove(const std::string &studentID);

    // Print all student data
    void printAll() const;

    // Print invalid email addresses
    void printInvalidEmails() const;

    // Print average number of days in the course for a student
    void printAverageDaysInCourse(const std::string &studentID) const;

    // Print student information by degree program
    void printByDegreeProgram(DegreeProgram degreeProgram) const;
};
