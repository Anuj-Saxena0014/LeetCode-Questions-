class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxpro = 0;
         int bestbuy=prices[0];
        for(int i =1 ;i<prices.size();i++){
          if(prices[i] > bestbuy){
            maxpro = max(maxpro,prices[i]-bestbuy);
          }
          bestbuy = min(bestbuy,prices[i]);
        }
       return maxpro;
    }
};