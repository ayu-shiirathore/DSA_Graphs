class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            
            if (sum == target) {
                return {left + 1, right + 1};  // Convert to 1-based indexing
            } else if (sum < target) {
                left++;  // Move left pointer to the right
            } else {
                right--; // Move right pointer to the left
            }
        }
        
        return {};  // This line won't be reached as per problem guarantees
    }
};
