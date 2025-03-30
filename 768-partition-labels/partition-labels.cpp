class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> lastIndex;
        // Store the last index of each character
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i]] = i;  
        }
        vector<int> ans;
        int start=0, end=0;
        for(int i=0;i<s.size();i++){
            end=max(end,lastIndex[s[i]]);

            if(i==end){
                //means partition is complete
                int size=i-start+1;
                ans.push_back(size);
                start=i+1;
            }
        }

        return ans;

    }
};