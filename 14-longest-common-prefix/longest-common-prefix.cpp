class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
        return "";

        int n = strs.size();

        string pref = strs[0];
        int len = pref.size();

        for(int i=1; i<n; i++){
            string s = strs[i];
            while(len>s.size() || pref != s.substr(0,len)){
                len--;
                if(len==0){
                    return "";
                }
                pref = pref.substr(0,len);
            }
        }

        return pref;
    }
};