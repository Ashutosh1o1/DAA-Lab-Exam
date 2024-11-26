#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// Function to merge two halves and count inversions
int mergeAndCount(vector<int> &arr, int left, int mid, int right)
{
    int count = 0;
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    // Merge the two halves while counting inversions
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            // Since arr[i] > arr[j], there are mid - i inversions
            count += (mid - i + 1);
        }
    }

    // Copy remaining elements from both halves
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    // Copy the sorted subarray back to the original array
    for (i = left, k = 0; i <= right; i++, k++)
    {
        arr[i] = temp[k];
    }

    return count;
}

// Function to perform merge sort and count inversions
int mergeSortAndCount(vector<int> &arr, int left, int right)
{
    if (left >= right)
    {
        return 0;
    }

    int mid = left + (right - left) / 2;
    int count = 0;

    // Recursively sort and count inversions
    count += mergeSortAndCount(arr, left, mid);
    count += mergeSortAndCount(arr, mid + 1, right);
    count += mergeAndCount(arr, left, mid, right);

    return count;
}

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

    // Process each student's course choices and calculate inversion count
    for (int i = 0; i < courseChoices.size(); i++)
    {
        int inversionCount = mergeSortAndCount(courseChoices[i], 0,
                                               courseChoices[i].size() - 1);
        cout << "Student " << i + 1 << " inversion count: " << inversionCount
             << endl;
    }

    return 0;
}