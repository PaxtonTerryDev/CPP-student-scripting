#include <iostream>
#include <string>
#include <sstream>
#include <array>
#include "student.h"

class Roster
{
private:
    Student *createStudent(std::string studentData);

public:
    int classSize = 5;
    Student **classRosterArray;

    Student **getClassRosterArray() const;
    void setClassRosterArray(Student **newArray, int newSize);
    void createRoster(std::array<std::string, 5> studentData);
    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(std::string studentID);
    void printAll();
    void printAverageDaysInCourse(std::string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);

    // constructor
    Roster(std::array<std::string, 5> studentData);

    // destructor
    ~Roster();
};
