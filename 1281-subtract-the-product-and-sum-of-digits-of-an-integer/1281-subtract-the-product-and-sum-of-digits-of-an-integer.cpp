class Solution {
public:
    int subtractProductAndSum(int n) {
        int pro = 1;
        int sum =0; 
        
        while (n>0){
            int d = n%10;
            sum += d;
            pro *= d;
            n = n/10;      

        }
        return pro -sum;
        
    }
};