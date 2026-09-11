class Solution {
public:
    // bool fun(int i,int n,vector<int>&nums){
    //     if(i==n-1) return true;
    //     if(nums[i]==0) return false;
    //     // if(dp[i]!=0) return true;
    //     for(int j=nums[i];j>=1;j--){
    //         if(i+j>n-1) continue;
    //         if(fun(i+j,n,nums)) return true;
    //     }
    //     return false;
    // }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=true;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j] and j+nums[j]>=i){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n-1];
    }
};