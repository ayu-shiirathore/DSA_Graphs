class Solution {
public:
    double myPow(double x, int n) {
        long long N=n;
        if(n<0) N= -1*N;
        double ans=1;
        while(N){
            if(N%2){
                ans = ans * x;
                N--;
            }
            else{
                x = x*x;
                N = N/2;
            }
        }
        if (n<0) return (1/ans);
        return ans;
    }
};