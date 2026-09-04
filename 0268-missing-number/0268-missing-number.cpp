class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int n = nums.size();
        int t=0;
        int sn;
        sn = n*(n+1)/2;
        for(int i =0; i<n; i++){
             t += nums[i];
            }
    return sn-t;  
    }
};