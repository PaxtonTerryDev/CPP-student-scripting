#include <iostream>
#include <string>
#include <sstream>
#include "roster.h"

Student createStudent(const std::string &input)
{
    std::stringstream ss(input);
    std::string token;

    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string email;
    int age;
    int daysToComplete[3];
    DegreeProgram program;

    std::getline(ss, studentID, ',');
    std::getline(ss, firstName, ',');
    std::getline(ss, lastName, ',');
    std::getline(ss, email, ',');
    std::getline(ss, token, ',');
    age = std::stoi(token);
    std::getline(ss, token, ',');
    daysToComplete[0] = std::stoi(token);
    std::getline(ss, token, ',');
    daysToComplete[1] = std::stoi(token);
    std::getline(ss, token, ',');
    daysToComplete[2] = std::stoi(token);
    std::getline(ss, token, ',');
    if (token == "SECURITY")
    {
        program = SECURITY;
    }
    else if (token == "NETWORK")
    {
        program = NETWORK;
    }
    else if (token == "SOFTWARE")
    {
        program = SOFTWARE;
    }

    // Create and return a new Student object
    return Student(studentID, firstName, lastName, email, age, daysToComplete, program);
}

int main()
{
    const std::string studentDataArray[] = {
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Paxton,Terry,dter125@wgu.com,27,20,25,30,SOFTWARE"};

    std::cout << "Course Title: C867 - Scripting and Programming Applications" << std::endl;
    std::cout << "Language Used: C++" << std::endl;
    std::cout << "WGU Student ID: YOUR_STUDENT_ID" << std::endl;
    std::cout << "Name: YOUR_NAME" << std::endl;

    Roster classRoster(5);

    for (const std::string &studentData : studentDataArray)
    {
        Student student = createStudent(studentData);
        classRoster.add(student);
    }

    classRoster.printAll();
    classRoster.printInvalidEmails();

    for (int i = 0; i < classRoster.getSize(); i++)
    {
        classRoster.printAverageDaysInCourse(classRoster.getStudentByID(std::to_string(i + 1))->getID());
    }

    classRoster.printByDegreeProgram(SOFTWARE);

    classRoster.remove("A3");

    classRoster.printAll();

    classRoster.remove("A3");

    return 0;
}
