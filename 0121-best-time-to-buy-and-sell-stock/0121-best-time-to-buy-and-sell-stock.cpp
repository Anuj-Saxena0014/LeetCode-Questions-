class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int max_profit=0;
        int buy =prices[0];
        for(int i=1;i<n;i++){
            int curr_profit= prices[i]-buy;
        
        if(curr_profit > max_profit){
            max_profit =curr_profit;
        }
        if(prices[i]< buy){
            buy = prices[i];
        }

        }
        return max_profit;
    }
};