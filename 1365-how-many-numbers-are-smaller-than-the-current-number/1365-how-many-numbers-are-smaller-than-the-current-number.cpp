class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res;
        for(int i =0 ;i < nums.size(); i++){
        int c =0 ;
        int x = nums[i];
        for(int j =0; j< nums.size();j++){
            if(x > nums[j]){
                c++;
            }
        }
        res.push_back(c);
     }
     return res;
    }
};