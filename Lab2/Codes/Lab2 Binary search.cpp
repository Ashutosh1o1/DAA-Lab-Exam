#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int x)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;
        // If x is greater, ignore the left half
        if (arr[mid] < x)
            left = mid + 1;
        // If x is smaller, ignore the right half
        else
            right = mid - 1;
    }
    // If the element is not present, return -1
    return -1;
}
int main()
{
    int n, x;
    // Get the size of the array from the user
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n]; // Declare the array with the user-defined size
    // Get the elements of the array from the user
    cout << "Enter the elements of the array in ascending order: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // Get the key to search for
    cout << "Enter the element to search for: ";
    cin >> x;
    // Perform the binary search
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        cout << "Element is not present in array" << endl;
    else
        cout << "Element is present at index " << result << endl;
    return 0;
}