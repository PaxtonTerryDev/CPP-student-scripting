#include <iostream>
#include <string>
#include <sstream>
#include "roster.h"

int main()
{
    std::cout << std::endl;
    const std::array<std::string, 5> studentData = {
        "A1,John,Smith,John1989@g mail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Paxton,Terry,P@G.com,27,10,15,20,SOFTWARE"};

    // Create instance of Roster
    // The Roster constructor creates a new Student Object for each item in the studentData array
    Roster classRoster(studentData);

    classRoster.printAll();
    classRoster.printInvalidEmails();

    for (int i = 0; i < classRoster.classSize; i++)
    {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    };
    std::cout << "-----------------------" << std::endl;

    std::cout << "Printing By Degree Program: " << std::endl;
    classRoster.printByDegreeProgram(SOFTWARE);

    std::cout << "Removing Student A3... " << std::endl;
    classRoster.remove("A3");

    std::cout << "Updated Roster " << std::endl;
    classRoster.printAll();

    std::cout << "Removing Student A3... " << std::endl;
    classRoster.remove("A3");

    return 0;
}
