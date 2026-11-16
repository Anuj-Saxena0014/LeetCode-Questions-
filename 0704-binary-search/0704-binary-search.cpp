class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l =0;
        int r=n-1;
        while( l <= r){
        int mid = l + (r-l)/2;
        if(target == nums[mid] ){
            return mid;
        }
        if( target < nums[mid]){
            r = mid-1;
        }
        if(target >nums[mid]){
            l = mid+1;
        }
        } 
        return -1;
    }
};