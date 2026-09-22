class Solution {
public:
    int findComplement(int num) {
    int ans = 0;
    long long power = 1;

    while(num > 0){
        int bit = num % 2;
        
        if(bit == 0)
        ans += power;
        
        num /= 2;
        power *= 2;
    }

    return ans;
    }
};