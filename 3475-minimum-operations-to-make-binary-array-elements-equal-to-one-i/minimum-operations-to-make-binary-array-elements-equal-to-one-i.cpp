class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        // Only process if the array has at least 3 elements
        if (n < 3) return -1;
        
        // Traverse the array to flip bits
        for (int i = 0; i < n - 2; i++) {
            // If the current bit is 0, flip the next three bits
            if (nums[i] == 0) {
                for (int j = 0; j < 3; j++) {
                    nums[i + j] = !nums[i + j]; // Flip each of the next 3 bits
                }
                count++; // Increment the number of operations
            }
        }
        
        // After flipping, check if there is any '0' left
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) return -1; // If any bit is still 0, return -1
        }
        
        return count; // Return the number of operations
    }
};
