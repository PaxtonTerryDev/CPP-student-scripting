#include <iostream>
#include <string>
#include <sstream>
#include <array>
#include "student.h"

class Roster
{
private:
    std::array<Student *, 5> classRosterArray;

public:
    void createRoster(const std::string studentData[], int numStudents)
    {
        for (int i = 0; i < numStudents; i++)
        {
            std::string id;
            std::string first;
            std::string last;
            std::string email;
            int age;
            int days[3];
            DegreeProgram program;
            std::stringstream ss(studentData[i]);
            std::string item;

            ;

            // Parse and assign each comma-separated value
            std::getline(ss, id, ',');
            std::getline(ss, first, ',');
            std::getline(ss, last, ',');
            std::getline(ss, email, ',');
            ss >> age;
            ss.ignore();
            int classDays[3];
            for (int j = 0; j < 3; j++)
            {
                ss >> classDays[j];
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

            Student *student = new Student(id, first, last, email, age, classDays, program)

                classRosterArray[i] = student;

            // Print the assigned values for the current student
            student->printInfo();
        }
    }
};