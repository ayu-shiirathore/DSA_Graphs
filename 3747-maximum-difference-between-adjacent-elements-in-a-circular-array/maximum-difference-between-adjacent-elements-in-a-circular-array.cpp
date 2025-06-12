class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int diff = 0;
        for(int i=1; i<= nums.size()-1; i++){
            diff = max(diff,abs(nums[i]-nums[i-1]));
        }
        int d = abs(nums[0]-nums[nums.size()-1]);
        diff = max(diff,d);
        
        return diff;

    }
};