class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n= nums.size();
        int total_sum =0;
        int dup =0;
        unordered_map<int,int> mp;
        for(int x : nums){
            mp[x]++;
            if(mp[x] ==2){
                dup=x;
            }
        }
        total_sum = n*(n+1)/2;
        int cursum=0;
        for(int x: nums){
          cursum+= x;
        }
        return {dup,total_sum - cursum +dup };
    }
};