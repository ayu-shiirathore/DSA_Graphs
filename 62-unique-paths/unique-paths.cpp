class Solution {
public:
    int count ;
    int backtrack(int m , int n , int i , int j , vector<vector<int>> &dp ){

        if(i>m-1 || j >n-1){
            return  0 ; 
        }
        if(i==m-1 && j==n-1){
            return 1 ;
        }
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = backtrack(m,n,i,j+1,dp)+ backtrack(m,n,i+1,j,dp);
    }


    int uniquePaths(int m, int n) {
        count = 0 ;
        vector<vector<int>> dp(m , vector<int>(n,-1));
        return backtrack(m,n,0,0,dp);
        // return count;
    }
};