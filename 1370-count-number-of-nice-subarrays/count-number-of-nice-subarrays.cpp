class Solution {
public:
    // Helper function to count subarrays with at most k odd numbers
    int atMostK(vector<int>& nums, int k) {
        int left = 0;
        int count = 0;
        int odd_count = 0;

        for (int right = 0; right < nums.size(); ++right) {
            // If the current number is odd, increment our odd count
            if (nums[right] % 2 != 0) {
                odd_count++;
            }

            // If the window is invalid (more than k odds), shrink it from the left
            while (odd_count > k) {
                if (nums[left] % 2 != 0) {
                    odd_count--;
                }
                left++;
            }

            // The window [left..right] is now valid.
            // Any subarray ending at `right` is also valid.
            // The number of such subarrays is (right - left + 1).
            count += (right - left + 1);
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        // The number of subarrays with exactly k odds is
        // (at most k odds) - (at most k-1 odds)
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};