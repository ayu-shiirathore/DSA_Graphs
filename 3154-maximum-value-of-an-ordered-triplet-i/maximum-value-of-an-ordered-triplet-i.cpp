class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int maxPrefix = nums[0];
        int maxDiff = INT_MIN;
        
        for (int j = 1; j < nums.size() - 1; j++) {
            maxDiff = max(maxDiff, maxPrefix - nums[j]);
            maxPrefix = max(maxPrefix, nums[j]);  // Update maxPrefix for next iteration
            
            ans = max(ans, (long long)maxDiff * nums[j + 1]);
        }
        
        return ans;
    }
};
