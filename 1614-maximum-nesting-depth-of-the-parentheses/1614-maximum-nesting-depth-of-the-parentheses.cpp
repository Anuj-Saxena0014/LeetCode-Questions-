class Solution {
public:
    int maxDepth(string s) {
        // int d=0;
        // int maxd= 0;
        // for(char ch : s){
        //     if(ch =='('){
        //         d++;
        //     }
        //     else{
        //         maxd= max(d,maxd);
        //         d--;
        //     }
        // }
        // return maxd;
        stack<int>st;
        int maxx=0;
        st.push(0);
        for(char ch : s){
            if(ch == '('){
                st.push(st.top()+1);
                maxx = max(maxx,st.top());
            }
            if(ch == ')'){
                st.pop();
            }
        }
        return maxx;
    }

};