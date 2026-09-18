class Solution {
public:

int moneyloot(int idx ,vector<int>& nums,vector<int>& dp ){
     if(idx>=nums.size()) return 0;
    if(dp[idx]!=-1) return dp[idx];
    int take = nums[idx] + moneyloot(idx+2 , nums,dp);
    int skip = moneyloot(idx+1,nums,dp);
    return dp[idx]=max(take,skip);

}

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n+1,-1);
        return moneyloot(0,nums,dp);
    }
};