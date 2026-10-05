class Solution {
public:
    int scoreOfParentheses(string s) {
        int n =s.size();
        vector<int> v;
        int c=0;
        for(int i =0;i<n;i++){
          if(s[i] == '('){
            v.push_back(c);
            c =0;
          }
          else{
           if(s[i-1] == '('){
            c = v.back() +1;
           } 
           else{
            c = v.back()+ (2*c);
           }
           v.pop_back();
          }
        }
        return c;
    }
};