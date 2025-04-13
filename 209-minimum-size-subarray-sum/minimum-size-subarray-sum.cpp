class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n= nums.size();
        int len = INT_MAX;
        int left=0, sum=0;
        for(int right=0; right<n;right++){
            //expand the window to right 
            sum+=nums[right];
            //shrink the window from the left as long as sum is valid
            while(sum>=target){
                len = min(len,right-left+1);
                sum-=nums[left];
                left++;
            }
        }

        return (len==INT_MAX) ?0 :len;
    }
};