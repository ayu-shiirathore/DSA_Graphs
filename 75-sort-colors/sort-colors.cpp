class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, current = 0, high = n-1;

        while(current<=high){
            if(nums[current]==0){
                swap(nums[current],nums[low]);
                current++;
                low++;
            }
            else if(nums[current]==2){
                swap(nums[current], nums[high]);
                high--;
            }
            else
            current++;
        }
    }
};