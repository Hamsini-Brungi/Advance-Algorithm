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
    int num;  
    
    cout << "Enter numbers followed by \"N\" to stop: ";
    while (cin >> num) {
        numbers.push_back(num);
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << "Enter target: ";
    cin >> target;
    
    auto result = findTwoSum(numbers, target);
    
    if (result.first != -1) {
        cout << "{" << result.first << ", " << result.second << "}" << endl;
    } else {
        cout << "no result" << endl;
    }

    return 0;
}
