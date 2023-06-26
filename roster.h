#include <iostream>
#include <string>
#include <sstream>
#include <array>
#include "student.h"

class Roster
{
private:
    std::array<Student *, 5> classRosterArray;

    Student createStudent(std::string studentData)
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
        Student newStudent(studentID, first, last, email, age, days, program);
        newStudent.printStudent();
        return newStudent;
    }

public:
    void createRoster(std::array<string, 5> studentData)
    {

        for (int i = 0; i < 5; i++)
        {
            Student newStudent = createStudent(studentData[i]);
            classRosterArray[i] = &newStudent;
        }
    }
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
    {
        // Create array from daysInCourse parameters
        std::array<int, 3> daysArray;
        daysArray[0] = daysInCourse1;
        daysArray[1] = daysInCourse2;
        daysArray[2] = daysInCourse3;

        // Create new student object from parameters
        Student *newStudent = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeProgram);

        // Create a new array with one more index
        std::array<Student *, classRosterArray.size() + 1> newRosterArray;

        // Copy the old array into the new array
        for (int i = 0; i < classRosterArray.size(); i++)
        {
            newRosterArray[i] = classRosterArray[i];
        }

        // Add the new student to the new array
        newRosterArray[classRosterArray.size()] = newStudent;
        newStudent->printStudent();

        // Destroy the old array (deallocate memory)
        for (int i = 0; i < classRosterArray.size(); i++)
        {
            delete classRosterArray[i];
        }

        // Assign the new array to classRosterArray
        classRosterArray = newRosterArray;
    }
};