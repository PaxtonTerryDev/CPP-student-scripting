#include <iostream>
#include <string>
#include <sstream>
#include "roster.h"

int main()
{
    const std::array<std::string, 5> studentData = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Paxton,Terry,P@G.com,27,10,15,20,SOFTWARE"};

    Roster newRoster;
    newRoster.createRoster(studentData);
    newRoster.add("A5", "Pingus", "Bingus", "Pingus@Bingus.com", 27, 15, 20, 25, SECURITY);

    return 0;
}
