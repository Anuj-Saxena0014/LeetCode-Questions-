class Solution {
public:
    int n;
    unordered_set<string> st;
    int maxlen;
    
    void solve(string &s,int i ,string &curr,int c){
        if(c <0) return ;
        if(i == n){
            if( c == 0){
                if(curr.length() > maxlen){
                    maxlen = curr.length();
                    st.clear();
                }
                if( curr.length() == maxlen){
                    st.insert(curr);
                }
            }
            return ;
        }
        if( s[i] != '(' && s[i] != ')'){
            curr.push_back(s[i]);
            solve(s,i+1,curr,c);
            curr.pop_back();
            return ;
        }
        curr.push_back(s[i]);
        solve(s,i+1,curr,c + (s[i] == '(' ? 1 :-1));
        curr.pop_back();
        solve(s,i+1,curr,c);
    }

    vector<string> removeInvalidParentheses(string s) {
        n = s.size();
        st.clear();
        maxlen=0;
        string curr = "";
        solve(s,0,curr,0);
       return vector<string>(st.begin(), st.end());

    }
};