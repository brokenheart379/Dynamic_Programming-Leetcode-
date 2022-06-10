https://leetcode.com/problems/house-robber/

//Bottom-Up Approach
class Solution {
public:
    int rob(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> dp(nums.size());
        int max_profit=0;
        if(nums.size()==0)
            return 0;
        else if(nums.size()==1)
            return nums[0];
        else if(nums.size()==2)
            return max(nums[0],nums[1]);
        else
        {
            dp[0]=nums[0];dp[1]=nums[1];
            dp[2]=dp[0]+nums[2];
            max_profit=max(dp[1],dp[2]);
            for(int i=3;i<nums.size();i++){
                dp[i]=max(dp[i-2],dp[i-3])+nums[i];
                max_profit=max(max_profit,dp[i]);
            }
        }
        return max_profit;
    }
};


//Top-Down Approach

class Solution {
public:
    int rob_helper(vector<int> nums,vector<int> &dp,int i){
        if(i>=nums.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        return dp[i]=max(nums[i]+rob_helper(nums,dp,i+2),rob_helper(nums,dp,i+1));
        
    }
    
    int rob(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> dp(nums.size(),-1);
        return rob_helper(nums,dp,0);
    }

};
