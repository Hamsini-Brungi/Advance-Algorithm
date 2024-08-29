#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>  
using namespace std;

pair<int, int> findTwoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> num_map;
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        
        if (num_map.find(complement) != num_map.end()) {
            return {num_map[complement], i};
        }
        
        num_map[nums[i]] = i;
    }

    return {-1, -1}; 
}

int main() {
    vector<int> numbers;
    int target;
    
    cout << "Enter numbers followed by \"N\" to stop: ";
    while (true) {
        int num;
        if (!(cin >> num)) break;
        numbers.push_back(num);
    }
    
    cout << "Enter target: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> target;
    
    auto result = findTwoSum(numbers, target);
    
    if (result.first != -1) {
        cout << "{" << result.first << ", " << result.second << "}" << endl;
    } else {
        cout << "no result" << endl;
    }

    return 0;
}
