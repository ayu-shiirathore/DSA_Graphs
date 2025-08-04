class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> elements;
        sort(candidates.begin(), candidates.end());
        helper(candidates, ans, elements, target, 0);
        return ans;
    }
    void helper(vector<int>& candidates, vector<vector<int>>& ans, vector<int> elements, int target, int index){
        if(target==0){
            ans.push_back(elements);
            return;
        }
        for(int i=index; i<candidates.size(); i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            elements.push_back(candidates[i]);
            helper(candidates, ans, elements, target-candidates[i], i+1);
            elements.pop_back();
        }
    }
};