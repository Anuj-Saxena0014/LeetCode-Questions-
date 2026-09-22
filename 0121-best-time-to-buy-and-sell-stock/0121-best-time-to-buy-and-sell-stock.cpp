class Solution {
public: 
    int kharid(int i,vector<int>& prices,int bestbuy,vector<int>& dp){
        int n = prices.size();
        if(i == n) return 0;
        if(dp[i] != -1)
            return dp[i];

       if(prices[i] < bestbuy){
            bestbuy = prices[i];
            return dp[i] = kharid(i + 1, prices, prices[i],dp);
        }
        int profit = (prices[i]- bestbuy);

        int future = kharid(i+1,prices,bestbuy,dp);
        return dp[i] =max(profit, future);

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>dp(n+1,-1);
        return kharid(1,prices,prices[0],dp);
    }
};