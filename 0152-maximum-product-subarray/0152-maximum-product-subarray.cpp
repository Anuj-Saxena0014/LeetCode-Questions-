class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int n= nums.size();
       int ans = INT_MIN;
       int l =1;
       int r =1;
       for(int i =0;i<nums.size();i++){
        if(l == 0){
            l =1;
        }
        if(r == 0){
            r=1;
        }
        l *= nums[i];
        r *= nums[n-1-i];
        ans = max(ans,max(l,r));
       }
       return ans;
    }
};