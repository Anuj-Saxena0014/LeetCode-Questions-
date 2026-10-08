class Solution {
public:
    string removeOuterParentheses(string s) {
        string res="";
        int c=0;
        for(char ch : s){
            if(ch == '('){
                if(c > 0){
                    res += ch;
                }
                c++;
            }
                else{
                    c--;
                if(c > 0){
                    res += ch;
                    }
                }
            }
        return res;
    }
};