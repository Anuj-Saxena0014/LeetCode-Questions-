class Solution {
public: 
    bool kudja(int idx, vector<int>& nums,vector<int>& dp){
        if(idx >= nums.size()-1) return true;

        if(dp[idx] != -1){
            return dp[idx];
        }
        
        for(int jump =1 ; jump <= nums[idx];jump++){
            if(kudja(jump + idx,nums,dp)){
                return true;
            }
        }
       return dp[idx] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return kudja(0,nums,dp);
    }
};