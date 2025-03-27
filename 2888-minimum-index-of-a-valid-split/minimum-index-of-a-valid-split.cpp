class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq; // Use unordered_map to store the frequency of elements
    
        // Populate the frequency map
        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        // Find the element with the highest frequency
        int f = 0;
        int x = -1;
        for (auto& entry : freq) {
            if (entry.second > f) {
                f = entry.second;
                x = entry.first;
            }
        }

        int f1=0, f2=0;

        // let frequency of dominant element x in left subarray be f1 then
        // frequency of dominant element x in right subarray will be f2=f-f1
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == x) {
                f1++;
            }
            int leftSize = i + 1;
            int rightSize = n - leftSize;
            f2 = f - f1; // freq of x in right subarry:
            // check if dominant in both subarrays:
            if (f1 > (leftSize / 2) && f2 > (rightSize / 2)) {
                return i; // valid split index
            }
        }
        // else:
        return -1;      
    }
};