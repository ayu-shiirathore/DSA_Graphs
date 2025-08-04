class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> elements;
        helper(candidates, target, elements, ans, 0, 0);
        return ans;
    }

    void helper(vector<int>& candidates, int target, vector<int>& elements, vector<vector<int>>& ans, int index, int sum){
        if(sum==target){
            ans.push_back(elements);
            return;
        }
        if(index==candidates.size()) return;
 
        if(sum<target){
            elements.push_back(candidates[index]);
            helper(candidates,target,elements, ans,index,sum+candidates[index]);
            elements.pop_back();
        }
        helper(candidates,target,elements, ans,index+1,sum);
    }
};