class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(char ch : s){
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                if(st.empty()){
                return false;
            }
            char x= st.top();
            if(x == '(' && ch == ')' || x == '{' && ch == '}' || x == '[' && ch == ']'){
                st.pop();
            }
            else{
                return false;
            }
            }
        }
        return st.empty();
    }
};