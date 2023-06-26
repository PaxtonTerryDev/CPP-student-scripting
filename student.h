#include <iostream>
#include <cstdlib>
#include <array>
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
    array<int, 3> daysToComplete;
    DegreeProgram degreeProgram;

public:
    // constructor
    Student(string id, string first, string last, string email, int age, array<int, 3> days, DegreeProgram program);

    // getters
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    array<int, 3> getDays();
    DegreeProgram getDegreeProgram();
    // setters
    void setID(string id);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setDaysToComplete(array<int, 3> &newArray);
    void setDegreeProgram(DegreeProgram newProgram);

    // other
    void printStudent();
};