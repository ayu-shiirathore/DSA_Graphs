class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int subsequence = 1;
        int min_val = nums[0];

        for(int i=1; i<n; i++){
            if(nums[i]-min_val > k){
                min_val = nums[i];
                subsequence++;
            }
        }

        return subsequence;
    }
};