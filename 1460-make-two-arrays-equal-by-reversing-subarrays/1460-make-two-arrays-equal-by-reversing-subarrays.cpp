class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> freq(1001, 0);
        for(int x : arr){
            freq[x]++;
        }
        for(int x : target){
            freq[x]--;
        }
        for(int i =0; i< freq.size();i++){
            if(freq[i] != 0){
                return  false;
            }
        }
        return true;
    }
};