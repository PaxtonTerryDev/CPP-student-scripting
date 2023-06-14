#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <student.h>

using namespace std;

vector<string> splitString(const string &inputString)
{
    vector<string> result;
    string token;

    size_t start = 0;
    size_t end = inputString.find(',');

    while (end != string::npos)
    {
        token = inputString.substr(start, end - start);
        result.push_back(token);

        start = end + 1;
        end = inputString.find(',', start);
    }

    token = inputString.substr(start);
    result.push_back(token);

    // Combine "30", "35", "40" into a separate array
    vector<string> additionalValues;
    additionalValues.push_back(result[5]);
    additionalValues.push_back(result[6]);
    additionalValues.push_back(result[7]);

    // Remove the elements "30", "35", "40"
    result.erase(result.begin() + 5, result.begin() + 8);

    // Insert the combined array before "SECURITY"
    auto it = find(result.begin(), result.end(), string("SECURITY"));
    result.insert(it, additionalValues.begin(), additionalValues.end());

    return result;
}

void createStudent(vector<string> studentData)
{
}

int main()
{
    string input = "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY";
    vector<string> output = splitString(input);

    // Printing the split strings
    for (const auto &str : output)
    {
        cout << str << endl;
    }

    return 0;
}
