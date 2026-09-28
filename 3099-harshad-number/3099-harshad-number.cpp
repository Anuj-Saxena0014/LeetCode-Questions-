class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int dig = 0;
        int y =x;
      while(x>0){
        int rem = x%10;
        dig  += rem;
        x /= 10;
      } 
    return (y % dig == 0)? dig : -1;
     
    }
};