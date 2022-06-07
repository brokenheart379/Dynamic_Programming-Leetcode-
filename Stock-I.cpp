Best Time to Buy and Sell Stock
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(prices.size()<=1)
            return 0;
        int minimal=prices[0];
        int profit=0;
        int maxprofit=INT_MIN;
        for(int i=1;i<prices.size();i++){
            minimal=min(minimal,prices[i]);
            profit=max(profit,prices[i]-minimal);
            maxprofit=max(maxprofit,profit);
        }
        return maxprofit;
    }
};




class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size()<=1)
            return 0;
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> dp(prices.size(),0);
        int minimal=prices[0];
        for(int i=1;i<prices.size();i++){
            minimal=min(minimal,prices[i]);
            dp[i]=max(dp[i-1],prices[i]-minimal);
        }
        return dp[prices.size()-1];
    }
};
