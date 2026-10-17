class Solution {
public:
    int getdigitsum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n= nums.size();
        vector<int> asorted(nums);
        auto lambda = [&](int num1,int num2){
            int num1dsum = getdigitsum(num1);
            int num2dsum = getdigitsum(num2);
            if(num1dsum != num2dsum){
                return num1dsum < num2dsum; 
            }
            return num1 < num2;
        };
        sort(asorted.begin(),asorted.end(),lambda);

        unordered_map<int ,int> valtoidx;
        for(int i =0;i<n;i++){
            valtoidx[nums[i]] = i;
        }
        int count=0;

        for(int i =0;i<n;i++){
        int expectval = asorted[i];
        int currval  = nums[i];
        
        if(expectval == currval) continue;
        
        int idx = valtoidx[expectval];

        nums[i] = expectval;
        nums[idx] = currval;

        valtoidx[expectval] =i;
        valtoidx[currval] = idx;
        count++;
        }
        return count;
    }
};