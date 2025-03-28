class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;  // Pointer for string s
        int j = 0;  // Pointer for string t
    
        // Traverse both strings
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;  // Move pointer for s if characters match
            }
            j++;  // Always move pointer for t
        }
    
        // If we have matched all characters of s, return true
        return i == s.size();
    }
};