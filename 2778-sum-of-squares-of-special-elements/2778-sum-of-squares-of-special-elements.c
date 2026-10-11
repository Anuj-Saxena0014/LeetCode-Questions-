int sumOfSquares(int* nums, int n) {
 int num =0;
 for(int i =1;i<=n;i++){
    if(n % i == 0){
        num += nums[i-1]*nums[i-1];
    }
 } 
 return num;  
}