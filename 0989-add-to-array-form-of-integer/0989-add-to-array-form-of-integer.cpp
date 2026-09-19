class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size()-1;
        vector<int> v;
        while(n>= 0 || k>0){
            if(n>=0){
             k += num[n];
             n--;
            }
            v.push_back(k%10);
            k /=10;
        }
        reverse(v.begin(),v.end());
        return v;
    }
};