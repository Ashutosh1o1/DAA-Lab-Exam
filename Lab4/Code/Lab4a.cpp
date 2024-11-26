#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// Function to read course choices from CSV file
vector<vector<int>> readCourseChoicesFromCSV(const string &filename)
{
    ifstream file(filename);
    vector<vector<int>> courseChoices;
    string line, value;

    // Skip the header line
    getline(file, line);

    // Read each line (student's course choices)
    while (getline(file, line))
    {
        vector<int> studentChoices;
        stringstream ss(line);

        // Ignore the first column (StudentID)
        getline(ss, value, ',');

        // Read each course choice and store in the vector
        while (getline(ss, value, ','))
        {
            studentChoices.push_back(stoi(value)); // Convert string to integer
            
        }

        // Add this student's course choices to the overall list
        courseChoices.push_back(studentChoices);
    }

    file.close();
    return courseChoices;
}

int main()
{
    // Read course choices from the CSV file
    string filename = "students_course_choices.csv";
    vector<vector<int>> courseChoices = readCourseChoicesFromCSV(filename);

    // Print the course choices for each student
    for (int i = 0; i < courseChoices.size(); i++)
    {
        cout << "Student " << i + 1 << " course choices: ";
        for (int j = 0; j < courseChoices[i].size(); j++)
        {
            cout << courseChoices[i][j] << " ";
        }
        cout << endl;
    }

    // You can now pass a specific student's course choices to the inversion count function
        // Example: vector<int> student1Choices = courseChoices[0]; // Course choices of Student 1

        return 0;
}