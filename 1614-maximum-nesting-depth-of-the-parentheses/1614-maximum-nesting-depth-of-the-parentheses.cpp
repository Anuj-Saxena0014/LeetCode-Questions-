class Solution {
public:
    int maxDepth(string s) {
        int d = 0;
        int maxd=0;
        for(int i = 0; i< s.size(); i++){
           char ch = s[i];
            if( ch == '('){
                d++;
                maxd = max(d, maxd);
            }
            if(ch == ')'){
                d--;
            }

        }
        return maxd;
    }
};