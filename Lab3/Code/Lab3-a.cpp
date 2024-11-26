#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

string generateRandomName()
{
    vector<string> firstNames = {"George", "John", "Thomas",
                                 "Abraham", "Theodore", "Franklin",
                                 "John", "Ronald", "Barack", "Joe"};
    vector<string> lastNames = {"Washington", "Adams", "Jefferson",
                                "Lincoln", "Roosevelt", "Roosevelt",
                                "Kennedy", "Reagan", "Obama", "Biden"};

    string firstName = firstNames[rand() % firstNames.size()];
    string lastName = lastNames[rand() % lastNames.size()];

    return firstName + " " + lastName;
}

int generateRandomSalary()
{
    return rand() % 90001 + 18000; // Random salary between 10,000 and
    100, 000
}

int main()
{
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    ofstream file("input5.csv");

    if (!file.is_open())
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // Write the header
    file << "Name,Salary\n";

    // Generate and write 2000 records
    for (int i = 0; i < 2000; ++i)
    {
        string name = generateRandomName();
        int salary = generateRandomSalary();
        file << name << "," << salary << "\n";
    }

    file.close();
    cout << "CSV file created successfully!" << endl;

    return 0;
}