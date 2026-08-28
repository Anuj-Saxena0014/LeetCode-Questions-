class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int no = 1; 
        int i =0; 
        while(i< arr.size() && k> 0){
            if(arr[i] == no ){
                i++;
            }
            else{
                k--;
            }
            no++;
        }
        while(k--){
            no++;
        }
        return no -1;
    }
};