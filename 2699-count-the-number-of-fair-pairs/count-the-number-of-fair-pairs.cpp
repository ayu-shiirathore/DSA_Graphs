class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long count = 0;

        for (int i = 0; i < n; ++i) {
            //lower <= nums[i] + nums[j] <= upper
            //➝ lower - nums[i] <= nums[j] <= upper - nums[i]

            //So we calculate the bounds of nums[j] that would make the pair fair.
            int low = lower - nums[i];
            int high = upper - nums[i];

            //Finds the first index j > i where nums[j] >= low.
            //Returns an iterator pointing to the start of the valid range.
            auto left = lower_bound(nums.begin() + i + 1, nums.end(), low);
            //Finds the first index j > i where nums[j] > high
            auto right = upper_bound(nums.begin() + i + 1, nums.end(), high);

            count += (right - left);
        }

        return count;
    }
};