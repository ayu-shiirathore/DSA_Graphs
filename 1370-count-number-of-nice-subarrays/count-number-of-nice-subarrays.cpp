class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // Map to store frequencies of prefix odd counts
        unordered_map<int, int> prefix_counts;
        // A prefix with 0 odds has been seen once (the empty prefix)
        prefix_counts[0] = 1;

        int total_subarrays = 0;
        int current_odd_count = 0;

        for (int num : nums) {
            // Increment current odd count if the number is odd
            if (num % 2 != 0) {
                current_odd_count++;
            }

            // We are looking for a previous prefix that has `current_odd_count - k` odds.
            int target = current_odd_count - k;

            // If we've seen such a prefix before, add its frequency to our total.
            // Each time we've seen it represents a valid starting point for a subarray.
            if (prefix_counts.count(target)) {
                total_subarrays += prefix_counts[target];
            }

            // Increment the frequency of the current prefix odd count for future lookups.
            prefix_counts[current_odd_count]++;
        }

        return total_subarrays;
    }
};