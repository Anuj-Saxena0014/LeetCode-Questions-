class Solution {
public:
    bool checkRecord(string s) {
        int a =0;
        int l=0;
        for(char ch :s){
            if(ch == 'A'){
                a++;
                l=0;
            }
            else if(ch == 'L'){
                l++;

            if(l >= 3)
                return false;
            }
            else {
                l = 0; 
            }
        }  
        if( a >= 2){
            return false;
        }
        return true;
    }
};