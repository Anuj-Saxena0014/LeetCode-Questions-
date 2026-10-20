class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        int i =0;
        int st=0;
        while(i <n ){
            int curr =nums[i];
            int j=i;
            while(j<n && nums[j] == curr){
                j++;
            }
            int allow= min(j-i,2);
            for(int x =0;x<allow;x++){
                nums[st++] = curr;
            }
            i=j;
        }
        return st;
    }
};