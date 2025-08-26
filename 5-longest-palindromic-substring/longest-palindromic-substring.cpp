class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";  // Handle empty string case
    
        int start = 0;  // Start index of longest palindrome
        int end = 0;    // End index of longest palindrome
    
        for (int i = 0; i < s.length(); i++) {
            // Check both types of palindromes centered at position i
            int odd = expandAroundCenter(s, i, i);      // Odd-length: "aba"
            int even = expandAroundCenter(s, i, i + 1); // Even-length: "abba"
        
            int max_len = max(odd, even);  // Get the longer palindrome at this center
        
            // Update start and end indices if we found a longer palindrome
            if (max_len > end - start) {
                start = i - (max_len - 1) / 2;
                end = i + max_len / 2;
            }
        }
    
        return s.substr(start, end - start + 1);
    }

    int expandAroundCenter(string s, int left, int right) {
        // Expand outwards while characters match and within bounds
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return length of palindrome (right - left - 1)
        return right - left - 1;
    }   
};