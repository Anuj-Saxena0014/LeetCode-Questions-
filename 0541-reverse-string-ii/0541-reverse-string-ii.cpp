class Solution {
public:
    string reverseStr(string s, int k) {
        // int n = s.length();
        // string str = s.substr(0,k);
        // reverse(str.begin(),str.end());
        // string ans = str + s.substr(k,n);
        // return ans;
       
        // reverse(s.begin(),s.begin()+k);
        // return  s;
        int n =s.length();

        for(int i=0;i<n;i+= 2*k){
          reverse(s.begin()+i,s.begin()+min(i+k,n)); 
        }
        return s;
    }
};