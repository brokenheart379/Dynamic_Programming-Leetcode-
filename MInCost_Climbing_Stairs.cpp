https://leetcode.com/problems/min-cost-climbing-stairs/


Top-Down Approach
class Solution {
public:
    int helper(vector<int> &cost,vector<int> &dp,int i){
        if(i>=cost.size())
            return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i]=min(helper(cost,dp,i+1),helper(cost,dp,i+2))+cost[i];
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        return min(helper(cost,dp,0),helper(cost,dp,1));
    }
};


Bottom-Up Approach
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> dp(cost.size(),0);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<cost.size();i++){
            dp[i]=min(dp[i-1],dp[i-2])+cost[i];
        }
        return min(dp[cost.size()-1],dp[cost.size()-2]);
    }
};
