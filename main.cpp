#include <iostream>
#include <string>
#include <sstream>
#include "roster.h"

enum DegreeProgram
{
    SECURITY,
    NETWORK,
    SOFTWARE
};

int main()
{
    const std::string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Paxton,Terry,P@G.com,27,10,15,20,SOFTWARE"};

    const int numStudents = sizeof(studentData) / sizeof(studentData[0]);

    Roster roster;
    roster.createRoster(studentData, numStudents);

    return 0;
}
