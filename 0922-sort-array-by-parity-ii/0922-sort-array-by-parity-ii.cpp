class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int evenidx =0;
        int oddidx =1;
        while( evenidx < n && oddidx < n){
            if(nums[evenidx] % 2 != 0  && nums[oddidx] %2 == 0 ){
                swap(nums[evenidx], nums[oddidx]);
                evenidx+= 2;
                oddidx += 2;
            }
             else{
                if(nums[evenidx] % 2 == 0)
                    evenidx += 2;
                if(nums[oddidx] % 2 != 0)
                    oddidx += 2;
            }
        }
        return nums;
    }
};