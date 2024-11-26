#include <iostream>
#include <vector>
using namespace std;
int LinearSearch(vector<int> &numbers, int key)
{
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (numbers[i] == key)
        {
            return i; // key found at index i.
        }
    }
    return -1; // key not found.
}

int main()
{
    int n, key;
    // Get the size of the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    // Create a vector and get the elements from the user
    vector<int> numbers(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> numbers[i];
    }
    // Get the key to search for
    cout << "Enter the number to search: ";
    cin >> key;
    // Perform Linear Search and output the result
    int result = LinearSearch(numbers, key);
    cout << (result != -1 ? "Number found at index: " + to_string(result) : "Number not found") << endl;
    return 0;
}