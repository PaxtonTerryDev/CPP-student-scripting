#include <iostream>
#include <cstdlib>
#include "degree.h"

using namespace std;

class Student
{

private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int daysToComplete[3];
    DegreeProgram program;

public:
    // Getters
    string getID() const
    {
        return studentID;
    };
    string getFirst() const
    {
        return firstName;
    };
    string getLast() const
    {
        return lastName;
    };
    string getEmail() const
    {
        return email;
    };
    int getAge() const
    {
        return age;
    };
    const int *getDaysToComplete() const
    {
        return daysToComplete;
    }
    DegreeProgram getProgram() const
    {
        return program;
    };

    // Setters
    void setID(const string &id)
    {
        studentID = id;
    };
    void setFirst(const string &first)
    {
        firstName = first;
    };
    void setLast(const string &last)
    {
        lastName = last;
    };
    void setEmail(const string &newEmail)
    {
        email = newEmail;
    };
    void setAge(const int newAge)
    {
        age = newAge;
    };
    void setDaysToComplete(const int values[3])
    {
        for (int i = 0; i < 3; i++)
        {
            daysToComplete[i] = values[i];
        }
    };
    void setProgram(DegreeProgram newProgram)
    {
        program = newProgram;
    };

    // Constructor
    Student(const string &id, const string &first, const string &last,
            const string &emailAddress, int studentAge, const int days[3],
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
    // member function - print out student info
    void printInfo() const
    {
        cout << "Student ID: " << studentID << endl;
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "Email: " << email << endl;
        cout << "Age: " << age << endl;
        cout << "Days to Complete: ";
        for (int i = 0; i < 3; i++)
        {
            cout << daysToComplete[i] << " ";
        }
        cout << endl;
        cout << "Program: " << static_cast<int>(program) << endl;
    }
};