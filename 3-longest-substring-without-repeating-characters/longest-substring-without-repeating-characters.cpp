class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0, right = 0, len = 0;
        string st = "";

        while (right < n) {
            char c = s[right];

            // If the character is already in the current substring
            // st.find(c) != std::string::npos this condition checks if 
            // the character is already present
            if (st.find(c) != std::string::npos) {
                // Remove characters from the left until we remove the duplicate
                while (st.find(c) != std::string::npos) {
                    st.erase(0, 1);  // Remove the first character
                    left++;
                }
            }

            st += c;
            len = max(len, right - left + 1);
            right++;
        }

        return len;
    }
};
