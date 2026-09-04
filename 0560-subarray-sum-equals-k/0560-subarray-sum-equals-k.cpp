class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        int cursum =0; 
        int c =0;
        m[0] =1;
        for(int x : nums){
           cursum += x;

           if(m.find(cursum -k ) != m.end()){
            c += m[cursum-k];
           }
           m[cursum]++; 
        }
        return c;
    }
};