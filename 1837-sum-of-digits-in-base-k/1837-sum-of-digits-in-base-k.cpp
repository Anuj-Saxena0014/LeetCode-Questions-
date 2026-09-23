class Solution {
public:
    int sumBase(int n, int k) {
        int s=0;
        while(n>0){
           int x = n%k;
           s += x;
           n /= k;
        }
        return s;
    }
};