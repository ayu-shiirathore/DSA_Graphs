class Solution {
public:
    bool isAnagram(string s, string t) {
        // If lengths are different, they can't be anagrams
        if (s.length() != t.length()) {
            return false;
        }
        
        // Create frequency arrays for both strings
        int freq[26] = {0};
        
        // Count frequencies for string s
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        // Subtract frequencies for string t
        for (char c : t) {
            freq[c - 'a']--;
        }
        
        // Check if all frequencies are zero
        for (int count : freq) {
            if (count != 0) {
                return false;
            }
        }
        
        return true;
    }
};