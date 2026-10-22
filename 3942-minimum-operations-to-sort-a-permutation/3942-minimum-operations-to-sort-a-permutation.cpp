class Solution {
public:
    int minOperations(vector<int>& nums) {
       int n = nums.size();
       int asc = 0;
       int dsc =0;

       for(int i=1;i<n;i++){
        asc += (nums[i] == (nums[i-1]+1 )%n);
        dsc += (nums[i-1] == (nums[i]+1)%n);
       } 
    
    if(asc == n-1 && nums[0] == 0){
        return 0;
    }
    if(asc == n-1){
        int lrot=n-nums[0];
        int rrot= 1+ (nums.back()+1) +1;
        return min(lrot,rrot);
    }
   if(dsc == n-1){
    int lrot = n-nums.back()+1;
    int rrot = (nums[0]+1)%n+1;

    return min(lrot,rrot);
    }
    return -1;
    }
};