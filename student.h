#include <iostream>
#include <cstdlib>
#include <vector>
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
    vector<int> daysToComplete;
    DegreeProgram degreeProgram;

public:
    // constructor
    Student(string id, string first, string last, string email, int age, vector<int> days, DegreeProgram program);

    // getters
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    vector<int> getDays();
    DegreeProgram getDegreeProgram();
    // setters
    void setID(string id);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setDaysToComplete(vector<int> &newVector);
    void setDegreeProgram(DegreeProgram newProgram);

    // other
    void printStudent();
};