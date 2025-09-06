class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> ds;
        vector<vector<string>> ans;
        helper(0, s, ds, ans);
        return ans;
    }

    void helper(int index, string s, vector<string>& ds, vector<vector<string>>& ans){

        if(index == s.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=index; i<s.size(); i++){
            if(isPallindrome(s,index,i)){
                ds.push_back(s.substr(index, i-index+1));
                helper(i+1, s, ds, ans);
                ds.pop_back();
            }
            
        }
    }

    bool isPallindrome(string s,int left, int right){
        while(left<=right){
            if(s[left]!=s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};