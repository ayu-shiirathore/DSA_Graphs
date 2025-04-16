class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        long long res = 0, pairs= 0;
        unordered_map <int, int> mp;

        while(j<n){
            //is se pehle kiti baar nums[j] dekha h humne
            pairs += mp[nums[j]];
            mp[nums[j]]++;

            while(pairs>=k){
                res += n-j;
                mp[nums[i]]--;
                pairs -= mp[nums[i]];
                i++;
            }
            j++;
        }
        return res;
    }
};