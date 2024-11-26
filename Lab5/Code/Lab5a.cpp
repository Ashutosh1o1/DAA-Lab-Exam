#include <iostream> 
#include <vector> 
#include <algorithm> 
 
using namespace std; 
 
// Function to calculate the maximum value for the fractional knapsack problem 
double fractionalKnapsack(vector<int>& weights, vector<int>& values, 
vector<int>& shelfLife, int capacity) { 
    // Vector to store items with (shelfLife/value, weight, value) 
    vector<pair<double, pair<int, int>>> items; 
    int n = weights.size(); 
 
    // Calculate shelfLife/value ratio and store it with corresponding weight  and value 
    for (int i = 0; i < n; i++) { 
        double ratio = static_cast<double>(shelfLife[i]) / values[i]; 
        items.push_back({ratio, {weights[i], values[i]}}); 
    } 
 
    // Sort items based on the shelfLife/value ratio in descending order 
    sort(items.begin(), items.end(), [](const auto& a, const auto& b) { 
        return a.first > b.first; 
    }); 
 
    double currentWeight = 0; 
    double currentValue = 0; 
 
    // Iterate over the sorted items 
    for (int i = 0; i < items.size(); i++) { 
        int w = items[i].second.first; 
        int v = items[i].second.second; 
 
        // If adding the whole item does not exceed capacity, add it 
        if (currentWeight + w <= capacity) { 
            currentWeight += w; 
            currentValue += v; 
        }  
        // Else add the fraction of the remaining capacity and break 
        else { 
            double remain = capacity - currentWeight; 
            currentValue += v * (remain / w); 
            break; 
        } 
    } 
 
    return currentValue; 
} 
 
int main() { 
    vector<int> weights; 
    vector<int> values; 
    vector<int> shelfLife; 
    weights = {10, 20, 30};    // Example weights 
    values = {60, 100, 120};   // Example values 
    shelfLife = {2, 3, 5};     // Example shelf lives 
    int capacity; 
    capacity = 50;                     // Example capacity 
    double maxValue = fractionalKnapsack(weights, values, shelfLife, 
capacity); 
    cout << "Maximum value in knapsack: " << maxValue << endl; 
 
    weights = {60, 80, 100};    // Example weights 
    values = {10, 20, 30};   // Example values 
    shelfLife = {5, 10, 3};     // Example shelf lives 
    capacity = 50;                     // Example capacity 
     maxValue = fractionalKnapsack(weights, values, shelfLife, capacity); 
    cout << "Maximum value in knapsack: " << maxValue << endl; 
 
    weights = {50, 90, 50};    // Example weights 
    values = {5, 20, 15};   // Example values 
    shelfLife = {1, 2, 4};     // Example shelf lives 
    capacity = 50;                     // Example capacity 
     maxValue = fractionalKnapsack(weights, values, shelfLife, capacity); 
    cout << "Maximum value in knapsack: " << maxValue << endl; 
 
    return 0; 
}