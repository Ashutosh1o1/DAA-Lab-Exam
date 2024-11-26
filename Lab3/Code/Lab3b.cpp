#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

void merge(vector<double> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back
    // into arr[left..right]
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(vector<double> &arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main()
{
    ifstream inputFile("input5.csv");   // Input CSV file
    ofstream outputFile("output5.csv"); // Output CSV file
    vector<double> v;
    if (!inputFile.is_open() || !outputFile.is_open())
    {
        cout << "Error opening file!" << endl;
    }

    string line;
    // Write the header for the output file
    outputFile << "Name,Salary,Tax,Home Rent,Bonus\n";

    // Skip the header line in the input file
    getline(inputFile, line);

    // Process each line
    while (getline(inputFile, line))
    {
        stringstream ss(line);
        string name, salaryStr;
        getline(ss, name, ',');
        getline(ss, salaryStr, ',');

        double salary = stod(salaryStr);
        v.push_back(salary);
        double tax = 0.30 * salary;
        double homeRent = 0.12 * salary;
        double bonus = 0.15 * salary;

        // Write the results to the output file
        outputFile << name << "," << salary << "," << tax << "," << homeRent << "," << bonus << "\n";
    }

    inputFile.close();
    outputFile.close();

    cout << "Calculations completed and output saved to 'output_finances.csv'." << endl; 
     mergeSort(v, 0, 2000);
    if (v[1] < 0)
    {
        cout << "Salary can't be negative";
    }
    else if (v.empty())
    {
        cout << "No Data Present";
    }
    else
    {
        cout << "Min Salary -> " << v[1] << endl;
        cout << "Max Salary -> " << v[v.size() - 1];
    }
    return 0;
}