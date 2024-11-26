#include <iostream> 
#include<cmath>
#include <fstream> 
#include <sstream> 
#include <vector> 
#include <string> 
 
using namespace std; 
 
// Function to perform brute force multiplication 
int bruteForceMultiply(int a, int b) { 
    return a * b; 
} 
 
// Function to perform divide-and-conquer multiplication (Karatsuba Algorithm) 
int multiplyDivideAndConquer(int x, int y) { 
    // Base case 
    if (x < 10 || y < 10) return x * y; 
 
    int n = max(to_string(x).length(), to_string(y).length()); 
    int half = n / 2; 
 
    // Split the digit sequences 
    int a = x / pow(10, half); 
    int b = x % static_cast<int>(pow(10, half)); 
    int c = y / pow(10, half); 
    int d = y % static_cast<int>(pow(10, half)); 
 
    // Recursively calculate 
    int ac = multiplyDivideAndConquer(a, c); 
    int bd = multiplyDivideAndConquer(b, d); 
    int ab_cd = multiplyDivideAndConquer(a + b, c + d); 
 
    // Return the result 
    return ac * pow(10, 2 * half) + (ab_cd - ac - bd) * pow(10, half) + bd; 
} 
 
// Function to read pairs of numbers from CSV 
vector<pair<int, int>> readNumbersFromCSV(const string& filename) { 
    ifstream file(filename); 
    vector<pair<int, int>> numberPairs; 
    string line, value; 
     
    // Skip the header 
    getline(file, line); 
     
    // Read each line (pairs of numbers) 
    while (getline(file, line)) { 
        stringstream ss(line); 
        string num1, num2; 
         
        getline(ss, num1, ','); 
        getline(ss, num2, ','); 
         
        numberPairs.push_back(make_pair(stoi(num1), stoi(num2))); 
    } 
     
    file.close(); 
    return numberPairs; 
} 
 
int main() { 
    // File containing pairs of numbers 
    string filename = "numbers_for_multiplication.csv"; 
     
    // Read the number pairs from the CSV file 
    vector<pair<int, int>> numberPairs = readNumbersFromCSV(filename); 
     
    // Perform multiplication using brute force and divide-and-conquer methods 
    for (int i = 0; i < numberPairs.size(); i++) { 
        int a = numberPairs[i].first; 
        int b = numberPairs[i].second; 
 
        // Brute-force multiplication 
        int bruteResult = bruteForceMultiply(a, b); 
 
        // Divide-and-conquer multiplication 
        int divAndConqResult = multiplyDivideAndConquer(a, b); 
 
        cout << "Pair " << i + 1 << ": " << a << " * " << b << endl; 
        cout << "Brute-force result: " << bruteResult << endl; 
        cout << "Divide-and-conquer result: " << divAndConqResult << endl; 
        cout << "---------------------------------" << endl; 
    } 
 
    return 0; 
} 