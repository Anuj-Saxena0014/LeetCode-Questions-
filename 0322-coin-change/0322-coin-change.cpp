class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      if(amount < 0) return 0;
      vector<int> mincoindp(amount + 1, INT_MAX);
      mincoindp[0] = 0;
      for(int i=1;i<= amount;i++){
        for(int coin : coins){
            if (coin <= i && mincoindp[i - coin] != INT_MAX) {
         mincoindp[i] = min(mincoindp[i],1 + mincoindp[i - coin]);
        }
    }
    }
    if(mincoindp[amount] == INT_MAX){
        return -1;
    }
    return mincoindp[amount];
    }
};