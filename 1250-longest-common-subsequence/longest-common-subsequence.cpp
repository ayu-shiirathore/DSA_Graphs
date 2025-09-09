#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        
        // Create memoization table with -1 indicating not computed
        vector<vector<int>> memo(m, vector<int>(n, -1));
        
        return lcs(text1, text2, 0, 0, memo);
    }
    
private:
    int lcs(string& text1, string& text2, int i, int j, vector<vector<int>>& memo) {
        // Base case: if either string is empty
        if (i == text1.size() || j == text2.size()) {
            return 0;
        }
        
        // If already computed, return cached result
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        int result;
        // If characters match, include in LCS
        if (text1[i] == text2[j]) {
            result = 1 + lcs(text1, text2, i + 1, j + 1, memo);
        } else {
            // Skip character from text1 or text2
            result = max(lcs(text1, text2, i + 1, j, memo), lcs(text1, text2, i, j + 1, memo));
        }
        
        // Store result in memo table before returning
        memo[i][j] = result;
        return result;
    }
};