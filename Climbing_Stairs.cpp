https://leetcode.com/problems/climbing-stairs/

//Botton-Up Approach
class Solution {
public:
    int climbStairs(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> dp(n+1,0);
        dp[0]=1,dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};


//Top-Down Appraoch
class Solution {
public:
    int fun(int n,vector<int> &dp){
        if(n==0 or n==1)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        dp[n]=fun(n-1,dp)+fun(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return fun(n,dp);
    }
};
