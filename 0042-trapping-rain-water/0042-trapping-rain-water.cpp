class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l =0; 
        int r =n-1;
        int lmax =0; 
        int rmax =0; 
        int area =0; 
        while(l<= r){
          lmax = max(height[l], lmax);
          rmax = max(height[r],rmax);
          if(lmax < rmax){
          area += lmax-height[l];
          l++;
          }
          else{
            area += rmax-height[r];
            r--;
          }
          
        }
   return area; }
};