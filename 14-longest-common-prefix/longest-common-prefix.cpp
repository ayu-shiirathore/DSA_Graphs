class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        if(v.empty()) return ""; // Handle empty input
        string prefix = v[0]; // Start with the first string as the initial prefix
        for(int i = 1; i < v.size(); i++) { // Compare with all other strings
            while(v[i].find(prefix) != 0) { // While the current string doesn't start with our prefix
                prefix = prefix.substr(0, prefix.length()-1); // Shrink the prefix from the end
                if(prefix.empty()) return ""; // If prefix becomes empty, return immediately
            }
        }
        return prefix;
    }
};