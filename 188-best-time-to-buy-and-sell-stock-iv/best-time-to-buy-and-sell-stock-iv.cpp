class Solution {
public:

    int f(int index, int Canbuy,int k,vector<vector<vector<int>>>&dp,vector<int>&prices){

        if(index==prices.size()) return 0;
        if(k==0) return 0;
        if(dp[index][Canbuy][k]!=-1) return dp[index][Canbuy][k];

        if(Canbuy){
            int buy= -prices[index]+f(index+1,0,k,dp,prices);
            int notbuy= 0+f(index+1,1,k,dp,prices);
            return dp[index][Canbuy][k]=max(buy,notbuy);
        }
        else{
            int sell= prices[index]+f(index+1,1,k-1,dp,prices);
            int notsell= 0+f(index+1,0,k,dp,prices);
            return dp[index][Canbuy][k]=max(sell,notsell);
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(0,1,k,dp,prices);
    }
};